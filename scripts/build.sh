#!/usr/bin/env bash
set -euo pipefail

DIR="$(dirname "$0")"

TARGET=${1:-leben_raytracer}

cmake --build "$DIR/../build/" --target $TARGET
