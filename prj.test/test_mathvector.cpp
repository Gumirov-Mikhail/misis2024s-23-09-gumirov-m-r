#include <mathvector/mathvector.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("MathVector - Constructors") {
    const int capacity = 10;
    int size_empty = 0;
    int ch1 = 5;
    int ch2 = 3;
    int ch3 = 1;
    SUBCASE("Default constructor") {
        MathVector<capacity> ctor;
        CHECK(ctor.empty());
        CHECK_EQ(ctor.getSize(), size_empty);
    }
    SUBCASE("Constructor Copy") {
        MathVector<capacity> ctor_copy1;
        ctor_copy1.push_back(ch1);
        ctor_copy1.push_back(ch2);
        MathVector<capacity> ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy1.empty());
        CHECK_EQ(ctor_copy1.getSize(), 2);
        CHECK(!ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.getSize(), 2);
    }
    SUBCASE("Constructor Move") {
        MathVector<capacity> ctor_move1;
        ctor_move1.push_back(ch1);
        ctor_move1.push_back(ch2);
        MathVector<capacity> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK_EQ(ctor_move1.getSize(), size_empty);
        CHECK(!ctor_move2.empty());
        CHECK_EQ(ctor_move2.getSize(), 2);
    }
    SUBCASE("Initializer list") {
        MathVector<capacity> init_list1 {ch1, ch2, ch3};
        CHECK(!init_list1.empty());
        CHECK_EQ(init_list1.getSize(), 3);
    }
    SUBCASE("Constructor Copy with empty vector") {
        MathVector<capacity> ctor_copy1;
        MathVector<capacity> ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.empty());
        CHECK_EQ(ctor_copy1.getSize(), size_empty);
        CHECK(ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.getSize(), size_empty);
    }
    SUBCASE("Constructor Move with empty vector") {
        MathVector<capacity> ctor_move1;
        MathVector<capacity> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK_EQ(ctor_move1.getSize(), size_empty);
        CHECK(ctor_move2.empty());
        CHECK_EQ(ctor_move2.getSize(), size_empty);
    }
}

TEST_CASE("MathVector - Push_back, Getters, Clear, At and Replace_at") {
    const int capacity = 10;
    int size_empty = 0;
    int ch1 = 5;
    int ch2 = 4;
    int ch3 = 3;
    int ch1_big = 30;
    int ch2_big = 40;
    int ch3_big = 50;
    SUBCASE("Push_back, Getters and Clear") {
        MathVector<capacity> vector;
        CHECK(vector.empty());
        CHECK_EQ(vector.getSize(), size_empty);
        vector.push_back(ch1);
        CHECK(!vector.empty());
        CHECK_EQ(vector.getSize(), 1);
        CHECK_EQ(vector.getFront(), ch1);
        CHECK_EQ(vector.getBack(), ch1);
        vector.push_back(ch2);
        CHECK_EQ(vector.getSize(), 2);
        CHECK_EQ(vector.getFront(), ch1);
        CHECK_EQ(vector.getBack(), ch2);
        vector.push_back(ch3);
        CHECK_EQ(vector.getSize(), 3);
        CHECK_EQ(vector.getFront(), ch1);
        CHECK_EQ(vector.getBack(), ch3);
        vector.Clear();
        CHECK(vector.empty());
        CHECK_EQ(vector.getSize(), size_empty);
        CHECK_THROWS_WITH(void(vector.getFront()), "MathVector - try get at from empty vector.");
        CHECK_THROWS_WITH(void(vector.getBack()), "MathVector - try get at from empty vector.");
    }
    SUBCASE("At and Clear") {
        MathVector<capacity> vector {ch1, ch2, ch3};
        CHECK_EQ(vector.at(0), ch1);
        CHECK_EQ(vector.at(1), ch2);
        CHECK_EQ(vector.at(2), ch3);
        CHECK_THROWS_WITH(void(vector.at(3)), "MathVector - try get at from outside the vector.");
        CHECK_THROWS_WITH(void(vector.at(24)), "MathVector - try get at from outside the vector.");
        vector.Clear();
        CHECK_THROWS_WITH(void(vector.at(24)), "MathVector - try get at from empty vector.");
    }
    SUBCASE("Replace_at and At") {
        MathVector<capacity> vector {ch1, ch2, ch3};
        vector.replace_at(0, ch1_big);
        vector.replace_at(1, ch2_big);
        vector.replace_at(2, ch3_big);
        CHECK_EQ(vector.at(0), ch1_big);
        CHECK_EQ(vector.at(1), ch2_big);
        CHECK_EQ(vector.at(2), ch3_big);
    }
}

