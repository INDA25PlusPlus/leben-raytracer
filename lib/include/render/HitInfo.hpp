//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "Material.hpp"
#include "math/Vec3.hpp"


struct HitInfo {
    number_t const distance;
    Vec3 const pos;
    Vec3 const normal;
    Material const &material;
};
