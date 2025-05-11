#include <iostream>
#include <vector>
#include <assert.h>
#include <fstream>
#include <chrono>
#include <memory>

#include "feat/feature-mfcc.h"   // 用于 MFCC 特征提取
#include "feat/feature-fbank.h"  // 用于 FBank 特征提取
#include "feat/wave-reader.h"    // 用于读取音频文件
#include "transform/cmvn.h"      // 用于 CMVN 操作
#include "util/common-utils.h"   // Kaldi 通用工具

#include <NvInfer.h>
#include <cuda_runtime_api.h>

using namespace kaldi;

struct InferDeleter
{
    template <typename T>
    void operator()(T* obj) const
    {
        delete obj;
    }
};

void checkCudaErrors(cudaError_t err) {
    if (err != cudaSuccess) {
        std::cerr << "CUDA error: " << cudaGetErrorString(err) << std::endl;
        exit(-1);
    }
}

class Logger : public nvinfer1::ILogger{
	virtual void log(Severity severity, const char* msg) noexcept override{
		if (severity != Severity::kINFO)
			std::cout << msg << std::endl;
	}
};


class KaldiFbankFeatExtractor {
public:
    KaldiFbankFeatExtractor(int num_mel_bins = 80, float frame_length_ms = 25.0, float frame_shift_ms = 10.0)
        : num_mel_bins_(num_mel_bins), frame_length_ms_(frame_length_ms), frame_shift_ms_(frame_shift_ms) {}

    Matrix<BaseFloat> ExtractFeatures(const std::string& wav_file) {
        Matrix<BaseFloat> features;
        
        static int save_index = 0;
        char save_buf[128] = {0};

        try {
            WaveData wave_data;
            Input wave_input(wav_file);
            wave_data.Read(wave_input.Stream());

            BaseFloat samp_freq = wave_data.SampFreq();
            Matrix<BaseFloat> wave_matrix = wave_data.Data();
            if (wave_matrix.NumRows() != 1) {
                KALDI_ERR << "Only single channel audio is supported!";
            }
            SubVector<BaseFloat> wave(wave_matrix, 0); // 提取单声道

            // 配置 FBank 参数
            FbankOptions fbank_opts;
            fbank_opts.frame_opts.samp_freq = samp_freq; 
            fbank_opts.mel_opts.num_bins = num_mel_bins_; 
            fbank_opts.frame_opts.frame_length_ms = frame_length_ms_; 
            fbank_opts.frame_opts.frame_shift_ms = frame_shift_ms_; 
            Fbank fbank(fbank_opts);

            // FbankOptions fbank_opts;
            // fbank_opts.frame_opts.dither = 1.0;
            // fbank_opts.frame_opts.samp_freq = 16000.0;
            // fbank_opts.frame_opts.frame_length_ms = 25.0;
            // fbank_opts.frame_opts.frame_shift_ms = 10.0;
            // fbank_opts.mel_opts.num_bins = 80;
            // fbank_opts.mel_opts.low_freq = 20.0;
            // fbank_opts.mel_opts.high_freq = 0.0;
            // Fbank fbank(fbank_opts);

            fbank.ComputeFeatures(wave, samp_freq, 1.0, &features);
            
            // snprintf(save_buf, sizeof(save_buf), "fbank_feats_before_%d.ark", save_index);
            // // Output fbank_out_b("fbank_feats_before.ark", false);
            // Output fbank_out_b(save_buf, false);
            // features.Write(fbank_out_b.Stream(), false);

            // cmvn
            Matrix<double> cmvn_stats(2, features.NumCols() + 1);
            cmvn_stats.SetZero();
            AccCmvnStats(features, nullptr, &cmvn_stats);
            ApplyCmvn(cmvn_stats, false, &features);

            // bzero(save_buf, sizeof(save_buf));
            // snprintf(save_buf, sizeof(save_buf), "fbank_feats_after_%d.ark", save_index);
            // // Output fbank_out_a("fbank_feats_after.ark", false);
            // Output fbank_out_a(save_buf, false);
            // features.Write(fbank_out_a.Stream(), false);
            // save_index++;
        } catch (const std::exception& e) {
            std::cerr << "Error extracting features: " << e.what() << std::endl;
            return Matrix<BaseFloat>();
        }

        return features;
    }

private:
    int num_mel_bins_        = 80;          // Mel 滤波器组数量
    float frame_length_ms_   = 25.0;        // 帧长度（毫秒）
    float frame_shift_ms_    = 10.0;        // 帧移（毫秒）
};


class SpeakerRecognition {
public:
    SpeakerRecognition(const std::string& planFilePath, float threshold = 0.6) {
        init(planFilePath);

        threshold_ = threshold;
    }

    ~SpeakerRecognition() {
    }

