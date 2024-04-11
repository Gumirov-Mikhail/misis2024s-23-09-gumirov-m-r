#include <stackarr/stackarr.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("stackarr") {
    StackArr proba1;
    Complex complex(2, 3);
    CHECK(proba1.IsEmpty() == true);
    proba1.Push(complex);
    CHECK(proba1.IsEmpty() == false);
    CHECK(proba1.Top() == Complex(2, 3));
    StackArr proba2(proba1);
    CHECK(proba1.IsEmpty() == false);
    CHECK(proba1.Top() == Complex(2, 3));
    CHECK(proba2.IsEmpty() == false);
    CHECK(proba2.Top() == Complex(2, 3));
    StackArr proba3(std::move(proba2));
    CHECK(proba3.IsEmpty() == false);
    CHECK(proba3.Top() == Complex(2, 3));
    CHECK(proba2.IsEmpty() == true);
}