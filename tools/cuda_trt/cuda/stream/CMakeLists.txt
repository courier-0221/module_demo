cmake_minimum_required(VERSION 3.14) 
project(1-stream)

find_package(CUDA REQUIRED)

# 如果你是不同显卡，请设置为显卡对应的号码参考这里：https://developer.nvidia.com/zh-cn/cuda-gpus#compute
set(CUDA_GEN_CODE "-gencode=arch=compute_86,code=sm_86")
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -std=c++11 -O0 -Xcompiler -fPIC -g -w ${CUDA_GEN_CODE}")

file(GLOB_RECURSE cuda_srcs ${PROJECT_SOURCE_DIR}/1-stream.cu)
cuda_add_executable(${PROJECT_NAME} ${cuda_srcs})