//
// Created by Leonard on 2025-12-27.
//

#pragma once

// config options:
// RES_X:               integer     (output image resolution, x)
// RES_Y:               integer     (output image resolution, y)
// SAMPLE_COUNT:        integer     (samples per pixel)
// MIN_CONTRIBUTION:    floating    (light ray contribution threshold)
// MAX_DEPTH:           integer     (reflection recursion limit)
// PRINT_PROGRESS:      bool        (print rendering progress?)
// DOUBLE_PRECISION:    bool        (use double instead of float?)

#ifndef RES_X
#define RES_X 1920
#endif

#ifndef RES_Y
#define RES_Y 1080
#endif

#ifndef SAMPLE_COUNT
#define SAMPLE_COUNT 20
#endif

#ifndef MIN_CONTRIBUTION
#define MIN_CONTRIBUTION 0.01
#endif

#ifndef MAX_DEPTH
#define MAX_DEPTH 100
#endif

#ifndef PRINT_PROGRESS
#define PRINT_PROGRESS true
#endif

#ifndef DOUBLE_PRECISION
#define DOUBLE_PRECISION true
#endif

#if DOUBLE_PRECISION
using number_t = double;
#else
using number_t = float;
#endif
