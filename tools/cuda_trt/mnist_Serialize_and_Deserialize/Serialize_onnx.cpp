#include <iostream>
#include <fstream> 
#include <string>
#include "NvInfer.h"
#include "NvOnnxParser.h"    

using namespace nvinfer1;

// 继承 ILogger 类型创建自己的Logger
class Logger : public nvinfer1::ILogger{
	virtual void log(Severity severity, const char* msg) noexcept override{
		if (severity != Severity::kINFO)
			std::cout << msg << std::endl;
	}
};

class serialize_onnx{
public:
    serialize_onnx(std::string onnx_path, std::string engine_path){
        this->onnx_path = onnx_path;
        this->engine_path = engine_path;
    }
    std::ofstream onnx2engine();

private:
    std::string onnx_path;
    std::string engine_path;
    Logger gLogger;
};

std::ofstream serialize_onnx::onnx2engine(){

    // build
    nvinfer1::IBuilder* builder = nvinfer1::createInferBuilder(gLogger);

    // 利用builder创建network（空的network，后面需要不断添加算子）
    // 1U << static_cast<uint32_t>(NetworkDefinitionCreationFlag::kEXPLICIT_BATCH) 表示使用显式batchsize
    // 传递 0 时，例如builder->createNetworkV2(0U)表示使用隐式batchsize，隐式batchsize
    // 显式batchsize和隐式batchsize参考：https://zhuanlan.zhihu.com/p/547973146
    nvinfer1::INetworkDefinition* network = builder->createNetworkV2(1U << static_cast<uint32_t>(nvinfer1::NetworkDefinitionCreationFlag::kEXPLICIT_BATCH));

    // onnx模型解析器
    auto parser = nvonnxparser::createParser(*network, gLogger);
    bool parser_state = parser->parseFromFile(onnx_path.c_str(), 2); // 解析模型，在创建解析器的时候传入了network，因此在解析过程中会自动填充network
    if (parser_state == false){
        std::cerr << "parser onnx model failed!" << std::endl;
        exit(1);
    }

    // config
    nvinfer1::IBuilderConfig* config = builder->createBuilderConfig();
    config->setMaxWorkspaceSize(16 * (1 << 20)); // 设置最大工作空间
    config->setFlag(nvinfer1::BuilderFlag::kGPU_FALLBACK); // 启用GPU回退模式
    config->setFlag(nvinfer1::BuilderFlag::kFP16); // 设置精度计算

	// nvinfer1::IOptimizationProfile* profile = builder->createOptimizationProfile(); // 创建优化配置文件
    // profile->setDimensions("input", nvinfer1::OptProfileSelector::kMIN, nvinfer1::Dims2(1, 1)); // 设置输入input的动态维度，最小值
	// profile->setDimensions("input", nvinfer1::OptProfileSelector::kOPT, nvinfer1::Dims2(3, 1)); // 期望输入的最优值
	// profile->setDimensions("input", nvinfer1::OptProfileSelector::kMAX, nvinfer1::Dims2(5, 1)); // 最大值
	// config->addOptimizationProfile(profile); // 将优化配置加入到config

    // engine  trt version < 8
    // nvinfer1::ICudaEngine* engine = builder->buildEngineWithConfig(*network, *config);
    // nvinfer1::IHostMemory* modelStream = engine->serialize(); // 序列化创建的engine
    // engine->destroy();

    // engine trt version = 8.6
    nvinfer1::IHostMemory* modelStream = builder->buildSerializedNetwork(*network, *config);

    // 保存engine
    std::ofstream p(this->engine_path, std::ios::binary);
    if(!p){
        std::cerr << "could not open plan output file" << std::endl;
        exit(1);
    }
    p.write(reinterpret_cast<const char*>(modelStream->data()), modelStream->size()); // 保存

	modelStream->destroy();
	network->destroy();
	parser->destroy();

    return p;
}

int main(int argc, char* argv[]){
    std::string onnx_path = "/opt/TensorRT-8.6.1.6/data/mnist/mnist.onnx";
    std::string engine_path = "./mnist.engine";
    serialize_onnx serialize_demo(onnx_path, engine_path);
    serialize_demo.onnx2engine();
    std::cout << "serialize sucessfully!" << std::endl;
    return 0;
}