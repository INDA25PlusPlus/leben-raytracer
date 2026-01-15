//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include <memory>
#include <vector>

#include "render/color.hpp"
#include "scene/SceneObject.hpp"

class Scene {
    std::vector<std::unique_ptr<SceneObject>> objects;

public:
    Scene();

    void add_object(std::unique_ptr<SceneObject> &&object);

    Color3 ray_cast(Ray3 const &ray);
};
