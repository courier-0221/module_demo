#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

TEST(test_pyramid, gauss_pyramid) {

  Mat img = imread("../../data/lena.png");
  CHECK(!img.empty()) << "read img error";
  vector<Mat> Gauss, Lap;  //高斯金字塔
  int level = 3;  //高斯金字塔下采样次数
  Gauss.push_back(img);  //将原图作为高斯金字塔的第0层
  //构建高斯金字塔
  for (int i = 0; i < level; i++) {
    Mat gauss;
    pyrDown(Gauss[i], gauss);  //下采样
    Gauss.push_back(gauss);
  }

  for (int i = 0; i < level + 1; i++) {
    string name = to_string(i);
    imshow("G" + name, Gauss[i]);
  }

  waitKey(0);
}
