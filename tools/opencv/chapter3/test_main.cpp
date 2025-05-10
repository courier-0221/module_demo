#include <gtest/gtest.h>
#include <glog/logging.h>

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  google::InitGoogleLogging(argv[0]);
  google::LogToStderr();
  LOG(INFO) << "Start test...\n";
  return RUN_ALL_TESTS();
}