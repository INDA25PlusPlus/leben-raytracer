#!/usr/bin/env bash
set -euo pipefail

TARGET=leben_raytracer_test

bash ./scripts/build.sh $TARGET
./build/$TARGET