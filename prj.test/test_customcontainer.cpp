#include <customcontainer/customcontainer.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("Container") {
    CustomContainer a;
    a.add(5);
    a.add(6);
    a.add(7);
    a.add(8);
    CHECK(a.contains(5));
    CHECK(a.contains(6));
    CHECK(a.contains(7));
    CHECK(a.contains(8));
    CustomContainer b;
    b.add(5);
    b.add(6);
    b.add(7);
    b.add(8);
    CHECK(a == b);
    b.add(9);
    CHECK(!(a == b));
}