    std::vector<float> runInference(const Matrix<BaseFloat> &audio_feat) {
        int batchSize = 1;
        int inputSize = audio_feat.NumRows() * audio_feat.NumCols();
        int outputSize = 192;

        nvinfer1::Dims inputDims {3, {batchSize, audio_feat.NumRows(), audio_feat.NumCols()}};
        context_->setInputShape("feature", inputDims);

        void* inputDataGPU;
        void* outputDataGPU;
        checkCudaErrors(cudaMalloc(&inputDataGPU, inputSize * batchSize * sizeof(float)));
        checkCudaErrors(cudaMalloc(&outputDataGPU, outputSize * batchSize * sizeof(float)));

        checkCudaErrors(cudaMemcpy(inputDataGPU, audio_feat.Data(), inputSize * batchSize * sizeof(float), cudaMemcpyHostToDevice));

        void* bindings[2];
        bindings[0] = inputDataGPU;
        bindings[1] = outputDataGPU;
        
        // auto start = std::chrono::system_clock::now();
        context_->executeV2(bindings);
        // auto end = std::chrono::system_clock::now();
        // std::cout << "\n[INFO]: Time taken by execution: "
        //         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
        //         << "ms" << std::endl;

        std::vector<float> output_result(static_cast<int64_t>(outputSize), 0.0);
        output_result.resize(outputSize * batchSize);
        checkCudaErrors(cudaMemcpy(output_result.data(), outputDataGPU, outputSize * batchSize * sizeof(float), cudaMemcpyDeviceToHost));

        cudaFree(inputDataGPU);
        cudaFree(outputDataGPU);

        return output_result;
    }

    bool contrast(const std::string& audio_path_1, const std::string& audio_path_2) {
        bool ret = false;

        Matrix<BaseFloat> audio_feat_1 = afe_.ExtractFeatures(audio_path_1);
        std::vector<float> sre_feat_1 = runInference(audio_feat_1);

        Matrix<BaseFloat> audio_feat_2 = afe_.ExtractFeatures(audio_path_2);
        std::vector<float> sre_feat_2 = runInference(audio_feat_2);

        // Output fbank_out_1("audio1_feat.ark", false);
        // audio_feat_1.Write(fbank_out_1.Stream(), false);

        // Output fbank_out_2("audio2_feat.ark", false);
        // audio_feat_2.Write(fbank_out_2.Stream(), false);

        float score = cosine(sre_feat_1, sre_feat_2);
    
        if (score >= threshold_) {
            std::cout << "score: " << score << ". is the same persion" << std::endl;
            return true;
        } else {
            std::cout << "score: " << score << ". is not the same persion" << std::endl;
            return false;
        }
    }

    float cosine(const std::vector<float>& vec1, const std::vector<float>& vec2) {
        if (vec1.size() != vec2.size()) {
            std::cout << "Vectors must have the same size." << std::endl;
            return 0.0;
        }

        float dot_product = 0.0;
        float norm_a = 0.0;
        float norm_b = 0.0;

        // 计算点积和范数
        for (size_t i = 0; i < vec1.size(); ++i) {
            dot_product += vec1[i] * vec2[i];
            norm_a += vec1[i] * vec1[i];
            norm_b += vec2[i] * vec2[i];
        }

        if (norm_a == 0.0 || norm_b == 0.0) {
            std::cout << "One of the vectors is zero, cosine similarity is undefined." << std::endl;
            return 0.0;
        }

        // 返回余弦相似度
        return dot_product / (std::sqrt(norm_a) * std::sqrt(norm_b));
    }

private:
    void init(const std::string& planFilePath) {
        logger_ = std::unique_ptr<nvinfer1::ILogger>(new Logger());
        runtime_ = std::shared_ptr<nvinfer1::IRuntime>(nvinfer1::createInferRuntime(*logger_.get()));

        // Load the .plan file
        std::ifstream planFile(planFilePath, std::ios::binary);
        if (!planFile.is_open()) {
            std::cerr << "Failed to open plan file: " << planFilePath << std::endl;
            exit(-1);
        }

        planFile.seekg(0, std::ios::end);
        size_t planSize = planFile.tellg();
        planFile.seekg(0, std::ios::beg);
        std::vector<char> planData(planSize);
        planFile.read(planData.data(), planSize);
        planFile.close();

        // Deserialize the engine from the .plan file
        engine_ = std::shared_ptr<nvinfer1::ICudaEngine>(runtime_->deserializeCudaEngine(planData.data(), planData.size()), InferDeleter());
        if (!engine_) {
            std::cerr << "Failed to deserialize engine from .plan file." << std::endl;
            exit(-1);
        }

        context_ = std::shared_ptr<nvinfer1::IExecutionContext>(engine_->createExecutionContext());
        if (!context_) {
            std::cerr << "Failed to context_." << std::endl;
            exit(-1);
        }
    }
private:
    // 析构顺序很讲究
    std::unique_ptr<nvinfer1::ILogger> logger_;
    std::shared_ptr<nvinfer1::IRuntime> runtime_;
    std::shared_ptr<nvinfer1::ICudaEngine> engine_;
    std::shared_ptr<nvinfer1::IExecutionContext> context_;
    KaldiFbankFeatExtractor afe_;
    float threshold_;
};

int main() {
    std::string model_path = "/home/dear/code/deploy/sre/trt/sre.plan";

    SpeakerRecognition sre(model_path);
    std::string audio_1("/home/dear/code/VoiceprintRecognition-Pytorch/dataset/a_1.wav");
    std::string audio_2("/home/dear/code/VoiceprintRecognition-Pytorch/dataset/a_2.wav");

    auto start = std::chrono::system_clock::now();
    sre.contrast(audio_1, audio_2);
    auto end = std::chrono::system_clock::now();
    std::cout << "[INFO]: Time taken by execution: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
            << "ms" << std::endl;

    start = std::chrono::system_clock::now();
    sre.contrast(audio_1, audio_2);
    end = std::chrono::system_clock::now();
    std::cout << "[INFO]: Time taken by execution: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() 
            << "ms" << std::endl;

    return 0;
}
