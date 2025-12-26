//
// Created by Leonard on 2025-12-26.
//

#include <cassert>
#include <cstdint>
#include <iostream>
#include <iterator>

#include "lib/include/add.hpp"

int main() {
    uint32_t a[] = {1, 2, 3, 4, 5, 6};
    uint32_t b[] = {2, 4, 6, 8, 10, 12};
    uint32_t expected[] = {3, 6, 9, 12, 15, 18};

    uint32_t sum[std::size(a)];
    add(a, b, sum, std::size(a));

    assert(std::equal(expected, std::end(expected), sum));
    std::cout << "All tests succeeded" << std::endl;
    return 0;
}
