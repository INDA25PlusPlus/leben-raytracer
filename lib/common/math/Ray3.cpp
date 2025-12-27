//
// Created by Leonard on 2025-12-27.
//

#include "math/Ray3.hpp"

const Ray3 Ray3::X = {Vec3::ZERO, Vec3::X};
const Ray3 Ray3::Y = {Vec3::ZERO, Vec3::Y};
const Ray3 Ray3::Z = {Vec3::ZERO, Vec3::Z};

Ray3::Ray3(const Vec3 &from, const Vec3 &dir) : from(from), dir(dir) {}
