//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "color.hpp"
#include "math/Vec3.hpp"

struct HitInfo;

struct Material {
    Color3 const emissive_color;
    number_t const emissivity;

    Color3 const diffuse_color;
    Color3 const specular_color;

    number_t const reflectivity;
    number_t const roughness;
};
