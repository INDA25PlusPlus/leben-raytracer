//
// Created by Leonard on 2025-12-27.
//

#pragma once
#include "Vec3.hpp"

struct Ray3 {
    static const Ray3 X, Y, Z;

    Vec3 from, dir;

    Ray3(const Ray3 &r) = default;

    Ray3(const Vec3 &from, const Vec3 &dir);
};
