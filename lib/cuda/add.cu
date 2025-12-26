//
// Created by Leonard on 2025-12-26.
//

#include "add.hpp"

#include <cstdio>
#include <string>

void assert_success(cudaError_t code, std::string message) {
    if (code != cudaSuccess) {
        fprintf(stderr, "CUDA error %d", code);
        exit(EXIT_FAILURE);
    }
}

__global__ void add_kernel(uint32_t const *a, uint32_t const *b, uint32_t *sum, size_t n) {
    auto i = blockDim.x * blockIdx.x + threadIdx.x;
    if (i < n) {
        sum[i] = a[i] + b[i];
    }
}

void add(uint32_t const *a, uint32_t const *b, uint32_t *sum, size_t n) {
    cudaError_t err = cudaSuccess;

    auto size = n * sizeof(uint32_t);

    uint32_t *dev_a, *dev_b, *dev_sum;
    err = cudaMalloc(reinterpret_cast<void **>(&dev_a), size);
    assert_success(err, "CUDA malloc a");
    err = cudaMalloc(reinterpret_cast<void **>(&dev_b), size);
    assert_success(err, "CUDA malloc b");
    err = cudaMalloc(reinterpret_cast<void **>(&dev_sum), size);
    assert_success(err, "CUDA malloc sum");

    err = cudaMemcpy(dev_a, a, size, cudaMemcpyHostToDevice);
    assert_success(err, "CUDA copy a to device");
    err = cudaMemcpy(dev_b, b, size, cudaMemcpyHostToDevice);
    assert_success(err, "CUDA copy b to device");

    auto threadsPerBlock = 256;
    auto blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
    add_kernel<<<blocksPerGrid, threadsPerBlock>>>(a, b, sum, n);
    err = cudaGetLastError();
    assert_success(err, "CUDA kernel");

    err = cudaMemcpy(sum, dev_sum, size, cudaMemcpyDeviceToHost);
    assert_success(err, "CUDA copy sum to host");

    err = cudaFree(dev_a);
    assert_success(err, "CUDA free a");
    err = cudaFree(dev_b);
    assert_success(err, "CUDA free b");
    err = cudaFree(dev_sum);
    assert_success(err, "CUDA free sum");
}
