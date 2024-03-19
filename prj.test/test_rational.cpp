#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.hpp>

TEST_CASE("rational constructor") {
    Rational r_pusto;
    CHECK(0 == r_pusto.num());
    CHECK(1 == r_pusto.den());
    Rational r_num(3);
    CHECK(3 == r_num.num());
    CHECK(1 == r_num.den());
    Rational r_otriz(2, -3);
    CHECK(-2 == r_otriz.num());
    CHECK(3 == r_otriz.den());
    Rational r_big(6, 9);
    CHECK(2 == r_big.num());
    CHECK(3 == r_big.den());
    Rational r_copy(r_big);
    CHECK(2 == r_copy.num());
    CHECK(3 == r_copy.den());
    CHECK_THROWS(void(Rational(1,0)));
}

TEST_CASE("Sravnenie") {
    Rational r_num1{2, 3};
    Rational r_num2{4, 5};
    CHECK((r_num1 == r_num2) == false);
    CHECK((r_num1 != r_num2) == true);
    CHECK((r_num1 > r_num2) == false);
    CHECK((r_num1 < r_num2) == true);
    CHECK((r_num1 >= r_num2) == false);
    CHECK((r_num1 <= r_num2) == true);
}

TEST_CASE("mathematics") {
    Rational r_num1{2, 3};
    Rational r_num2{4, 5};
    CHECK((r_num1 + r_num2) == Rational{22, 15});
    CHECK((r_num1 - r_num2) == Rational{-2, 15});
    CHECK((r_num1 * r_num2) == Rational{8, 15});
    CHECK((r_num1 / r_num2) == Rational{10, 12});
    CHECK((r_num1++) == Rational{2, 3});
    CHECK((++r_num1) == Rational{8, 3});
    CHECK((r_num2--) == Rational{4, 5});
    CHECK((--r_num2) == Rational{-6, 5});
    Rational r_num3{5, 6};
    r_num3 = -r_num3;
    CHECK(-5 == r_num3.num());
    CHECK(6 == r_num3.den());
}

TEST_CASE("Rational input/output") {
    Rational t{1, 2};
    std::ostringstream output;
    output << t;
    CHECK(output.str() == "1/2");
    Rational m;
    std::istringstream input("5/3");
    input >> m;
    CHECK(m == Rational{5, 3});
}

