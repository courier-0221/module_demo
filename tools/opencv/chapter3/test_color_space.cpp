#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>
#include <vector>

# if 1
TEST(test_colorsapce, cvcolor) {
  cv::Mat img = cv::imread("../../data/lena.png");
  CHECK(!img.empty()) << "img read error!";
  cv::Mat gray, hsv, yuv, lab, img32f;
  
  //将像素转换成为0-1区间
  img.convertTo(img32f, CV_32F, 1.0/255); //将CV_8U类型转换成CV_32F类型
  //img32.convertTo(img, CV_8U, 255);  //将CV_32F类型转换成CV_8U类型
  cv::cvtColor(img32f, hsv, cv::COLOR_BGR2HSV);
  cv::cvtColor(img32f, yuv, cv::COLOR_BGR2YUV);
  cv::cvtColor(img32f, lab, cv::COLOR_BGR2Lab);
  cv::cvtColor(img32f, gray, cv::COLOR_BGR2GRAY);
  cv::imshow("原图", img32f);
  cv::imshow("HSV", hsv);
  cv::imshow("YUV", yuv);
  cv::imshow("Lab", lab);
  cv::imshow("GRAY", gray);
  
  //不将像素转换成0-1区间，保持原来的0-255做转换对比效果
  gray.release();
  hsv.release();
  yuv.release();
  lab.release();
  cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
  cv::cvtColor(img, yuv, cv::COLOR_BGR2YUV);
  cv::cvtColor(img, lab, cv::COLOR_BGR2Lab);
  cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
  cv::imshow("原图2", img);
  cv::imshow("HSV2", hsv);
  cv::imshow("YUV2", yuv);
  cv::imshow("Lab2", lab);
  cv::imshow("GRAY2", gray);

  cv::waitKey(0);
}


/*
输入数组参数的多通道分离与合并
void split(const Mat& src, Mat* mvbegin);
void merge(const Mat* mv, size_t count, OutputArray dst);
*/
TEST(test_colorsapce, split_and_merge_test1) {
  cv::Mat img = cv::imread("../../data/lena.png");
  CHECK(!img.empty()) << "img read error!";

  cv::Mat imgs0, imgs1, imgs2;  //用于存放数组类型的结果
  cv::Mat result0, result1, result2;  //多通道合并的结果

  //1.显示分离后的rgb每一个通道内容
  cv::Mat imgs[3];
  cv::split(img, imgs);
  imgs0 = imgs[0];
  imgs1 = imgs[1];
  imgs2 = imgs[2];
  cv::imshow("RGB-B通道", imgs0);  //显示分离后B通道的像素值
  cv::imshow("RGB-G通道", imgs1);  //显示分离后G通道的像素值
  cv::imshow("RGB-R通道", imgs2);  //显示分离后R通道的像素值
  
  //2.待合并的图像数组中有超过3个通道，merge和imgshow怎么展示
  imgs[2] = img;  //将数组中的图像通道数变成不统一
  cv::merge(imgs, 3, result0);  //合并图像
  //cv::imshow("result0", result0);  //imshow最多显示4个通道，result0中有5个通道，会报错
  
  //3.使用图像中一个通道数据，填充其他两个通道的合成效果
  cv::Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_8UC1);
  imgs[0] = zero;
  imgs[2] = zero;
  cv::merge(imgs, 3, result1);  //用于还原G通道的真实情况，合并结果为绿色
  cv::imshow("result1", result1);  //显示合并结果

  cv::waitKey(0);
}
#endif

/*
输入vector参数的多通道分离与合并
void split(InputArray m, OutputArrayOfArrays mv);
void merge(InputArrayOfArrays mv, OutputArray dst);
*/
TEST(test_colorsapce, split_and_merge_test2) {
  cv::Mat img = cv::imread("../../data/lena.png");
  CHECK(!img.empty()) << "img read error!";

  cv::Mat imgv0, imgv1, imgv2;  //用于存放vector类型的结果
  cv::Mat result0, result1;  //多通道合并的结果

  cv::Mat HSV, img32f;
  img.convertTo(img32f, CV_32F, 1.0/255); //将CV_8U类型转换成CV_32F类型
  cv::cvtColor(img32f, HSV, cv::COLOR_RGB2HSV);

  //1.显示分离后的hsv每一个通道内容
  std::vector<cv::Mat> imgv;
  cv::split(HSV, imgv);
  imgv0 = imgv.at(0);
  imgv1 = imgv.at(1);
  imgv2 = imgv.at(2);
  cv::imshow("HSV-H通道", imgv0);  //显示分离后H通道的像素值
  cv::imshow("HSV-S通道", imgv1);  //显示分离后S通道的像素值
  cv::imshow("HSV-V通道", imgv2);  //显示分离后V通道的像素值
  
  //2.待合并的图像数组中有超过3个通道，merge和imgshow怎么展示
  imgv.push_back(HSV);  //将vector中的图像通道数变成不统一
  cv::merge(imgv, result0);  //合并图像
  //cv::imshow("result0", result0);  //imshow最多显示4个通道，imgv中有6个通道，会报错

  //3.使用图像中一个通道数据，填充其他两个通道的合成效果
  cv::Mat zero = cv::Mat::zeros(img.rows, img.cols, CV_32FC1);
  std::vector<cv::Mat> imgvv;
  imgvv.push_back(zero);
  imgvv.push_back(zero);
  imgvv.push_back(imgv2);
  cv::merge(imgvv, result1);  //合并图像
  cv::imshow("result1", result1);

  cv::waitKey(0);
}