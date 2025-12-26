#!/usr/bin/env bash
set -euo pipefail

MODE=${1:-}

case $MODE in
  cpu_only)
    rm -f build/CMakeCache.txt
    cmake -B build/
    ;;
  cuda)
    rm -f build/CMakeCache.txt
    cmake -DENABLE_CUDA=ON -B build/
    ;;
  *)
    >&2 echo "Expected argument: 'cpu_only' or 'cuda'"
    exit 1
    ;;
esac
