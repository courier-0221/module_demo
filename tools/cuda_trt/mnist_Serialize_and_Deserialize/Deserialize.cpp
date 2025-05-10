#include <iostream> 
#include <string>
#include <fstream>
#include <cassert>
#include <chrono> 
#include <vector>
#include <cmath>
#include <iomanip>
#include "NvInfer.h"

using namespace nvinfer1;

static const int inputH = 28;
static const int inputW = 28;
static const int output_size = 1 * 10;

const std::string IMAGE_PATH = "/opt/TensorRT-8.6.1.6/data/mnist/1.pgm";

inline void readPGMFile(const std::string& fileName, uint8_t* buffer, int inH, int inW)
{
    std::ifstream infile(fileName, std::ifstream::binary);
    assert(infile.is_open() && "Attempting to read from a file that is not open.");
    std::string magic, w, h, max;
    infile >> magic >> w >> h >> max;
    infile.seekg(1, infile.cur);
    infile.read(reinterpret_cast<char*>(buffer), inH * inW);
}

void verifyOutput(float* output)
{
    float val{0.0F};
    int idx{0};

    // Calculate Softmax
    float sum{0.0F};
    for (int i = 0; i < output_size; i++)
    {
        output[i] = exp(output[i]);
        sum += output[i];
    }

    std::cout << "Output:" << std::endl;
    for (int i = 0; i < output_size; i++)
    {
        output[i] /= sum;
        val = std::max(val, output[i]);
        if (val == output[i])
        {
            idx = i;
        }

        std::cout << " Prob " << i << "  " << std::fixed << std::setw(5) << std::setprecision(4) << output[i]
                         << " "
                         << "Class " << i << ": " << std::string(int(std::floor(output[i] * 10 + 0.5F)), '*')
                         << std::endl;
    }
    std::cout << std::endl;
}

// 继承 ILogger 类型创建自己的Logger
class Logger : public nvinfer1::ILogger{
	virtual void log(Severity severity, const char* msg) noexcept override{
		if (severity != Severity::kINFO)
			std::cout << msg << std::endl;
	}
};
static Logger gLogger;

class Deserialize_Demo{
public:
    Deserialize_Demo(std::string engine_path, float* input_data, float* output_data, int input_size);
    void deserialize_and_infer();
private:
    void runInference(IExecutionContext &context, float *input, float *output);
private:
    std::string engine_path;
    float *input;
    float *output;
    int input_size;
    int output_size;
};

Deserialize_Demo::Deserialize_Demo(std::string engine_path, float* input_data, float* output_data, int input_size){
    this->engine_path = engine_path;
    this->input = input_data;
    this->output = output_data;
    this->input_size = input_size;
    this->output_size = input_size;
}

void Deserialize_Demo::deserialize_and_infer(){
    // 准备将模型写入 stream 中
    char *trtModelStream{nullptr};
    std::ifstream file(this->engine_path, std::ios::binary);
    size_t engine_size{0}; // 初始化size大小
    if(file.good()){
        file.seekg(0, file.end); // 从file.end开始，偏移0
        engine_size = file.tellg(); // 获取当前位置，由于上一步处于file.end，因此可以获取file的字节大小
        file.seekg(0, file.beg); // 从file.beg开始，偏移0
        trtModelStream = new char[engine_size];
        assert(trtModelStream);
        file.read(trtModelStream, engine_size); // 读取size个size_t大小存放到创建的trtModelStream中
        file.close();
    }

    IRuntime *runtime = createInferRuntime(gLogger); // 创建runtime
    assert(runtime != nullptr);

    ICudaEngine *engine = runtime->deserializeCudaEngine(trtModelStream, engine_size, nullptr); // 反序列化加载engine
    assert(engine != nullptr);

    IExecutionContext *context = engine->createExecutionContext(); // 创建context
    assert(context != nullptr);

    std::cout << "allInputDimensionsSpecified: " << context->allInputDimensionsSpecified() << std::endl; 
    Dims dims = context->getBindingDimensions(0);
    std::cout << "dims.nbDims: " << dims.nbDims << std::endl; 
    std::cout << "dims.d[0..3]: " << dims.d[0] << " " << dims.d[1] << " " << dims.d[2] << " " << dims.d[3] << std::endl;
    // context->setBindingDimensions(0, Dims2(3, 1)); // 这步非常重要，要为动态维度设置具体的数值，否则输出结果会是全零，目前看不设置也能跑，使用解析时输入指定的tensor
    
    auto start = std::chrono::system_clock::now(); // 记录推理时长
    runInference(*context, this->input, this->output); // 执行推理
    auto end = std::chrono::system_clock::now(); // 打印推理时间
    std::cout << "\n[INFO]: Time taken by execution: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
              << "ms" << std::endl;

    context->destroy();
    engine->destroy();
    runtime->destroy();
}

