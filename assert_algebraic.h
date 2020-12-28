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

// GitHub: https://github.com/Hirrolot/assert-algebraic.

#ifndef ASSERT_ALGEBRAIC_H
#define ASSERT_ALGEBRAIC_H

#include <assert.h>

#define ASSERT_IMPLICATION(x, y)                                                                   \
    if (x) {                                                                                       \
        assert(y);                                                                                 \
    }                                                                                              \
                                                                                                   \
    do {                                                                                           \
    } while (0)

#define ASSERT_BIDIRECTIONAL_IMPLICATION(x, y)                                                     \
    ASSERT_IMPLICATION(x, y);                                                                      \
    ASSERT_IMPLICATION(y, x);                                                                      \
                                                                                                   \
    do {                                                                                           \
    } while (0)

#define ASSERT_REFLEXIVE(f, x)        assert(f(x, x))
#define ASSERT_SYMMETRIC(f, x, y)     ASSERT_BIDIRECTIONAL_IMPLICATION(f(x, y), f(y, x))
#define ASSERT_TRANSITIVE(f, x, y, z) ASSERT_IMPLICATION(f(x, y) && f(y, z), f(x, z))

#define ASSERT_BIJECTIVE(f, inverse_f, eq, x) assert(eq(inverse_f(f(x)), x))
#define ASSERT_INVOLUTIVE(f, eq, x)           ASSERT_BIJECTIVE(f, f, eq, x)
#define ASSERT_IDEMPOTENT(f, eq, x)           assert(eq(f(x, x), x))

#define ASSERT_COMMUTATIVE(f, eq, x, y)    assert(eq(f(x, y), f(y, x)))
#define ASSERT_ASSOCIATIVE(f, eq, x, y, z) assert(eq(f(f(x, y), z), f(x, f(y, z))))

#define ASSERT_LEFT_DISTRIBUTIVE(f1, f2, eq, x, y, z)                                              \
    assert(eq(f1(x, f2(y, z)), f2(f1(x, y), f1(x, z))))
#define ASSERT_RIGHT_DISTRIBUTIVE(f1, f2, eq, x, y, z)                                             \
    assert(eq(f1(f2(y, z), x), f2(f1(y, x), f1(z, x))))
#define ASSERT_DISTRIBUTIVE(f1, f2, eq, x, y, z)                                                   \
    ASSERT_LEFT_DISTRIBUTIVE(f1, f2, eq, x, y, z);                                                 \
    ASSERT_RIGHT_DISTRIBUTIVE(f1, f2, eq, x, y, z);                                                \
                                                                                                   \
    do {                                                                                           \
    } while (0)

#define ASSERT_LEFT_IDENTITY(f, eq, e, x)  assert(eq(f(e, x), x))
#define ASSERT_RIGHT_IDENTITY(f, eq, e, x) assert(eq(f(x, e), x))
#define ASSERT_IDENTITY(f, eq, e, x)                                                               \
    ASSERT_LEFT_IDENTITY(f, eq, e, x);                                                             \
    ASSERT_RIGHT_IDENTITY(f, eq, e, x);                                                            \
                                                                                                   \
    do {                                                                                           \
    } while (0)

#define ASSERT_LEFT_ZERO(f, eq, z, x)  assert(eq(f(z, x), z))
#define ASSERT_RIGHT_ZERO(f, eq, z, x) assert(eq(f(x, z), z))
#define ASSERT_ZERO(f, eq, z, x)                                                                   \
    ASSERT_LEFT_ZERO(f, eq, z, x);                                                                 \
    ASSERT_RIGHT_ZERO(f, eq, z, x);                                                                \
                                                                                                   \
    do {                                                                                           \
    } while (0)

#endif // ASSERT_ALGEBRAIC_H
