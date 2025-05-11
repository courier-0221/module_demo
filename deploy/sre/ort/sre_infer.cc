#include "feat/feature-mfcc.h"   // 用于 MFCC 特征提取
#include "feat/feature-fbank.h"  // 用于 FBank 特征提取
#include "feat/wave-reader.h"    // 用于读取音频文件
#include "transform/cmvn.h"      // 用于 CMVN 操作
#include "util/common-utils.h"   // Kaldi 通用工具

#include <onnxruntime_cxx_api.h>
#include <iostream>
#include <vector>
using namespace kaldi;

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
    SpeakerRecognition(const std::string& model_path, float threshold = 0.6)
        : env_(ORT_LOGGING_LEVEL_WARNING, "SpeakerRecognition"), session_(nullptr) {
        Ort::SessionOptions session_options;
        session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_ALL);
        session_options.SetIntraOpNumThreads(1);

        //profiling机制
        session_options.EnableProfiling("./onnxruntime_profile");

        session_ = std::make_unique<Ort::Session>(env_, model_path.c_str(), session_options);
        session_->GetInputTypeInfo(0);

        threshold_ = threshold;

        // Get input/output information
        initializeIOInfo();
    }

    ~SpeakerRecognition() = default;

    std::vector<float> runInference(const Matrix<BaseFloat> &audio_feat) {
        size_t batch_size = 1;
        size_t sre_feat_len = 192;

        auto memory_info = Ort::MemoryInfo::CreateCpu(OrtDeviceAllocator, OrtMemTypeCPU);

        // 创建输入 tensor
        std::vector<int64_t> input_shape = {static_cast<int64_t>(batch_size), 
                                           static_cast<int64_t>(audio_feat.NumRows()), 
                                           static_cast<int64_t>(audio_feat.NumCols())};
        Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
            memory_info,
            const_cast<float*>(audio_feat.Data()),
            audio_feat.NumRows() * audio_feat.NumCols(),
            input_shape.data(),
            input_shape.size());
        
        // 创建输出 tensor
        std::vector<int64_t> output_shape = {static_cast<int64_t>(batch_size), static_cast<int64_t>(sre_feat_len)};
        std::vector<float> output_result(static_cast<int64_t>(sre_feat_len), 0.0);
        Ort::Value output_tensor = Ort::Value::CreateTensor<float>(
            memory_info,
            output_result.data(),
            static_cast<int64_t>(sre_feat_len),
            output_shape.data(),
            output_shape.size());
        
        session_->Run(Ort::RunOptions{nullptr},
                                          input_names_.data(),
                                          &input_tensor,
                                          batch_size,
                                          output_names_.data(),
                                          &output_tensor,
                                          batch_size);
        
        // debug 打印输出
        // std::cout << "Embedding: " << std::endl;
        // for (size_t i = 0; i < output_shape[1]; ++i) {
        //     std::cout << output_result[i] << " ";
        // }
        // std::cout << std::endl;
        
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
    Ort::Env env_;
    std::unique_ptr<Ort::Session> session_;
    std::vector<const char*> input_names_;
    std::vector<const char*> output_names_;
    KaldiFbankFeatExtractor afe_;
    float threshold_;

    void initializeIOInfo() {
        input_names_.push_back("feature");
        output_names_.push_back("embedding");   
    }

};

int main() {
    std::string model_path = "/home/dear/code/VoiceprintRecognition-Pytorch/models/Res2Net_pt_onnx/inference.onnx";

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
