//
// Created by Leonard on 2025-12-26.
//

#include <iostream>

#include "math/Vec2.hpp"

int main() {
    Vec2 v(1., .5);
    Vec2 w(2., 0.);

    std::cout << "Hello world!" << std::endl;
    std::cout
        << "This is a vector: "
        << (v + w).debug_string()
        << std::endl;
    return 0;
}
