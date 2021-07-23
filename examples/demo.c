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
