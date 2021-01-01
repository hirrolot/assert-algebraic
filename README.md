# assert-algebraic

[![CI](https://github.com/Hirrolot/assert-algebraic/workflows/C/C++%20CI/badge.svg)](https://github.com/Hirrolot/assert-algebraic/actions)

A set of macros to dynamically assert certain algebraic properties of regular C functions.

[[ `examples/demo.c` ](examples/demo.c)] [ [Playground >>](https://godbolt.org/z/8h5Ebr) ]

``` c
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
```

To install assert-algebraic, just copy [ `assert_algebraic.h` ] to your code base (or use [Git submodules]) and then `#include <assert_algebraic.h>` where necessary.

[Git submodules]: https://git-scm.com/book/en/v2/Git-Tools-Submodules

## Purpose

The goal is to implement property-based testing in pure C. (Though this library is not intended as a complete property-based testing framework: test cases generation is not planned, for example.)

## Available properties

To see the macro definitions, go to [ `assert_algebraic.h` ].

| Macro | Property |
|----------|----------|
| `ASSERT_IMPLICATION(x, y)` | [Logical implication](https://en.wikipedia.org/wiki/Logical_consequence) |
| `ASSERT_BIDIRECTIONAL_IMPLICATION(x, y)` | [Logical equivalence](https://en.wikipedia.org/wiki/Logical_equivalence) |
| `ASSERT_REFLEXIVE(f, x)` | [Reflexivity](https://en.wikipedia.org/wiki/Reflexive_relation) |
| `ASSERT_IRREFLEXIVE(f, eq, x, y)` | [Irreflexivity](https://en.wikipedia.org/wiki/Reflexive_relation#Related_terms) |
| `ASSERT_SYMMETRIC(f, x, y)` | [Symmetricity](https://en.wikipedia.org/wiki/Symmetric_relation) |
| `ASSERT_ANTISYMMETRIC(f, eq, x, y)` | [Antisymmetricity](https://en.wikipedia.org/wiki/Antisymmetric_relation) |
| `ASSERT_ASYMMETRIC(f, eq, x, y)` | [Asymmetricity](https://en.wikipedia.org/wiki/Asymmetric_relation) |
| `ASSERT_BIJECTIVE(f, inverse_f, eq, x)` | [Bijection](https://en.wikipedia.org/wiki/Bijection) |
| `ASSERT_INVOLUTIVE(f, eq, x)` | [Involution](https://en.wikipedia.org/wiki/Involution_(mathematics)) |
| `ASSERT_IDEMPOTENT(f, eq, x)` | [Idempotence](https://en.wikipedia.org/wiki/Idempotence) |
| `ASSERT_COMMUTATIVE(f, eq, x, y)` | [Commutativity](https://en.wikipedia.org/wiki/Commutative_property) |
| `ASSERT_ASSOCIATIVE(f, eq, x, y, z)` | [Associativity](https://en.wikipedia.org/wiki/Associative_property) |
| `ASSERT_LEFT_DISTRIBUTIVE(f1, f2, eq, x, y, z)` | [Distributivity](https://en.wikipedia.org/wiki/Distributive_property) (left) |
| `ASSERT_RIGHT_DISTRIBUTIVE(f1, f2, eq, x, y, z)` | [Distributivity](https://en.wikipedia.org/wiki/Distributive_property) (right)  |
| `ASSERT_DISTRIBUTIVE(f1, f2, eq, x, y, z)` | [Distributivity](https://en.wikipedia.org/wiki/Distributive_property) (both left and right) |
| `ASSERT_LEFT_IDENTITY(f, eq, e, x)` | [Identity element](https://en.wikipedia.org/wiki/Identity_element) (left) |
| `ASSERT_RIGHT_IDENTITY(f, eq, e, x)` | [Identity element](https://en.wikipedia.org/wiki/Identity_element) (right) |
| `ASSERT_IDENTITY(f, eq, e, x)` | [Identity element](https://en.wikipedia.org/wiki/Identity_element) (both left and right) |
| `ASSERT_LEFT_ZERO(f, eq, z, x)` | [Zero element](https://en.wikipedia.org/wiki/Absorbing_element) (left) |
| `ASSERT_RIGHT_ZERO(f, eq, z, x)` | [Zero element](https://en.wikipedia.org/wiki/Absorbing_element) (right) |
| `ASSERT_ZERO(f, eq, z, x)` | [Zero element](https://en.wikipedia.org/wiki/Absorbing_element) (both left and right) |

## Projects using assert-algebraic

 - [Hirrolot/slice99](https://github.com/Hirrolot/slice99) -- Array slicing for C99.

[ `assert_algebraic.h` ]: assert_algebraic.h
