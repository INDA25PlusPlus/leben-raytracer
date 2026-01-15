//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include <array>
#include <cstdint>

#include "config.hpp"
#include "../scene/Scene.hpp"
#include "math/Matrix4x4.hpp"


#define BUFFER_SIZE (RES_X * RES_Y)

class RenderBuffer {
    std::array<uint32_t, BUFFER_SIZE> buffer;

public:
    RenderBuffer();

    void render(Scene const &scene, Matrix4x4 const &proj_matrix, number_t v_fov);

    std::string write_png(std::string const &output_path) const;
};
