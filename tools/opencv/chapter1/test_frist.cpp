#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>

TEST(test_first, show_image) {
  LOG(INFO) << "My first test!";
  cv::Mat img;
  img = cv::imread("../../data/lena.png");
  cv::imshow("test", img);
  cv::waitKey(0);
}