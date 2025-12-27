//
// Created by Leonard on 2025-12-27.
//

#pragma once
#include <string>

#include "Axis.hpp"
#include "Vec2.hpp"
#include "config.hpp"


struct Vec3 {
    static const Vec3 ZERO, ONE, X, Y, Z, MIN, MAX;

    number_t x, y, z;

    Vec3(number_t x, number_t y, number_t z);
    Vec3(Vec2 xy, number_t z);
    Vec3(number_t x, Vec2 yz);
    explicit Vec3(number_t xyz);

    Vec3 operator+(const Vec3 &w) const;
    Vec3 operator+(number_t w) const;

    Vec3 operator-(const Vec3 &w) const;
    Vec3 operator-(number_t w) const;

    Vec3 operator*(const Vec3 &w) const;
    Vec3 operator*(number_t w) const;

    Vec3 operator/(const Vec3 &w) const;
    Vec3 operator/(number_t w) const;

    Vec3 operator-() const;

    number_t component(Axis axis) const;

    number_t sq() const;
    number_t magn() const;
    Vec3 norm() const;

    std::string debug_string() const;

    static number_t dot(const Vec3 &v, const Vec3 &w);
    static Vec3 cross(const Vec3 &v, const Vec3 &w);

    static Vec3 min(const Vec3 &v, const Vec3 &w);
    static Vec3 max(const Vec3 &v, const Vec3 &w);
};
