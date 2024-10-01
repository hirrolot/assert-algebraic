# assert-algebraic

[![CI](https://github.com/hirrolot/assert-algebraic/workflows/C/C++%20CI/badge.svg)](https://github.com/hirrolot/assert-algebraic/actions)

A set of macros to dynamically assert certain algebraic properties of regular C functions.

[[ `examples/demo.c` ](examples/demo.c)] [ [Playground >>](https://godbolt.org/z/Y377GY) ]

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
    ASSERT_EQUIVALENCE(eq, 1, 1, 3);

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

 - [Logical implication](https://en.wikipedia.org/wiki/Logical_consequence)
 - [Logical equivalence](https://en.wikipedia.org/wiki/Logical_equivalence)
 - [Reflexivity](https://en.wikipedia.org/wiki/Reflexive_relation)
 - [Irreflexivity](https://en.wikipedia.org/wiki/Reflexive_relation#Related_terms)
 - [Symmetricity](https://en.wikipedia.org/wiki/Symmetric_relation)
 - [Antisymmetricity](https://en.wikipedia.org/wiki/Antisymmetric_relation)
 - [Asymmetricity](https://en.wikipedia.org/wiki/Asymmetric_relation)
 - [Transitivity](https://en.wikipedia.org/wiki/Transitive_relation)
 - [Antitransitivity](https://en.wikipedia.org/wiki/Intransitivity#Antitransitivity)
 - [Equivalence](https://en.wikipedia.org/wiki/Equivalence_relation)
 - [Connexity](https://en.wikipedia.org/wiki/Connex_relation)
 - [Semiconnexity](https://en.wikipedia.org/wiki/Connex_relation)
 - [Bijectivity](https://en.wikipedia.org/wiki/Bijection)
 - [Involutivity](https://en.wikipedia.org/wiki/Involution_(mathematics))
 - [~~Impotence~~ Idempotence](https://en.wikipedia.org/wiki/Idempotence)
 - [Commutativity](https://en.wikipedia.org/wiki/Commutative_property)
 - [Associativity](https://en.wikipedia.org/wiki/Associative_property)
 - [Distributivity](https://en.wikipedia.org/wiki/Distributive_property)
 - [Identity element](https://en.wikipedia.org/wiki/Identity_element)
 - [Zero element](https://en.wikipedia.org/wiki/Absorbing_element)
 - [Preorder](https://en.wikipedia.org/wiki/Preorder)
 - [Partial order](https://en.wikipedia.org/wiki/Partially_ordered_set#Formal_definition) (strict and non-strict)
 - [Total order](https://en.wikipedia.org/wiki/Total_order) (strict and non-strict)

## Projects using assert-algebraic

 - [hirrolot/slice99](https://github.com/hirrolot/slice99) -- Array slicing for C99.

[ `assert_algebraic.h` ]: assert_algebraic.h

## Release procedure

 1. Update the `PROJECT_NUMBER` field in `Doxyfile`.
 2. Run `doxygen` to generate the newest docs.
 3. Update `CHANGELOG.md`.
 4. Release the project in [GitHub Releases].

[GitHub Releases]: https://github.com/hirrolot/slice99/releases
