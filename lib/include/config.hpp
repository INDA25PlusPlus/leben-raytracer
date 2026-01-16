//
// Created by Leonard on 2025-12-27.
//

#pragma once

// config options:
// RES_X:               integer
// RES_Y:               integer
// SAMPLE_COUNT:        integer
// MIN_CONTRIBUTION:    floating
// MAX_DEPTH:           integer
// PRINT_PROGRESS:      bool
// DOUBLE_PRECISION:    bool

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

#ifdef DOUBLE_PRECISION
using number_t = double;
#else
using number_t = float;
#endif
