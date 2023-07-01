#!/bin/bash
# modified code taken from
# https://stackoverflow.com/a/65988393/8968308
# original author: https://stackoverflow.com/users/314290/mikhail

THIS_PATH="$(realpath "$0")"
THIS_DIR="$(dirname "$THIS_PATH")"

FILE_LIST="$(find "." -not -path './build/*' | grep -E ".*(\.ino|\.cpp|\.c|\.h|\.hpp|\.hh)$")"

echo -e "Files found to format = \n\"\"\"\n$FILE_LIST\n\"\"\""

clang-format --verbose -i --style=google $FILE_LIST