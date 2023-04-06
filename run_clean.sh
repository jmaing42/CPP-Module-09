#!/bin/sh

set -e

find . \( -name "*.cpp.o" -o -name "*.cxx.o" -o -name "*.cc.o" -o -name "*.part.json" \) -delete
