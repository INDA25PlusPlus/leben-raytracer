#!/usr/bin/env bash
set -euo pipefail

SHOW_MODE=${1:-}

DIR="$(dirname "$0")"

TARGET=leben_raytracer
bash "$DIR"/build.sh $TARGET

exec 3>&1
OUTPUT=$(stdbuf -oL "$DIR/../build/$TARGET" | tee >(cat - >&3))

OUTPUT_PATH=$(echo "$OUTPUT" | tail --lines 1)
if [[ -f $OUTPUT_PATH ]]; then
  case $SHOW_MODE in
    kitty)
      kitty +kitten icat "$OUTPUT_PATH"
      ;;
    chafa)
      chafa "$OUTPUT_PATH"
      ;;
    path)
      echo "$OUTPUT_PATH"
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
