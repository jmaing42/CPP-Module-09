#!/bin/sh

set -e

ls -1 | grep "^ex[[:digit:]]\\+\$" | while IFS= read -r line
do
  (cd "$line" && make "$1")
done
