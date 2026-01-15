//
// Created by Leonard on 2026-01-15.
//

#include "render/RenderBuffer.hpp"

#include <cmath>

#include "render/color.hpp"


RenderBuffer::RenderBuffer() :
    buffer() {}

void RenderBuffer::render(Scene const &scene, Matrix4x4 const &proj_matrix, number_t v_fov) {
    size_t index = 0;
    for (size_t j = 0; j < RES_Y; j++) {
        number_t v = static_cast<number_t>(j) / RES_Y;
        for (size_t i = 0; i < RES_X; i++) {
            number_t u = static_cast<number_t>(i) / RES_X;

            number_t corner_y = std::tan(v_fov * .5);

            constexpr number_t aspect_ratio = static_cast<number_t>(RES_X) / static_cast<number_t>(RES_Y);
            Vec2 corner = {aspect_ratio * corner_y, corner_y};
            Vec3 screen_space_dir = {
                corner.x * (2 * u - 1),
                corner.y * (2 * v - 1),
                1
            };

            Color3 result = Vec3::ZERO;

            Ray3 ray = proj_matrix.apply(Ray3(Vec3::ZERO, screen_space_dir.norm()));
            size_t depth = 0;
            Color3 contribution = Vec3::ONE;
            // we have if let Some(hit) = scene.ray_cast(ray) at home
            while (auto hit = scene.ray_cast(ray)) {
                auto material = hit->material;

                contribution = contribution * material.color;
                result = result + contribution * material.emissivity;

                contribution = contribution * material.reflectivity;
                if (contribution.max_component() < MIN_CONTRIBUTION)
                    break;

                // TODO reflection
                break;
            }

            buffer[index] = wrap(result, 1);

            index++;
        }
    }
}
