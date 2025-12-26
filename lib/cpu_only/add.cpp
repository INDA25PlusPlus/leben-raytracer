//
// Created by Leonard on 2025-12-26.
//

#include "add.hpp"

void add(uint32_t const *a, uint32_t const *b, uint32_t *sum, size_t n) {
    for (auto i = 0; i < n; i++) {
        sum[i] = a[i] + b[i];
    }
}
