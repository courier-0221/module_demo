#include <stdio.h>
#define N (1024)
#define FULL_DATA_SIZE (N*500)

// nvcc -o 1-event 1-event.cu
// 类似cpu统计耗时一样，event的一个用法是可以统计出程序在gpu上运行的时长
// https://unofficial-sendoh.gitbook.io/unofficialsendoh/a/cuda-programming/cuda-events-and-streams

__global__ void add( int *a, int *b, int *c ) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    c[tid] = a[tid] + b[tid];
}

int main(void) {
  float elapsedTime;
  cudaEvent_t start, stop;
  
  cudaEventCreate(&start);
  cudaEventCreate(&stop);
  cudaEventRecord(start, 0);
  
  int host_a[FULL_DATA_SIZE], host_b[FULL_DATA_SIZE], host_c[FULL_DATA_SIZE];
  int *dev_a, *dev_b, *dev_c;
  
  cudaMalloc((void**)&dev_a, N * sizeof(int));
  cudaMalloc((void**)&dev_b, N * sizeof(int));
  cudaMalloc((void**)&dev_c, N * sizeof(int));

  for (int i = 0; i < FULL_DATA_SIZE; i++) {
    host_a[i] = rand();
    host_b[i] = rand();
  }

  for (int i = 0; i < FULL_DATA_SIZE; i+=N) {
    cudaMemcpy(dev_a, host_a + i, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, host_b + i, N * sizeof(int), cudaMemcpyHostToDevice);
    add<<<256,256>>>(dev_a, dev_b, dev_c);
    cudaMemcpy(host_c + i, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost);
  }

  cudaEventRecord(stop, 0);
  cudaEventSynchronize(stop);
  cudaEventElapsedTime(&elapsedTime, start, stop);
  
  printf("Time taken: %3.1f ms\n", elapsedTime);
  
  cudaFree(dev_a);
  cudaFree(dev_b);
  cudaFree(dev_c);
  return 0;
}