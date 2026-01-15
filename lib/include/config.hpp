//
// Created by Leonard on 2025-12-27.
//

#pragma once

// config options:
// RES_X:               integer
// RES_Y:               integer
// MIN_CONTRIBUTION:    floating
// MAX_DEPTH:           integer
// DOUBLE_PRECISION:    bool

#ifndef RES_X
#define RES_X 1920
#endif

#ifndef RES_Y
#define RES_Y 1080
#endif

#ifndef MIN_CONTRIBUTION
#define MIN_CONTRIBUTION 0.01
#endif

#ifndef MAX_DEPTH
#define MAX_DEPTH 100
#endif

#ifdef DOUBLE_PRECISION
using number_t = double;
#else
using number_t = float;
#endif
