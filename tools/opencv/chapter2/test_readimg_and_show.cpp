#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>

TEST(test_readimg_and_show, show_image) {
  cv::Mat img;
  img = cv::imread("../../data/lena.png");
  CHECK(!img.empty()) << "read img error";
  
  LOG(INFO) << "channels:" << img.channels() << " cols:" << img.cols << " rows:" << img.rows \
    << " step:" << img.step << " total:" << img.total() << " elemsize:" << img.elemSize();
  
  cv::namedWindow("test");
  cv::imshow("test", img);
  cv::waitKey(0);
}