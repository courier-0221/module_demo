cmake_minimum_required(VERSION 3.16)
#创建工程
project(chapter3)

#找 OpenCV 4.x 安装路径
find_package(OpenCV REQUIRED)
#加载 OpenCV 4.x 的头文件
include_directories(${OpenCV_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#需要链接的库
set(link_lib glog gtest pthread)

#添加源文件
set(color_space_src test_main.cpp test_color_space.cpp)
set(pixel_operation_src test_main.cpp test_pixel_operation.cpp)
set(plot_src test_main.cpp test_plot.cpp)
set(deepcopy_src test_main.cpp test_deepcopy.cpp)
set(interactive_src test_main.cpp test_interactive.cpp)
set(pyramid_src test_main.cpp test_pyramid.cpp)

#将程序生成可执行文件
add_executable(color_space ${color_space_src})
add_executable(pixel_operation ${pixel_operation_src})
add_executable(plot ${plot_src})
add_executable(deepcopy ${deepcopy_src})
add_executable(interactive ${interactive_src})
add_executable(pyramid ${pyramid_src})
#glog gtest安装位置在"/usr/local/lib/"
link_directories(/usr/local/lib/)
#链接 lib 文件到可执行文件中
target_link_libraries(color_space ${OpenCV_LIBS} ${link_lib})
target_link_libraries(pixel_operation ${OpenCV_LIBS} ${link_lib})
target_link_libraries(plot ${OpenCV_LIBS} ${link_lib})
target_link_libraries(deepcopy ${OpenCV_LIBS} ${link_lib})
target_link_libraries(interactive ${OpenCV_LIBS} ${link_lib})
target_link_libraries(pyramid ${OpenCV_LIBS} ${link_lib})