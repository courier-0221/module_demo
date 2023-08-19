#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>

TEST(test_mat, mat_attribute) {
  cv::Mat data(3, 4, CV_32FC3);
  LOG(INFO) << "channels:" << data.channels() << " cols:" << data.cols << " rows:" << data.rows \
    << " step:" << data.step << " total:" << data.total() << " elemsize:" << data.elemSize();
}

TEST(test_mat, create_and_print_1_channel) {
  cv::Mat data(3, 4, CV_32SC1);
  
  for (int i = 0; i < data.rows; i++) {
    for (int j = 0; j < data.cols; j++) {
      data.at<int>(i, j) = i + j;
    }
  }

  for (int i = 0; i < data.rows; i++) {
    int* ptr = data.ptr<int>(i);
    for (int j = 0; j < data.cols*data.channels(); j++) {
      LOG(INFO) << (int)ptr[j];
    }
    printf("\n");
  }
}

TEST(test_mat, create_and_print_3_channel) {
  cv::Mat data(3, 4, CV_32SC3);
  
  for (int i = 0; i < data.rows; i++) {
    for (int j = 0; j < data.cols; j++) {
      data.at<cv::Vec3i>(i, j) = cv::Vec3i(i+j, i+j, i+j);
    }
  }

  for (int i = 0; i < data.rows; i++) {
    int* ptr = data.ptr<int>(i);
    for (int j = 0; j < data.cols*data.channels(); j++) {
      LOG(INFO) << (int)ptr[j];
    }
    printf("\n");
  }
}

TEST(test_mat, operation_add_1_channel_with_operand) {
  cv::Mat data(3, 4, CV_32SC1);
  
  for (int i = 0; i < data.rows; i++) {
    for (int j = 0; j < data.cols; j++) {
      data.at<int>(i, j) = i+j;
    }
  }

  data = data + 100;

  for (int i = 0; i < data.rows; i++) {
    int* ptr = data.ptr<int>(i);
    for (int j = 0; j < data.cols*data.channels(); j++) {
      LOG(INFO) << (int)ptr[j];
    }
    printf("\n");
  }
}

TEST(test_mat, operation_add_3_channel_with_operand) {
  cv::Mat data(3, 4, CV_32SC3);
  
  for (int i = 0; i < data.rows; i++) {
    for (int j = 0; j < data.cols; j++) {
      //data.at<cv::Vec3i>(i, j) = cv::Vec3i(i+j, i+j, i+j);
      data.at<cv::Vec3i>(i, j)[0] = i + j;
      data.at<cv::Vec3i>(i, j)[1] = i + j;
      data.at<cv::Vec3i>(i, j)[2] = i + j;
    }
  }

  int addvalue = 100;
  for (cv::MatIterator_<cv::Vec3i> it = data.begin<cv::Vec3i>(); it != data.end<cv::Vec3i>(); ++it) {
    (*it)[0] += addvalue;
    (*it)[1] += addvalue;
    (*it)[2] += addvalue;
  }

  for (int i = 0; i < data.rows; i++) {
    int* ptr = data.ptr<int>(i);
    for (int j = 0; j < data.cols*data.channels(); j++) {
      LOG(INFO) << (int)ptr[j];
    }
    printf("\n");
  }
}

TEST(test_mat, operation_mul_1_channel_with_mat) {
  cv::Mat num1(2, 3, CV_32FC1, cv::Scalar(1));
  cv::Mat num2(3, 2, CV_32FC1, cv::Scalar(1));

  LOG(INFO) << num1;
  LOG(INFO) << num2;
  
  cv::Mat result = num1 * num2;

  LOG(INFO) << result;
}

TEST(test_mat, operation_mul_3_channel_with_mat) {
  cv::Mat num1(2, 3, CV_32FC3, cv::Scalar(1,1,1));
  cv::Mat num2(3, 2, CV_32FC3, cv::Scalar(1,1,1));

  LOG(INFO) << num1;
  LOG(INFO) << num2;
  
  // 会报错，目前先不研究多通道的内容相乘
  //cv::Mat result = num1 * num2;
  //LOG(INFO) << result;
}