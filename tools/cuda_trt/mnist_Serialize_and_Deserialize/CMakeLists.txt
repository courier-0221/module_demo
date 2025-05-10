cmake_minimum_required(VERSION 3.14) 
project(mnist)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wno-error=deprecated-declarations -Wno-deprecated-declarations ")

set(CUDA_TOOLKIT_ROOT_DIR     "/usr/local/cuda")
set(CUDNN_DIR    "/usr/local/cuda/")
# set(TENSORRT_DIR "/opt/TensorRT-8.2.1.8")
set(TENSORRT_DIR "/opt/TensorRT-8.6.1.6")
# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/workspace)

include_directories(
    ${CUDA_TOOLKIT_ROOT_DIR}/include
    ${TENSORRT_DIR}/include
    ${CUDNN_DIR}/include
)

link_directories(
    ${TENSORRT_DIR}/lib
    ${CUDA_TOOLKIT_ROOT_DIR}/lib64
    ${CUDNN_DIR}/lib
)

add_executable(Serialize_onnx Serialize_onnx.cpp)
target_link_libraries(Serialize_onnx nvinfer cudart nvonnxparser)
add_definitions(-O2 -pthread)

add_executable(Deserialize Deserialize.cpp)
target_link_libraries(Deserialize nvinfer cudart)
add_definitions(-O2 -pthread)

add_executable(0-read_show_pgm 0-read_show_pgm.cpp)
add_definitions(-O2)

