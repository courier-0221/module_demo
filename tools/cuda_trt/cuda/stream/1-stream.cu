#include <iostream>
#include <cuda_runtime.h>

// 这段CUDA代码创建了两个CUDA流，分别在两个流中执行不同的计算任务。
// 在流1中，使用一个kernel函数将deviceData数组中的每个元素都设置为42+1。
// 在流2中，使用cudaMemcpyAsync函数将deviceData数组中的数据异步地拷贝到hostData数组中。
// 最后，主机等待流1和流2的任务完成，然后打印hostData数组中的数据，并释放所有的资源。
// 这个程序的目的是展示如何使用CUDA流来并行执行多个计算任务。

#define N 1000

__global__ void kernel(int* data, int value) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < N) {
        data[tid] = value + 1;
    }
}

int main() {
    int* hostData;
    int* deviceData;
    cudaStream_t stream1, stream2;

    // 分配主机内存和设备内存
    hostData = (int*)malloc(N * sizeof(int));
    cudaMalloc((void**)&deviceData, N * sizeof(int));

    // 创建cuda流
    cudaStreamCreate(&stream1);
    cudaStreamCreate(&stream2);

    // 在流1中执行计算
    dim3 block(256);
    dim3 grid((N + block.x - 1) / block.x);
    kernel << <grid, block, 0, stream1 >> > (deviceData, 42);

    // 在流2中执行计算
    cudaMemcpyAsync(hostData, deviceData, N * sizeof(int), cudaMemcpyDeviceToHost, stream2);

    // 主机等待流1和流2的任务完成
    cudaStreamSynchronize(stream1);
    cudaStreamSynchronize(stream2);

    // 打印结果
    for (int i = 0; i < N; i++) {
        printf("%d ", hostData[i]);
    }
    printf("\n");

    // 释放资源
    free(hostData);
    cudaFree(deviceData);
    cudaStreamDestroy(stream1);
    cudaStreamDestroy(stream2);

    return 0;
}