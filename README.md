# assert-algebraic

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
