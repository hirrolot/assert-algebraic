# assert-algebraic
[![CI](https://github.com/Hirrolot/assert-algebraic/workflows/C/C++%20CI/badge.svg)](https://github.com/Hirrolot/assert-algebraic/actions)

A set of macros to dynamically assert certain algebraic properties of regular C functions.

[[`examples/demo.c`](examples/demo.c)] [ [Playground >>](https://godbolt.org/z/TWWe73) ]
```c
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
```

To install assert-algebraic, just copy [`assert_algebraic.h`] to your code base (or use [Git submodules]) and then `#include <assert_algebraic.h>` where necessary.

[Git submodules]: https://git-scm.com/book/en/v2/Git-Tools-Submodules

## Purpose

The goal is to implement property-based testing in pure C. (Though this library is not intended as a complete property-based testing framework: test cases generation is not planned, for example.)

## Available properties

To see the macro definitions, go to [`assert_algebraic.h`].

| Macro | Property |
|----------|----------|
| `ASSERT_IMPLICATION(x, y)` | [Logical implication](https://en.wikipedia.org/wiki/Logical_consequence) |
| `ASSERT_BIDIRECTIONAL_IMPLICATION(x, y)` | [Logical equivalence](https://en.wikipedia.org/wiki/Logical_equivalence) |
| `ASSERT_REFLEXIVE(f, x)` | [Reflexivity](https://en.wikipedia.org/wiki/Reflexive_relation) |
| `ASSERT_SYMMETRIC(f, x, y)` | [Symmetricity](https://en.wikipedia.org/wiki/Symmetric_relation) |
| `ASSERT_BIJECTIVE(f, inverse_f, eq, x)` | [Bijection](https://en.wikipedia.org/wiki/Bijection) |
| `ASSERT_INVOLUTIVE(f, eq, x)` | [Involution](https://en.wikipedia.org/wiki/Involution_(mathematics)) |
| `ASSERT_IDEMPOTENT(f, eq, x)` | [~~Impotence~~ Idempotence](https://en.wikipedia.org/wiki/Idempotence) |
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

[`assert_algebraic.h`]: assert_algebraic.h
