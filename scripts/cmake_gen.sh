#!/usr/bin/env bash
set -euo pipefail

MODE=${1:-host}

case $MODE in
  host)
    rm -f build/CMakeCache.txt
    cmake -B build/
    ;;
  cuda)
    rm -f build/CMakeCache.txt
    cmake -DENABLE_CUDA_FEATURES=ON -B build/
    ;;
  *)
    >&2 echo "Invalid mode: '$MODE'"
    exit 1
    ;;
esac
