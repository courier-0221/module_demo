#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

Mat img, imgPoint;
Point prePoint; //前一时刻鼠标的坐标，用于绘制直线

void mouse(int event, int x, int y, int flags, void*) {
  if (event == EVENT_RBUTTONDOWN) //单击右键
  {
    LOG(INFO) << "点击鼠标左键才可以绘制轨迹";
  }
  if (event == EVENT_LBUTTONDOWN) //单击左键，输出坐标
  {
    prePoint = Point(x, y);
    LOG(INFO) << "轨迹起始坐标" << prePoint;
  }
  if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) //鼠标按住左键移动第 3 章 图像基本操作
  {
   //通过改变图像像素显示鼠标移动轨迹
    imgPoint.at<Vec3b>(y, x) = Vec3b(0, 0, 255);
    imgPoint.at<Vec3b>(y, x - 1) = Vec3b(0, 0, 255);
    imgPoint.at<Vec3b>(y, x + 1) = Vec3b(0, 0, 255);
    imgPoint.at<Vec3b>(y + 1, x) = Vec3b(0, 0, 255);
    imgPoint.at<Vec3b>(y + 1, x) = Vec3b(0, 0, 255);
    imshow("图像窗口 2", imgPoint);
    
    //通过绘制直线显示鼠标移动轨迹
    Point pt(x, y);
    line(img, prePoint, pt, Scalar(0, 0, 255), 2, 5, 0);
    prePoint = pt;
    imshow("图像窗口 1", img);
  }
}

TEST(test_interactive, mouse) {
  img = imread("../../data/lena.png");
  CHECK(!img.empty()) << "read img error";
  img.copyTo(imgPoint);
  imshow("图像窗口 1", img);
  imshow("图像窗口 2", imgPoint);
  setMouseCallback("图像窗口 1", mouse, 0); //鼠标影响
  waitKey(0);
}

int value;
Mat img1, img2;
void callBack(int, void*) {
  float a = value / 100.0;
  img2 = img1 * a;
  imshow("滑动条改变图像亮度", img2);
}

TEST(test_interactive, trackbar) {
  img1 = imread("../../data/lena.png");
  CHECK(!img1.empty()) << "read img error";
  namedWindow("滑动条改变图像亮度");
  imshow("滑动条改变图像亮度", img1);
  value = 100;  //滑动条创建时的初值
  //创建滑动条
  createTrackbar("亮度值百分比", "滑动条改变图像亮度", &value, 600, callBack, 0);
  waitKey();
}