void Deserialize_Demo::runInference(IExecutionContext &context, float *input, float *output){
    const ICudaEngine &engine = context.getEngine(); // 从context中获取engine
    assert(engine.getNbBindings() == 2); // 输入和输出两个bindings
    void *buffers[2];
    std::cout << "getNbBindings: " << engine.getNbBindings() << std::endl;

    // 通过name来获取输入和输出binding的索引
    const int inputIndex = engine.getBindingIndex("Input3"); // input对应输入节点的名称，参考最初的onnx模型可视化结果
    const int outputIndex = engine.getBindingIndex("Plus214_Output_0"); // output对应输出节点的名称

    // 在GPU中为输入和输出申请内存
    cudaMalloc(&buffers[inputIndex], this->input_size * sizeof(float));
    cudaMalloc(&buffers[outputIndex],  this->output_size * sizeof(float));

    // 创建cudastream
    cudaStream_t stream;
    cudaStreamCreate(&stream);

    // 从 cpu 中拷贝输入到 gpu
    cudaMemcpyAsync(buffers[inputIndex], input, this->input_size * sizeof(float), cudaMemcpyHostToDevice, stream);
    // enqueue支持隐式batchsize, enqueueV2支持显式batchsize
    // https://docs.nvidia.com/deeplearning/tensorrt/api/c_api/classnvinfer1_1_1_i_execution_context.html#a63cd95430852038ce864e17c670e0b36
    context.enqueueV2(buffers, stream, nullptr); // 执行推理

    // 将推理结果从 gpu 拷贝回 cpu 中
    cudaMemcpyAsync(output, buffers[outputIndex], this->output_size * sizeof(float), cudaMemcpyDeviceToHost, stream);

    cudaStreamSynchronize(stream); // 同步流，确保所有操作完成
    
    // 释放内存
    cudaStreamDestroy(stream);
    cudaFree(buffers[inputIndex]);
    cudaFree(buffers[outputIndex]);
}

int main(int argc, char* argv[]){
    // 序列化好的engine路径
    std::string engine_path = "./mnist.engine"; 
    
    // 初始化输入缓冲区
    std::vector<uint8_t> fileData(inputH * inputW);
    readPGMFile(IMAGE_PATH, fileData.data(), inputH, inputW);
    std::cout << "PGM:" << std::endl;
    for (int i = 0; i < inputH * inputW; i++)
    {
        std::cout << (" .:-=+*#%@"[fileData[i] / 26]) << (((i + 1) % inputW) ? "" : "\n");
    }
    std::cout << std::endl;
    float hostDataBuffer[inputH * inputW] = {0.0};
    for (int i = 0; i < inputH * inputW; i++)
    {
        hostDataBuffer[i] = 1.0 - float(fileData[i] / 255.0);
    }

    // 初始化输出缓冲区
    static float output_data[output_size];

    // 实例化对象
    Deserialize_Demo deserialize_demo(engine_path, hostDataBuffer, output_data, inputH * inputW);

    // 序列化并推理
    deserialize_demo.deserialize_and_infer();

    // 打印推理数据，验证结果
    // for(int i = 0; i < output_size; i++){ 
    //     std::cout << output_data[i] << std::endl; 
    // }
    verifyOutput(output_data);
    

    std::cout << "demo test successfully!" << std::endl;
    return 0;
}