//
// Created by Leonard on 2026-01-15.
//

#include "render/RenderBuffer.hpp"

#include <cmath>
#include <filesystem>
#include <format>

#include "img/stb_image_write.h"
#include "render/color.hpp"


RenderBuffer::RenderBuffer() :
    buffer() {}

void RenderBuffer::render(Scene const &scene, Matrix4x4 const &proj_matrix, number_t v_fov, std::random_device &rand) {
    std::mt19937_64 rng{rand()};
    std::uniform_real_distribution<number_t> uniform_dist(0., 1.);
    std::normal_distribution<number_t> normal_dist(0., 1.);

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

                result = result + contribution * material.emissive_color * material.emissivity;

                contribution = contribution * material.reflectivity;
                if (contribution.max_component() < MIN_CONTRIBUTION)
                    break;

                Vec3 normal = hit->normal;

                if (uniform_dist(rng) > material.roughness) {
                    // specular

                    Vec3 comp = normal * Vec3::dot(normal, ray.dir);
                    Vec3 dir = ray.dir - comp * 2;
                    ray = {
                        hit->pos + dir * .00001,
                        dir
                    };
                    contribution = contribution * material.specular_color;
                } else {
                    // diffuse

                    // random point on semisphere
                    Vec3 dir = {
                        normal_dist(rng),
                        normal_dist(rng),
                        normal_dist(rng),
                    };
                    if (Vec3::dot(dir, normal) < 0)
                        dir = -dir;
                    dir = dir.norm();

                    ray = {
                        hit->pos + dir * .00001,
                        dir
                    };
                    contribution = contribution * material.diffuse_color;
                }

                if (++depth >= MAX_DEPTH)
                    break;
            }

            buffer[index] = wrap(result, 1);

            index++;
        }
    }
}

std::string get_valid_path(const std::filesystem::path &path) {
    const std::string stem = path.stem().string();
    const std::string extension = path.extension().string();
    const std::string parent = path.has_parent_path()
        ? path.parent_path().string() + "/"
        : "";

    int counter = 0;
    std::string complete_path = path.string();
    while (std::filesystem::exists(complete_path)) {
        complete_path = std::format("{}{}-{}{}", parent, stem, counter, extension);
        counter++;
    }
    return complete_path;
}

std::string RenderBuffer::write_png(std::string const &output_path) const {
    const std::filesystem::path path(output_path);
    if (path.has_parent_path())
        create_directories(path.parent_path());
    const std::string valid_path = get_valid_path(path);

    // use external library
    stbi_write_png(valid_path.c_str(), RES_X, RES_Y, 4, buffer.data(), 0);
    return valid_path;
}
