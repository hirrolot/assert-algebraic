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

static bool eq(int x, int y) { return x == y; }
static bool lesser(int x, int y) { return x < y; }
static bool lesser_eq(int x, int y) { return x <= y; }
static int  add(int x, int y) { return x + y; }
static int  mul(int x, int y) { return x * y; }
static int  neg(int x) { return -x; }
static int  id(int x) { return x; }

int main(void) {
    ASSERT_IMPLICATION(true && false, false);
    ASSERT_BIDIRECTIONAL_IMPLICATION(true, true);

    ASSERT_REFLEXIVE(eq, 3);
    ASSERT_SYMMETRIC(eq, 4, 5);
    ASSERT_TRANSITIVE(eq, 6, 7, 8);

    ASSERT_BIJECTIVE(id, id, eq, 123);
    ASSERT_INVOLUTIVE(neg, eq, 123);

    ASSERT_COMMUTATIVE(add, eq, 1, 2);
    ASSERT_ASSOCIATIVE(add, eq, 1, 2, 3);
    ASSERT_DISTRIBUTIVE(mul, add, eq, 1, 2, 3);

    ASSERT_IDEMPOTENT(mul, eq, 1);

    ASSERT_IDENTITY(add, eq, 0, 123);
    ASSERT_ZERO(mul, eq, 0, 123);

    ASSERT_PREORDER(lesser_eq, 1, 2, 3);

    ASSERT_PARTIAL_ORDER(lesser_eq, eq, 1, 2, 3);
    ASSERT_STRICT_PARTIAL_ORDER(lesser, 1, 1, 3);
    ASSERT_TOTAL_ORDER(lesser_eq, eq, 1, 1, 3);
    ASSERT_STRICT_TOTAL_ORDER(lesser, eq, 1, 1, 3);
}
