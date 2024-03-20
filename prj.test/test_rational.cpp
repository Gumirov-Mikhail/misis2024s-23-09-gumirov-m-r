#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.hpp>

TEST_CASE("Rational constructor") {
    Rational r_empty;
    CHECK(0 == r_empty.num());
    CHECK(1 == r_empty.den());
    Rational r_num(3);
    CHECK(3 == r_num.num());
    CHECK(1 == r_num.den());
    Rational r_negative(2, -3);
    CHECK(-2 == r_negative.num());
    CHECK(3 == r_negative.den());
    Rational r_reduction(6, 9);
    CHECK(2 == r_reduction.num());
    CHECK(3 == r_reduction.den());
    Rational r_copy(r_reduction);
    CHECK(2 == r_copy.num());
    CHECK(3 == r_copy.den());
    CHECK_THROWS_WITH(void(Rational(1,0)), "Zero denumenator in Rational ctor");
}

TEST_CASE("Rational assignment") {
    Rational r_ch1;
    Rational r_ch2{2};
    Rational r_ch3{4, 5};
    r_ch1 = r_ch2 = r_ch3;
    CHECK(4 == r_ch1.num());
    CHECK(5 == r_ch1.den());
    CHECK(4 == r_ch2.num());
    CHECK(5 == r_ch2.den());
    CHECK(4 == r_ch3.num());
    CHECK(5 == r_ch3.den());
}

TEST_CASE("Rational comparison") {
    Rational r_ch1{2, 3};
    Rational r_ch2{4, 5};
    CHECK((r_ch1 == r_ch2) == false);
    CHECK((r_ch1 != r_ch2) == true);
    CHECK((r_ch1 > r_ch2) == false);
    CHECK((r_ch1 < r_ch2) == true);
    CHECK((r_ch1 >= r_ch2) == false);
    CHECK((r_ch1 <= r_ch2) == true);
}

TEST_CASE("Rational mathematics") {
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
    Rational r_num4{0, 5};
    CHECK_THROWS_WITH(void(r_num1 / r_num4), "Division by zero!");
}

TEST_CASE("Rational input/output") {
    Rational r_output{1, 2};
    std::ostringstream output;
    output << r_output;
    CHECK(output.str() == "1/2");
    Rational r_input;
    std::istringstream input("5/3");
    input >> r_input;
    CHECK(r_input == Rational{5, 3});
}

