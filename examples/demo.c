/*
 * MIT License
 *
 * Copyright (c) 2020 Temirkhan Myrzamadi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 * associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 * NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <assert_algebraic.h>

#include <stdbool.h>

static bool compare_ints(int x, int y);
static int add(int x, int y);
static int mul(int x, int y);
static int neg(int x);
static int id(int x);

int main(void) {
    ASSERT_IMPLICATION(true && false, false);
    ASSERT_BIDIRECTIONAL_IMPLICATION(true, true);

    ASSERT_REFLEXIVE(compare_ints, 3);
    ASSERT_SYMMETRIC(compare_ints, 4, 5);
    ASSERT_TRANSITIVE(compare_ints, 6, 7, 8);

    ASSERT_BIJECTIVE(id, id, compare_ints, 123);
    ASSERT_INVOLUTIVE(neg, compare_ints, 123);

    ASSERT_COMMUTATIVE(add, compare_ints, 1, 2);
    ASSERT_ASSOCIATIVE(add, compare_ints, 1, 2, 3);
    ASSERT_DISTRIBUTIVE(mul, add, compare_ints, 1, 2, 3);

    ASSERT_IDEMPOTENT(mul, compare_ints, 1);

    ASSERT_IDENTITY(add, compare_ints, 0, 123);
    ASSERT_ZERO(mul, compare_ints, 0, 123);
}

static bool compare_ints(int x, int y) {
    return x == y;
}

static int add(int x, int y) {
    return x + y;
}

static int mul(int x, int y) {
    return x * y;
}

static int neg(int x) {
    return -x;
}

static int id(int x) {
    return x;
}
