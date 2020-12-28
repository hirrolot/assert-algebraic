#!/bin/bash

find assert_algebraic.h examples -iname *.h -o -iname *.c -path examples/build -prune | xargs clang-format -i
