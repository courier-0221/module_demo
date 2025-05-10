#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>

void AlphaMat(cv::Mat &mat)
{
  CHECK(mat.channels() == 4);
  for (int i = 0; i < mat.rows; ++i) {
    for (int j = 0; j < mat.cols; ++j) {
      cv::Vec4b& bgra = mat.at<cv::Vec4b>(i, j);
      bgra[0] = UCHAR_MAX;  // 蓝色通道
      bgra[1] = cv::saturate_cast<uchar>((float(mat.cols - j)) / ((float)mat.cols) * UCHAR_MAX);  // 绿色通道
      bgra[2] = cv::saturate_cast<uchar>((float(mat.rows - i)) / ((float)mat.rows) * UCHAR_MAX);  // 红色通道
      bgra[3] = cv::saturate_cast<uchar>(0.5 * (bgra[1] + bgra[2]));  // Alpha通道
    }
  }
}

TEST(test_save, save_img) {
  cv::Mat mat(480, 640, CV_8UC4);
  AlphaMat(mat);
  std::vector<int> compression_params;
  compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);  //PNG格式图像压缩标志
  compression_params.push_back(9);  //设置最高压缩质量		
  bool result = imwrite("alpha.png", mat, compression_params);
  CHECK(result) << "imwrite error";
}