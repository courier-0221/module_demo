cmake_minimum_required(VERSION 3.10)
project(sre_ort)
set(CMAKE_CXX_STANDARD 17)

# onnx runtime
set(ONNX_RUNTIME_DIR $ENV{ONNX_RUNTIME_ROOT})
include_directories(${ONNX_RUNTIME_DIR}/include)
link_directories(${ONNX_RUNTIME_DIR}/lib)

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
add_executable(sre_ort ${SOURCES})
target_link_libraries(sre_ort kaldi-base kaldi-feat kaldi-util kaldi-matrix kaldi-transform)
target_link_libraries(sre_ort onnxruntime)
