#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <vector>

//像素统计
TEST(test_maxandmin, findmaxandmin1) {
  float a[12] = { 1, 2, 3, 4, 5, 10, 6, 7, 8, 9, 10, 0 };
  cv::Mat img = cv::Mat(3, 4, CV_32FC1, a);  //单通道矩阵
  cv::Mat imgs = cv::Mat(2, 3, CV_32FC2, a);  //多通道矩阵
  double minVal, maxVal;  //用于存放矩阵中的最大值和最小值
  cv::Point minIdx, maxIdx;  ////用于存放矩阵中的最大值和最小值在矩阵中的位置

  /*寻找单通道矩阵中的最值*/
  cv::minMaxLoc(img, &minVal, &maxVal, &minIdx, &maxIdx);
  LOG(INFO) << "img中最大值是:" << maxVal << "  " << "在矩阵中的位置:" << maxIdx;
  LOG(INFO) << "img中最小值是:" << minVal << "  " << "在矩阵中的位置:" << minIdx;

  /*寻找多通道矩阵中的最值*/
  cv::Mat imgs_re = imgs.reshape(1, 4);  //将多通道矩阵变成单通道矩阵
  cv::minMaxLoc(imgs_re, &minVal, &maxVal, &minIdx, &maxIdx);
  LOG(INFO) << "imgs中最大值是:" << maxVal << "  " << "在矩阵中的位置:" << maxIdx;
  LOG(INFO) << "imgs中最小值是:" << minVal << "  " << "在矩阵中的位置:" << minIdx;
}

TEST(test_maxandmin, findmaxandmin2) {
  // rgb彩色图像
  cv::Mat img1 = cv::imread("../../data/lena.png");
  CHECK(!img1.empty()) << "img read error!";
  // 灰度图像
  cv::Mat img2 = cv::imread("../../data/threshold.png");
  CHECK(!img2.empty()) << "img read error!";

  double minVal, maxVal;  //用于存放矩阵中的最大值和最小值
  cv::Point minIdx, maxIdx;  ////用于存放矩阵中的最大值和最小值在矩阵中的位置

  //读取rgb的彩色图像，找到里面的最大和最小值，是0-255
  cv::Mat imgs_re = img1.reshape(1);  //将多通道矩阵变成单通道矩阵
  cv::minMaxLoc(imgs_re, &minVal, &maxVal, &minIdx, &maxIdx);
  LOG(INFO) << "img中最大值是:" << maxVal << "  " << "在矩阵中的位置:" << maxIdx;
  LOG(INFO) << "img中最小值是:" << minVal << "  " << "在矩阵中的位置:" << minIdx;

  //读取灰度图像，找到里面的最大和最小值，是0-255
  cv::Mat imgs_re2 = img2.reshape(1);  //将多通道矩阵变成单通道矩阵
  cv::minMaxLoc(imgs_re2, &minVal, &maxVal, &minIdx, &maxIdx);
  LOG(INFO) << "img中最大值是:" << maxVal << "  " << "在矩阵中的位置:" << maxIdx;
  LOG(INFO) << "img中最小值是:" << minVal << "  " << "在矩阵中的位置:" << minIdx;

}

