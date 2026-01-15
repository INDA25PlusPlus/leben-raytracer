//
// Created by Leonard on 2026-01-15.
//

#include "scene/Scene.hpp"


Scene::Scene() {}

void Scene::add_object(std::unique_ptr<SceneObject> &&object) {
    objects.push_back(std::move(object));
}

std::optional<HitInfo> Scene::ray_cast(Ray3 const &ray) const {
    std::optional<HitInfo> hit;
    for (auto &object : objects) {
        object->ray_cast(ray, hit);
    }
    return hit;
}
