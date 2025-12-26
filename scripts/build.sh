#!/usr/bin/env bash
set -euo pipefail

TARGET=${1:-leben_raytracer}

cmake --build build/ --target $TARGET