#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <vector>

TEST(test_plot, plot) {
  cv::Mat img = cv::Mat::zeros(cv::Size(512, 512), CV_8UC3);  //生成一个黑色图像用于绘制几何图形
  
  //绘制圆形
  cv::circle(img, cv::Point(50, 50), 25, cv::Scalar(255, 255, 255), -1);  //绘制一个实心圆
  cv::circle(img, cv::Point(100, 50), 20, cv::Scalar(255, 255, 255), 4);  //绘制一个空心圆
  
  //绘制直线
  cv::line(img, cv::Point(100, 100), cv::Point(200, 100), cv::Scalar(255, 255, 255), 2, cv::LINE_4,0);  //绘制一条直线
  
  //绘制椭圆
  cv::ellipse(img, cv::Point(300, 255), cv::Size(100, 70), 0, 0, 100, cv::Scalar(255, 255, 255), -1);  //绘制实心椭圆的一部分
  cv::ellipse(img, cv::RotatedRect(cv::Point2f(150, 100), cv::Size2f(30, 20), 0), cv::Scalar(0, 0, 255), 2);  //绘制一个空心椭圆
  std::vector<cv::Point> points;
  cv::ellipse2Poly(cv::Point(200, 400), cv::Size(100, 70),0,0,360,2,points);  //用一些点来近似一个椭圆
  for (int i = 0; i < points.size()-1; i++) {//用直线把这个椭圆画出来 
    if (i==points.size()-1) {
      cv::line(img, points[0], points[i], cv::Scalar(255, 255, 255), 2);  //椭圆中后于一个点与第一个点连线
      break;
    }
    cv::line(img, points[i], points[i+1], cv::Scalar(255, 255, 255), 2);  //当前点与后一个点连线
  }
  
  //绘制矩形
  cv::rectangle(img, cv::Point(50, 400), cv::Point(100, 450), cv::Scalar(125, 125, 125), -1);  
  cv::rectangle(img, cv::Rect(400,450,60,50), cv::Scalar(0, 125, 125), 2);
  
  //绘制多边形
  cv::Point pp[2][6];
  pp[0][0] = cv::Point(72, 200);
  pp[0][1] = cv::Point(142, 204);
  pp[0][2] = cv::Point(226, 263);
  pp[0][3] = cv::Point(172, 310);
  pp[0][4] = cv::Point(117, 319);
  pp[0][5] = cv::Point(15, 260);
  pp[1][0] = cv::Point(359, 339);
  pp[1][1] = cv::Point(447, 351);
  pp[1][2] = cv::Point(504, 349);
  pp[1][3] = cv::Point(484, 433);
  pp[1][4] = cv::Point(418, 449);
  pp[1][5] = cv::Point(354, 402);
  cv::Point pp2[5];
  pp2[0] = cv::Point(350, 83);
  pp2[1] = cv::Point(463, 90);
  pp2[2] = cv::Point(500, 171);
  pp2[3] = cv::Point(421, 194);
  pp2[4] = cv::Point(338, 141);
  const cv::Point* pts[3] = { pp[0],pp[1],pp2 };  //pts变量的生成
  int npts[] = { 6,6,5 };  //顶点个数数组的生成
  cv::fillPoly(img, pts, npts, 3, cv::Scalar(125, 125, 125),8);  //绘制3个多边形
  
  //生成文字
  cv::putText(img, "Learn OpenCV 4",cv::Point(100, 400), 2, 1, cv::Scalar(255, 255, 255));
  cv::imshow("", img);
  cv::waitKey(0);
}