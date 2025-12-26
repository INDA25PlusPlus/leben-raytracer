#!/usr/bin/env bash
set -euo pipefail

TARGET=${1:-host}

case $TARGET in
  host)
    TARGET=leben_raytracer_host
    ;;
  cuda)
    TARGET=leben_raytracer_cuda
    ;;
  host_test)
    TARGET=leben_raytracer_host_test
    ;;
  cuda_test)
    TARGET=leben_raytracer_cuda_test
    ;;
  *)
    >&2 echo "Invalid target: '$TARGET'"
    exit 1
    ;;
esac

cmake --build build/ --target $TARGET
./build/$TARGET