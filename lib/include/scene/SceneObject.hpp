//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "math/Ray3.hpp"
#include "render/Material.hpp"

class SceneObject {
    Material const &material;

public:
    explicit SceneObject(Material const &material);

    virtual ~SceneObject() = default;

    virtual bool ray_cast(Ray3 const &ray, double &min_dist, Vec3 &pos, Vec3 &normal) const = 0;
};
