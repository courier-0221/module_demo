cmake_minimum_required(VERSION 3.16)
#创建工程
project(chapter2)

#找 OpenCV 4.x 安装路径
find_package(OpenCV REQUIRED)
#加载 OpenCV 4.x 的头文件
include_directories(${OpenCV_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#需要链接的库
set(link_lib glog gtest pthread)

#找到源文件
aux_source_directory(./ test_dir)

#将程序生成可执行文件
add_executable(opencv_test ${test_dir})
#glog gtest安装位置在"/usr/local/lib/"
link_directories(/usr/local/lib/)
#链接 lib 文件到可执行文件中
target_link_libraries(opencv_test ${OpenCV_LIBS} ${link_lib})