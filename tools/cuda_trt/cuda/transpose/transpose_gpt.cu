#include <iostream>
#include <cuda_runtime.h>
#include "transpose.hpp"
#include "utils.hpp"

__global__ void transpose_matrix(const int* input_matrix, int* output_matrix, const int rows, const int cols) {
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    if (x < rows && y < cols) {
        output_matrix[y * rows + x] = input_matrix[x * cols + y];
    }
}

void transpose_gpt()
{
    const int rows = 3;
    const int cols = 3;
    const int input_size = rows * cols;
    const int output_size = cols * rows;

    // 定义输入矩阵
    int input_matrix[rows][cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // 定义输出矩阵
    int output_matrix[cols][rows];

    // 将输入矩阵和输出矩阵复制到GPU内存中
    int* d_input_matrix;
    int* d_output_matrix;
    cudaMalloc((void**)&d_input_matrix, input_size * sizeof(int));
    cudaMalloc((void**)&d_output_matrix, output_size * sizeof(int));
    cudaMemcpy(d_input_matrix, input_matrix, input_size * sizeof(int), cudaMemcpyHostToDevice);

    // 定义CUDA线程块和线程数
    dim3 threads_per_block(16, 16);
    dim3 blocks_per_grid((rows + threads_per_block.x - 1) / threads_per_block.x, (cols + threads_per_block.y - 1) / threads_per_block.y);

    // 调用CUDA函数
    transpose_matrix<<<blocks_per_grid, threads_per_block>>>(d_input_matrix, d_output_matrix, rows, cols);

    // 将结果从GPU内存中复制回CPU内存中
    CUDA_CHECK(cudaMemcpy(output_matrix, d_output_matrix, output_size * sizeof(int), cudaMemcpyDeviceToHost));

    CUDA_CHECK(cudaDeviceSynchronize());

    // 打印输入矩阵和输出矩阵
    std::cout << "Input Matrix:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << input_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Output Matrix:" << std::endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            std::cout << output_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // 释放GPU内存
    cudaFree(d_input_matrix);
    cudaFree(d_output_matrix);
}