//像素操作 -- 二值化
TEST(test_threshold, threshold) {
  cv::Mat img = cv::imread("../../data/lena.png");
  CHECK(!img.empty()) << "img read error!";
  cv::Mat gray;
  cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
  cv::Mat img_B, img_B_V, gray_B, gray_B_V, gray_T, gray_T_V, gray_TRUNC;
  
  //彩色图像BINARY二值化
  cv::threshold(img, img_B, 125, 255, cv::THRESH_BINARY);
  cv::threshold(img, img_B_V, 125, 255, cv::THRESH_BINARY_INV);
  cv::imshow("img_B", img_B);
  cv::imshow("img_B_V", img_B_V);

  //灰度图BINARY二值化
  cv::threshold(gray, gray_B, 125, 255, cv::THRESH_BINARY);
  cv::threshold(gray, gray_B_V, 125, 255, cv::THRESH_BINARY_INV);
  cv::imshow("gray_B", gray_B);
  cv::imshow("gray_B_V", gray_B_V);

  //灰度图像TOZERO变换
  cv::threshold(gray, gray_T, 125, 255, cv::THRESH_TOZERO);
  cv::threshold(gray, gray_T_V, 125, 255, cv::THRESH_TOZERO_INV);
  cv::imshow("gray_T", gray_T);
  cv::imshow("gray_T_V", gray_T_V);

  //灰度图像TRUNC变换
  cv::threshold(gray, gray_TRUNC, 125, 255, cv::THRESH_TRUNC);
  cv::imshow("gray_TRUNC", gray_TRUNC);

  //灰度图像大津法和三角形法二值化
  cv::Mat img_Thr = imread("../../data/threshold.png", cv::IMREAD_GRAYSCALE);
  cv::Mat img_Thr_O, img_Thr_T;
  cv::threshold(img_Thr, img_Thr_O, 100, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
  cv::threshold(img_Thr, img_Thr_T, 125, 255, cv::THRESH_BINARY | cv::THRESH_TRIANGLE);
  cv::imshow("img_Thr", img_Thr);
  cv::imshow("img_Thr_O", img_Thr_O);
  cv::imshow("img_Thr_T", img_Thr_T);

  //灰度图像自适应二值化
  cv::Mat adaptive_mean, adaptive_gauss;
  cv::adaptiveThreshold(img_Thr, adaptive_mean, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 55, 0);
  cv::adaptiveThreshold(img_Thr, adaptive_gauss, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 55, 0);
  cv::imshow("adaptive_mean", adaptive_mean);
  cv::imshow("adaptive_gauss", adaptive_gauss);
  
  cv::waitKey(0);
}

TEST(test_lut, lut) {
  //LUT查找表第一层
  uchar lutFirst[256];
  for (int i = 0; i<256; i++) {
    if (i <= 100)
      lutFirst[i] = 0;
    if (i > 100 && i <= 200)
      lutFirst[i] = 100;
    if (i > 200)
      lutFirst[i] = 255;
  }
  cv::Mat lutOne(1, 256, CV_8UC1, lutFirst);

  //LUT查找表第二层
  uchar lutSecond[256];
  for (int i = 0; i<256; i++) {
    if (i <= 100)
      lutSecond[i] = 0;
    if (i > 100 && i <= 150)
      lutSecond[i] = 100;
    if (i > 150 && i <= 200)
      lutSecond[i] = 150;
    if (i > 200)
      lutSecond[i] = 255;
  }
  cv::Mat lutTwo(1, 256, CV_8UC1, lutSecond);

  //LUT查找表第三层
  uchar lutThird[256];
  for (int i = 0; i<256; i++) {
    if (i <= 100)
      lutThird[i] = 100;
    if (i > 100 && i <= 200)
      lutThird[i] = 200;
    if (i > 200)
      lutThird[i] = 255;
  }
  cv::Mat lutThree(1, 256, CV_8UC1, lutThird);

  //拥有三通道的LUT查找表矩阵
  std::vector<cv::Mat> mergeMats;
  mergeMats.push_back(lutOne);
  mergeMats.push_back(lutTwo);
  mergeMats.push_back(lutThree);
  cv::Mat LutTree;
  cv::merge(mergeMats, LutTree);

  //计算图像的查找表
  cv::Mat img = cv::imread("../../data/lena.png");
  CHECK(!img.empty()) << "img read error!";
  cv::Mat gray, out0, out1, out2;
  cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
  cv::LUT(gray, lutOne, out0);
  cv::LUT(img, lutOne, out1);
  cv::LUT(img, LutTree, out2);
  cv::imshow("out0", out0);
  cv::imshow("out1", out1);
  cv::imshow("out2", out2);

  cv::waitKey(0);
}
