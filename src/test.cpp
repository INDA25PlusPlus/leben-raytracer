//
// Created by Leonard on 2025-12-17.
//

#include <iostream>

int main() {
    std::cout << "Hello testing world!" << std::endl;
    if (ENABLE_CUDA_FEATURES) {
        std::cout << "CUDA is enabled!" << std::endl;
    } else {
        std::cout << "CUDA is disabled!" << std::endl;
    }
    return 0;
}
