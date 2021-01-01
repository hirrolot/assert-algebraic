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

/**
 * @mainpage
 * A set of macros to dynamically assert certain algebraic properties of regular C functions.<br>
 *
 * All the documentation is located in assert_algebraic.h. See <a
 * href="https://github.com/Hirrolot/assert-algebraic">our official GitHub repository</a> for a
 * high-level overview.
 */

/**
 * @file
 * Algebraic assertions.
 */

#ifndef ASSERT_ALGEBRAIC_H
#define ASSERT_ALGEBRAIC_H

#include <assert.h>

/**
 * <a href="https://en.wikipedia.org/wiki/Logical_consequence">Logical implication</a>: \f$x
 * \Rightarrow y\f$.
 */
#define ASSERT_IMPLICATION(x, y)                                                                   \
    if (x) {                                                                                       \
        assert(y);                                                                                 \
    }                                                                                              \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Logical_equivalence">Logical equivalence</a>: \f$x
 * \Leftrightarrow y\f$.
 */
#define ASSERT_BIDIRECTIONAL_IMPLICATION(x, y)                                                     \
    ASSERT_IMPLICATION(x, y);                                                                      \
    ASSERT_IMPLICATION(y, x);                                                                      \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Reflexive_relation">Reflexivity</a>: \f$f(x, x)\f$.
 */
#define ASSERT_REFLEXIVE(f, x) assert(f(x, x))

/**
 * <a href="https://en.wikipedia.org/wiki/Reflexive_relation#Related_terms">Irreflexivity</a>:
 * \f$\neg f(x, x)\f$.
 */
#define ASSERT_IRREFLEXIVE(f, x) assert(!f(x, x))

/**
 * <a href="https://en.wikipedia.org/wiki/Symmetric_relation">Symmetricity</a>: \f$f(x, y)
 * \Leftrightarrow f(y, x)\f$.
 */
#define ASSERT_SYMMETRIC(f, x, y) ASSERT_BIDIRECTIONAL_IMPLICATION(f(x, y), f(y, x))

/**
 * <a href="https://en.wikipedia.org/wiki/Antisymmetric_relation">Antisymmetricity</a>: \f$f(x, y)
 * \land f(y, x) \Rightarrow eq(x, y)\f$.
 */
#define ASSERT_ANTISYMMETRIC(f, eq, x, y) ASSERT_IMPLICATION(f(x, y) && f(y, x), eq(x, y))

/**
 * <a href="https://en.wikipedia.org/wiki/Asymmetric_relation">Asymmetricity</a>: \f$f(x, y)
 * \Rightarrow \neg f(y, x)\f$.
 */
#define ASSERT_ASYMMETRIC(f, x, y) ASSERT_IMPLICATION(f(x, y), !f(y, x))

/**
 * <a href="https://en.wikipedia.org/wiki/Transitive_relation">Transitivity</a>: \f$f(x, y) \land
 * f(y, z) \Rightarrow f(x, z)\f$.
 */
#define ASSERT_TRANSITIVE(f, x, y, z) ASSERT_IMPLICATION(f(x, y) && f(y, z), f(x, z))

/**
 * <a href="https://en.wikipedia.org/wiki/Intransitivity#Antitransitivity">Antitransitivity</a>:
 * \f$f(x, y) \land f(y, z) \Rightarrow \neg f(x, z)\f$.
 */
#define ASSERT_ANTITRANSITIVE(f, x, y, z) ASSERT_IMPLICATION(f(x, y) && f(y, z), !f(x, z))

/**
 * <a href="https://en.wikipedia.org/wiki/Connex_relation">Connexity</a>: \f$f(x, y) \lor f(y,
 * x)\f$.
 */
#define ASSERT_CONNEXIVE(f, x, y) assert(f(x, y) || f(y, x))

/**
 * <a href="https://en.wikipedia.org/wiki/Connex_relation">Semiconnexity</a>: \f$f(x, y) \lor f(y,
 * x) \lor x = y\f$.
 */
#define ASSERT_SEMICONNEXIVE(f, eq, x, y) assert(f(x, y) || f(y, x) || eq(x, y))

/**
 * <a href="https://en.wikipedia.org/wiki/Bijection">Bijectivity</a>: \f$g(f(x)) = x\f$.
 */
#define ASSERT_BIJECTIVE(f, g, eq, x) assert(eq(g(f(x)), x))

/**
 * <a href="https://en.wikipedia.org/wiki/Involution_(mathematics)">Involutivity</a>: \f$f(f(x)) =
 * x\f$.
 */
#define ASSERT_INVOLUTIVE(f, eq, x) ASSERT_BIJECTIVE(f, f, eq, x)

/**
 * <a href="https://en.wikipedia.org/wiki/Idempotence">Idempotence</a>: \f$f(x, x) = x\f$.
 */
#define ASSERT_IDEMPOTENT(f, eq, x) assert(eq(f(x, x), x))

/**
 * <a href="https://en.wikipedia.org/wiki/Commutative_property">Commutativity</a>: \f$f(x, y) = f(y,
 * x)\f$.
 */
#define ASSERT_COMMUTATIVE(f, eq, x, y) assert(eq(f(x, y), f(y, x)))

/**
 * <a href="https://en.wikipedia.org/wiki/Associative_property">Associativity</a>: \f$f(f(x, y), z)
 * = f(x, f(y, z))\f$.
 */
#define ASSERT_ASSOCIATIVE(f, eq, x, y, z) assert(eq(f(f(x, y), z), f(x, f(y, z))))

