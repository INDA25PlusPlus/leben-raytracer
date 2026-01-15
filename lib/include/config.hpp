//
// Created by Leonard on 2025-12-27.
//

#pragma once

// config options:
// RES_X:               size_t
// RES_Y:               size_t
// SAMPLE_GRID_SIZE:    size_t
// DOUBLE_PRECISION:    bool

#ifndef RES_X
#define RES_X 1920
#endif

#ifndef RES_Y
#define RES_Y 1080
#endif

#ifndef SAMPLE_GRID_SIZE
#define SAMPLE_GRID_SIZE 1
#endif

#ifdef DOUBLE_PRECISION
using number_t = double;
#else
using number_t = float;
#endif
