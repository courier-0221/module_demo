cmake_minimum_required(VERSION 3.10)
project(sre_trt)
set(CMAKE_CXX_STANDARD 17)

# tensorrt
set(TENSORRT_DIR $ENV{TENSORRT_ROOT})
include_directories(${TENSORRT_DIR}/include)
link_directories(${TENSORRT_DIR}/lib)

# cuda
set(CUDA_DIR $ENV{CUDA_ROOT})
include_directories(${CUDA_DIR}/include)
link_directories(${CUDA_DIR}/lib64)

# kaldi
set(KALDI_DIR $ENV{KALDI_ROOT}/src)
include_directories(
    ${KALDI_DIR}
)
link_directories(
    ${KALDI_DIR}/base
    ${KALDI_DIR}/feat
    ${KALDI_DIR}/util
    ${KALDI_DIR}/matrix
    ${KALDI_DIR}/transform
)

set(SOURCES sre_infer.cc)
add_executable(sre_trt ${SOURCES})
target_link_libraries(sre_trt kaldi-base kaldi-feat kaldi-util kaldi-matrix kaldi-transform)
target_link_libraries(sre_trt nvinfer cudart)
add_definitions(-O2 -pthread)