TEST_CASE("MathVector - Swap and Clear") {
    const int capacity = 10;
    int ch1 = 5;
    int ch2 = 4;
    int ch3 = 3;
    int ch_big = 30;
    MathVector<capacity> vector1 {ch_big, ch2, ch1};
    MathVector<capacity> vector2 {ch_big, ch2, ch1};
    MathVector<capacity> vector3;
    MathVector<capacity> vector4 {ch1, ch2, ch3};
    vector1.swap(vector3);
    CHECK_EQ((vector3 == vector2), true);
    CHECK(vector1.empty());
    vector2.swap(vector4);
    CHECK_EQ((vector3 == vector4), true);
    CHECK_EQ((vector2 != vector3), true);
}

TEST_CASE("MathVector - Compare") {
    const int capacity = 10;
    int ch1 = 5;
    int ch2 = 4;
    int ch3 = 3;
    int ch_big = 30;
    SUBCASE("Compare with not empty vector") {
        MathVector<capacity> vector1 {ch1, ch2, ch3};
        MathVector<capacity> vector2 {ch1, ch2, ch3};
        MathVector<capacity> vector3 {ch1, ch2, ch_big};
        CHECK_EQ((vector1 == vector2), true);
        CHECK_EQ((vector1 != vector3), true);
        CHECK_EQ((vector2 != vector3), true);
        CHECK_EQ((vector1 != vector2), false);
        CHECK_EQ((vector1 == vector3), false);
        CHECK_EQ((vector2 == vector3), false);
    }
    SUBCASE("Compare with empty vector") {
        MathVector<capacity> vector1 {ch1, ch2, ch3};
        MathVector<capacity> vector2;
        MathVector<capacity> vector3;
        CHECK_EQ((vector1 != vector2), true);
        CHECK_EQ((vector1 != vector3), true);
        CHECK_EQ((vector2 == vector3), true);
        CHECK_EQ((vector1 == vector2), false);
        CHECK_EQ((vector1 == vector3), false);
        CHECK_EQ((vector2 != vector3), false);
    }
}

TEST_CASE("MathVector - Assignment") {
    const int capacity = 10;
    int size_empty = 0;
    int ch1 = 5;
    int ch2 = 4;
    int ch3 = 3;
    int ch_big = 30;
    SUBCASE("Assignment with copy") {
        MathVector<capacity> vector1 {ch1, ch2, ch3};
        MathVector<capacity> vector2;
        vector2 = vector1;
        CHECK(!vector1.empty());
        CHECK(!vector2.empty());
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), ch3);
        CHECK_EQ(vector2.getFront(), ch1);
        CHECK_EQ(vector2.at(1), ch2);
        vector2.replace_at(2, ch_big);
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), ch_big);
        CHECK_EQ(vector2.getFront(), ch1);
        CHECK_EQ(vector2.at(1), ch2);
        vector2.Clear();
        CHECK(!vector1.empty());
        CHECK(vector2.empty());
    }
    SUBCASE("Assignment with copy empty vector") {
        MathVector<capacity> vector3;
        MathVector<capacity> vector4 {ch1, ch2, ch3};
        vector4 = vector3;
        CHECK(vector3.empty());
        CHECK(vector4.empty());
        CHECK_EQ(vector3.getSize(), size_empty);
        CHECK_EQ(vector4.getSize(), size_empty);
    }
    SUBCASE("Assignment with move") {
        MathVector<capacity> vector1 {ch1, ch2, ch3};
        MathVector<capacity> vector2;
        vector2 = std::move(vector1);
        CHECK(vector1.empty());
        CHECK(!vector2.empty());
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), ch3);
        CHECK_EQ(vector2.getFront(), ch1);
        CHECK_EQ(vector2.at(1), ch2);
        vector2.replace_at(2, ch_big);
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), ch_big);
        CHECK_EQ(vector2.getFront(), ch1);
        CHECK_EQ(vector2.at(1), ch2);
        vector2.Clear();
        CHECK(vector1.empty());
        CHECK(vector2.empty());
    }
    SUBCASE("Assignment with move empty vector") {
        MathVector<capacity> vector3;
        MathVector<capacity> vector4 {ch1, ch2, ch3};
        vector4 = std::move(vector3);
        CHECK(!vector3.empty());
        CHECK(vector4.empty());
        CHECK_EQ(vector3.getSize(), 3);
        CHECK_EQ(vector4.getSize(), size_empty);
    }
}