#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <mathvector/mathvector.hpp>

TEST_CASE("mathvector") {
    MathVector<2> proba1;
    CHECK(proba1.empty() == true);
    CHECK(proba1.getSize() == 0);
    proba1.push_back(5);
    CHECK(proba1.empty() == false);
    CHECK(proba1.getBack() == 5);
    CHECK(proba1.getFront() == 5);
    CHECK(proba1.getSize() == 1);
    proba1.push_back(3);
    CHECK(proba1.getBack() == 3);
    CHECK(proba1.getFront() == 5);
    CHECK(proba1.getSize() == 2);
    CHECK(proba1.at(0) == 5);
    CHECK(proba1.at(1) == 3);
    proba1.replace_at(0, 7);
    CHECK(proba1.getBack() == 3);
    CHECK(proba1.getFront() == 7);
    CHECK(proba1.getSize() == 2);
    CHECK(proba1.at(0) == 7);
    CHECK(proba1.at(1) == 3);

    MathVector<2> proba2;
    CHECK((proba1 == proba2) == false);
    CHECK((proba1 != proba2) == true);
    proba2.push_back(7);
    proba2.push_back(5);
    CHECK((proba1 == proba2) == true);
    CHECK((proba1 != proba2) == false);
}