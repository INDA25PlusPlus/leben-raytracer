//
// Created by Leonard on 2025-12-27.
//

#include "math/Vec3.hpp"

#include <cmath>
#include <format>
#include <bits/max_size_type.h>

const Vec3 Vec3::ZERO = {0, 0, 0};
const Vec3 Vec3::ONE = {1, 1, 1,};
const Vec3 Vec3::X = {1, 0, 0};
const Vec3 Vec3::Y = {0, 1, 0};
const Vec3 Vec3::Z = {0, 0, 1};
const Vec3 Vec3::MIN = Vec3{std::numeric_limits<number_t>::min()};
const Vec3 Vec3::MAX = Vec3{std::numeric_limits<number_t>::max()};

Vec3::Vec3(number_t x, number_t y, number_t z) : x(x), y(y), z(z) {}

Vec3::Vec3(Vec2 xy, number_t z) : x(xy.x), y(xy.y), z(z) {}

Vec3::Vec3(number_t x, Vec2 yz) : x(x), y(yz.x), z(yz.y) {}

Vec3::Vec3(number_t xyz) : x(xyz), y(xyz), z(xyz) {}

Vec3 Vec3::operator+(const Vec3 &w) const {
    return {x + w.x, y + w.y, z + w.z};
}

Vec3 Vec3::operator+(number_t w) const {
    return {x + w, y + w, z + w};
}

Vec3 Vec3::operator-(const Vec3 &w) const {
    return {x - w.x, y - w.y, z - w.z};
}

Vec3 Vec3::operator-(number_t w) const {
    return {x - w, y - w, z - w};
}

Vec3 Vec3::operator*(const Vec3 &w) const {
    return {x * w.x, y * w.y, z * w.z};
}

Vec3 Vec3::operator*(number_t w) const {
    return {x * w, y * w, z * w};
}

Vec3 Vec3::operator/(const Vec3 &w) const {
    return {x / w.x, y / w.y, z / w.z};
}

Vec3 Vec3::operator/(number_t w) const {
    return {x / w, y / w, z / w};
}

Vec3 Vec3::operator-() const {
    return {-x, -y, -z};
}

number_t Vec3::component(Axis axis) const {
    switch (axis) {
        case Axis::X:
            return x;
        case Axis::Y:
            return y;
        default:
            return z;
    }
}

number_t Vec3::max_component() const {
    return std::max(std::max(x, y), z);
}

number_t Vec3::sq() const {
    return x*x + y*y + z*z;
}

number_t Vec3::magn() const {
    return std::sqrt(x*x + y*y + z*z);
}

Vec3 Vec3::norm() const {
    return *this / magn();
}

std::string Vec3::debug_string() const {
    return std::format("({:12.4f}, {:12.4f}, {:12.4f})", x, y, z);
}

number_t Vec3::dot(const Vec3 &v, const Vec3 &w) {
    return v.x * w.x + v.y * w.y + v.z * w.z;
}

Vec3 Vec3::cross(const Vec3 &v, const Vec3 &w) {
    return {
        v.y * w.z - v.z * w.y,
        v.z * w.x - v.x * w.z,
        v.x * w.y - v.y * w.x};
}

Vec3 Vec3::min(const Vec3 &v, const Vec3 &w) {
    return {std::min(v.x, w.x), std::min(v.y, w.y), std::min(v.z, w.z)};
}

Vec3 Vec3::max(const Vec3 &v, const Vec3 &w) {
    return {std::max(v.x, w.x), std::max(v.y, w.y), std::max(v.z, w.z)};
}
