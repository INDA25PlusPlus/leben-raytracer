//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "math/Vec3.hpp"

struct Material {
    Vec3 const color;
    number_t const reflectivity;
    number_t const emissivity;
    number_t const roughness;
};
