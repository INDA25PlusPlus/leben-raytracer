#!/usr/bin/env bash
set -euo pipefail

SHOW_MODE=${1:-}

TARGET=leben_raytracer
bash ./scripts/build.sh $TARGET

OUTPUT=$(stdbuf -oL ./build/$TARGET | tee /dev/tty)

OUTPUT_PATH=$(echo "$OUTPUT" | tail --lines 1)
if [[ -f $OUTPUT_PATH ]]; then
  case $SHOW_MODE in
    kitty)
      kitty +kitten icat "$OUTPUT_PATH"
      ;;
    chafa)
      chafa "$OUTPUT_PATH"
      ;;
    "")
      ;;
    *)
      >&2 echo "Invalid show mode $SHOW_MODE"
      exit 1
      ;;
  esac
else
  >&2 echo "No image generated!"
  exit 1
fi
