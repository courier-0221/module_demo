#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

// 浅拷贝
TEST(test_shallowcopy, img_add_subimg) {
  Mat img = imread("../../data/lena.png");
  Mat noobcv = imread("../../data/noobcv.jpg");
  CHECK(!img.empty()) << "read img error";
  CHECK(!noobcv.empty()) << "read noobcv error";
  
  Mat renoobcv, ROI;
  
  //对noobcv resize 到 renoobcv
  resize(noobcv, renoobcv, Size(200, 200));
  imshow("renoobcv", renoobcv);

  //定义ROI区域 并截图 ROI1内容还是使用img中的区域，共用
  Rect rect(206, 206, 200, 200);
  ROI = img(rect);
  
  imshow("ROI before", ROI);
  imshow("img before", img);
  
  //将mask内容深拷贝到ROI1
  renoobcv.copyTo(ROI);
  
  imshow("img after", img);
  imshow("ROI after", ROI);
  
  waitKey(0);
}

// 深拷贝
TEST(test_deepcopy, img_add_subimg) {
  Mat img = imread("../../data/lena.png");
  Mat noobcv = imread("../../data/noobcv.jpg");
  CHECK(!img.empty()) << "read img error";
  CHECK(!noobcv.empty()) << "read noobcv error";
  
  Mat renoobcv, ROI;
  
  //对noobcv resize 到 renoobcv
  resize(noobcv, renoobcv, Size(200, 200));
  imshow("renoobcv", renoobcv);

  //定义ROI区域 并截图 将一个img中的区域复制到ROI区域中
  Rect rect(206, 206, 200, 200);
  img(rect).copyTo(ROI);
  
  imshow("ROI before", ROI);
  imshow("img before", img);
  
  //将mask内容深拷贝到ROI1
  renoobcv.copyTo(ROI);
  
  imshow("img after", img);
  imshow("ROI after", ROI);
  
  waitKey(0);
}