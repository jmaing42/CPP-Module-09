#!/bin/sh

set -e

find . -name "*.cpp" -o -name "*.cxx" -o -name "*.cc" | while IFS= read -r line
do
  clang -Wall -Wextra -Werror -std=c++98 -pedantic -c "$line" -o "$line.o" -MJ "$line.part.json"
done
