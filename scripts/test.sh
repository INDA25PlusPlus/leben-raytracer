#!/usr/bin/env bash
set -euo pipefail

DIR="$(dirname "$0")"

TARGET=leben_raytracer_test

bash "$DIR/build.sh" $TARGET
"$DIR/../build/$TARGET"