/**
 * <a href="https://en.wikipedia.org/wiki/Distributive_property">Distributivity (left)</a>: \f$f1(x,
 * f2(y, z)) = f2(f1(x, y), f1(x, z))\f$.
 */
#define ASSERT_LEFT_DISTRIBUTIVE(f1, f2, eq, x, y, z)                                              \
    assert(eq(f1(x, f2(y, z)), f2(f1(x, y), f1(x, z))))

/**
 * <a href="https://en.wikipedia.org/wiki/Distributive_property">Distributivity (right)</a>:
 * \f$f1(f2(y, z), x) = f2(f1(y, x), f1(z, x))\f$.
 */
#define ASSERT_RIGHT_DISTRIBUTIVE(f1, f2, eq, x, y, z)                                             \
    assert(eq(f1(f2(y, z), x), f2(f1(y, x), f1(z, x))))

/**
 * <a href="https://en.wikipedia.org/wiki/Distributive_property">Distributivity (left and
 * right)</a>: \f$f1(x, f2(y, z)) = f2(f1(x, y), f1(x, z)) \land f1(f2(y, z), x) = f2(f1(y, x),
 * f1(z, x))\f$.
 */
#define ASSERT_DISTRIBUTIVE(f1, f2, eq, x, y, z)                                                   \
    ASSERT_LEFT_DISTRIBUTIVE(f1, f2, eq, x, y, z);                                                 \
    ASSERT_RIGHT_DISTRIBUTIVE(f1, f2, eq, x, y, z);                                                \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Identity_element">Identity element (left)</a>: \f$f(e, x)
 * = x\f$.
 */
#define ASSERT_LEFT_IDENTITY(f, eq, e, x) assert(eq(f(e, x), x))

/**
 * <a href="https://en.wikipedia.org/wiki/Identity_element">Identity element (right)</a>: \f$f(x, e)
 * = x\f$.
 */
#define ASSERT_RIGHT_IDENTITY(f, eq, e, x) assert(eq(f(x, e), x))

/**
 * <a href="https://en.wikipedia.org/wiki/Identity_element">Identity element (left and right)</a>:
 * \f$f(e, x) = f(x, e) = e\f$.
 */
#define ASSERT_IDENTITY(f, eq, e, x)                                                               \
    ASSERT_LEFT_IDENTITY(f, eq, e, x);                                                             \
    ASSERT_RIGHT_IDENTITY(f, eq, e, x);                                                            \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Absorbing_element">Zero element (left)</a>: \f$f(z, x) =
 * z\f$.
 */
#define ASSERT_LEFT_ZERO(f, eq, z, x) assert(eq(f(z, x), z))

/**
 * <a href="https://en.wikipedia.org/wiki/Absorbing_element">Zero element (left)</a>: \f$f(x, z) =
 * z\f$.
 */
#define ASSERT_RIGHT_ZERO(f, eq, z, x) assert(eq(f(x, z), z))

/**
 * <a href="https://en.wikipedia.org/wiki/Absorbing_element">Zero element (left and right)</a>:
 * \f$f(z, x) = f(x, z) = z\f$.
 */
#define ASSERT_ZERO(f, eq, z, x)                                                                   \
    ASSERT_LEFT_ZERO(f, eq, z, x);                                                                 \
    ASSERT_RIGHT_ZERO(f, eq, z, x);                                                                \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Preorder">Preorder</a>: a relation that is reflexive and
 * transitive.
 */
#define ASSERT_PREORDER(f, x, y, z)                                                                \
    ASSERT_REFLEXIVE(f, x);                                                                        \
    ASSERT_TRANSITIVE(f, x, y, z);                                                                 \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Partially_ordered_set#Formal_definition">Non-strict
 * partial order</a>: an antisymmetric preorder.
 */
#define ASSERT_PARTIAL_ORDER(f, eq, x, y, z)                                                       \
    ASSERT_PREORDER(f, x, y, z);                                                                   \
    ASSERT_ANTISYMMETRIC(f, eq, x, y);                                                             \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a
 * href="https://en.wikipedia.org/wiki/Partially_ordered_set#Strict_and_non-strict_partial_orders">Strict
 * partial order</a>: A relation that is irreflexive (implied by asymmetricity), transitive and
 * asymmetric.
 */
#define ASSERT_STRICT_PARTIAL_ORDER(f, x, y, z)                                                    \
    ASSERT_TRANSITIVE(f, x, y, z);                                                                 \
    ASSERT_ASYMMETRIC(f, x, y);                                                                    \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Total_order">Non-strict total order</a>: a relation that
 * is antisymmetric, transitive, and connexive.
 */
#define ASSERT_TOTAL_ORDER(f, eq, x, y, z)                                                         \
    ASSERT_ANTISYMMETRIC(f, eq, x, y);                                                             \
    ASSERT_TRANSITIVE(f, x, y, z);                                                                 \
    ASSERT_CONNEXIVE(f, x, y);                                                                     \
                                                                                                   \
    do {                                                                                           \
    } while (0)

/**
 * <a href="https://en.wikipedia.org/wiki/Total_order#Strict_total_order">Strict total order</a>: a
 * non-strict total order for which exactly one of \f$f(x, y)\f$, \f$f(y, x)\f$, and \f$x = y\f$
 * holds.
 */
#define ASSERT_STRICT_TOTAL_ORDER(f, eq, x, y, z)                                                  \
    ASSERT_STRICT_PARTIAL_ORDER(f, x, y, z);                                                       \
    ASSERT_SEMICONNEXIVE(f, eq, x, y);                                                             \
                                                                                                   \
    do {                                                                                           \
    } while (0)

#endif // ASSERT_ALGEBRAIC_H
