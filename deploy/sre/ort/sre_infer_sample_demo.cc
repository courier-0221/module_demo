#include <onnxruntime_cxx_api.h>
#include <iostream>
#include <vector>

int main() {
    // 初始化 ONNX Runtime 环境
    Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "SpeakerRecognition");
    Ort::SessionOptions session_options;

    // 设置 ONNX Runtime 配置选项
    session_options.SetIntraOpNumThreads(1); // 使用单线程
    session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);

    //profiling机制
    session_options.EnableProfiling("./onnxruntime_profile.json");

    // 模型路径
    const char *model_path = "/home/dear/code/VoiceprintRecognition-Pytorch/models/Res2Net_pt_onnx/inference.onnx";

    try {
        // 加载模型
        Ort::Session session(env, model_path, session_options);

        const char* input_names[] = {"feature"};
        const char* output_names[] = {"embedding"};

        // 创建输入数据
        size_t batch_size = 1;
        size_t frame_num = 100; // 假设帧数为 100
        size_t feature_dim = 80;

        std::vector<float> input_tensor_values(batch_size * frame_num * feature_dim, 0.5); // 填充随机数据
        std::vector<int64_t> input_dims = {static_cast<int64_t>(batch_size), 
                                           static_cast<int64_t>(frame_num), 
                                           static_cast<int64_t>(feature_dim)};

        // 创建输入 tensor
        auto memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
            memory_info,
            input_tensor_values.data(),
            input_tensor_values.size(),
            input_dims.data(),
            input_dims.size());

        // 运行推理
        auto output_tensors = session.Run(Ort::RunOptions{nullptr},
                                          input_names,
                                          &input_tensor,
                                          1,
                                          output_names,
                                          1);

        // 获取输出
        auto &output_tensor = output_tensors[0];
        float *output_data = output_tensor.GetTensorMutableData<float>();
        auto output_dims = output_tensor.GetTensorTypeAndShapeInfo().GetShape();

        // 打印输出
        std::cout << "Embedding: ";
        for (size_t i = 0; i < output_dims[1]; ++i) {
            std::cout << output_data[i] << " ";
        }
        std::cout << std::endl;

    } catch (const Ort::Exception &e) {
        std::cerr << "ONNX Runtime Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
