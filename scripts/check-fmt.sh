#!/bin/bash

./run-clang-format/run-clang-format.py \
    --exclude examples/build \
    -r assert_algebraic.h examples
