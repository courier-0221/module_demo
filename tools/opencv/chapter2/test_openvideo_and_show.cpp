#include <gtest/gtest.h>
#include <glog/logging.h>
#include <opencv2/opencv.hpp>

TEST(test_openvideo_and_show, show_video) {
  cv::VideoCapture video("../../data/cup.mp4");
  CHECK(video.isOpened()) << "open video error";
  LOG(INFO) << "frame width:" << video.get(cv::CAP_PROP_FRAME_WIDTH);
  LOG(INFO) << "frame height:" << video.get(cv::CAP_PROP_FRAME_HEIGHT);
  LOG(INFO) << "fps:" << video.get(cv::CAP_PROP_FPS);
  LOG(INFO) << "frame count:" << video.get(cv::CAP_PROP_FRAME_COUNT);
  
  while(1) {
    cv::Mat frame;
	video >> frame;
    if (frame.empty()) {
	  break;
	}

    imshow("video", frame);
    cv::waitKey(1000 / video.get(cv::CAP_PROP_FPS));
  }

  cv::waitKey();

}