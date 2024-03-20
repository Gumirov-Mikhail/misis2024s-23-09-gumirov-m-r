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
    Rational r_general;
    int ch = 10;
    r_general = r_num1 + r_num2;
    CHECK((r_general) == Rational{22, 15});
    r_general = r_num1 - r_num2;
    CHECK((r_general) == Rational{-2, 15});
    r_general = r_num1 * r_num2;
    CHECK((r_general) == Rational{8, 15});
    r_general = r_num1 / r_num2;
    CHECK((r_general) == Rational{10, 12});
    r_general = r_num1 + ch;
    CHECK((r_general) == Rational{32, 3});
    r_general = r_num1 - ch;
    CHECK((r_general) == Rational{-28, 3});
    r_general = r_num1 * ch;
    CHECK((r_general) == Rational{20, 3});
    r_general = r_num1 / ch;
    CHECK((r_general) == Rational{2, 30});
    r_general = ch + r_num2;
    CHECK((r_general) == Rational{54, 5});
    r_general = ch - r_num2;
    CHECK((r_general) == Rational{46, 5});
    r_general = ch * r_num2;
    CHECK((r_general) == Rational{40, 5});
    r_general = ch / r_num2;
    CHECK((r_general) == Rational{50, 4});
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

TEST_CASE("Rational assignment and mathematics") {
    Rational r_ch1{2, 3};
    Rational r_ch2{4, 5};
    int ch = 10;
    r_ch1 += r_ch2;
    CHECK(22 == r_ch1.num());
    CHECK(15 == r_ch1.den());
    r_ch1 -= r_ch2;
    CHECK(2 == r_ch1.num());
    CHECK(3 == r_ch1.den());
    r_ch1 *= r_ch2;
    CHECK(8 == r_ch1.num());
    CHECK(15 == r_ch1.den());
    r_ch1 /= r_ch2;
    CHECK(2 == r_ch1.num());
    CHECK(3 == r_ch1.den());
    r_ch1 += ch;
    CHECK(32 == r_ch1.num());
    CHECK(3 == r_ch1.den());
    r_ch1 -= ch;
    CHECK(2 == r_ch1.num());
    CHECK(3 == r_ch1.den());
    r_ch1 *= ch;
    CHECK(20 == r_ch1.num());
    CHECK(3 == r_ch1.den());
    r_ch1 /= ch;
    CHECK(2 == r_ch1.num());
    CHECK(3 == r_ch1.den());
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

TEST_CASE("neponyatno chto") {
    SUBCASE("Correct inputs") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm.str("2/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(2, 3));
        }

        sstrm.clear();

        SUBCASE("Input with reducing") {
            sstrm.str("36/48");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(3, 4));
        }

        sstrm.clear();

        SUBCASE("Negative input") {
            sstrm.str("-8/7");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-8, 7));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on begin") {
            sstrm.str(" 1/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("   -3/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-3, 4));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends") {
            sstrm.str(" 5/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(5, 9));
        }
        sstrm.clear();
    }
}