#!/usr/bin/env bash
set -euo pipefail

rm -f build/CMakeCache.txt
cmake -B build/
