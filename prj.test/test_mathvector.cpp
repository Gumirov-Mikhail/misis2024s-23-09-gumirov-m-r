#include <mathvector/mathvector.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("MathVector - Constructors") {
    SUBCASE("Default constructor") {
        MathVector<10> ctor;
        CHECK(ctor.empty());
        CHECK_EQ(ctor.getSize(), 0);
    }
    SUBCASE("Constructor Copy") {
        MathVector<10> ctor_copy1;
        ctor_copy1.push_back(5);
        ctor_copy1.push_back(3);
        MathVector<10> ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy1.empty());
        CHECK_EQ(ctor_copy1.getSize(), 2);
        CHECK(!ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.getSize(), 2);
    }
    SUBCASE("Constructor Move") {
        MathVector<10> ctor_move1;
        ctor_move1.push_back(5);
        ctor_move1.push_back(3);
        MathVector<10> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK_EQ(ctor_move1.getSize(), 0);
        CHECK(!ctor_move2.empty());
        CHECK_EQ(ctor_move2.getSize(), 2);
    }
    SUBCASE("Initializer list") {
        MathVector<10> init_list1 {1, 2, 3};
        CHECK(!init_list1.empty());
        CHECK_EQ(init_list1.getSize(), 3);
    }
    SUBCASE("Constructor Copy with empty vector") {
        MathVector<10> ctor_copy1;
        MathVector<10> ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.empty());
        CHECK_EQ(ctor_copy1.getSize(), 0);
        CHECK(ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.getSize(), 0);
    }
    SUBCASE("Constructor Move with empty vector") {
        MathVector<10> ctor_move1;
        MathVector<10> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK_EQ(ctor_move1.getSize(), 0);
        CHECK(ctor_move2.empty());
        CHECK_EQ(ctor_move2.getSize(), 0);
    }
}

TEST_CASE("MathVector - Push_back, Getters, Clear, At and Replace_at") {
    SUBCASE("Push_back, Getters and Clear") {
        MathVector<3> vector;
        CHECK(vector.empty());
        CHECK_EQ(vector.getSize(), 0);
        vector.push_back(5);
        CHECK(!vector.empty());
        CHECK_EQ(vector.getSize(), 1);
        CHECK_EQ(vector.getFront(), 5);
        CHECK_EQ(vector.getBack(), 5);
        vector.push_back(3);
        CHECK_EQ(vector.getSize(), 2);
        CHECK_EQ(vector.getFront(), 5);
        CHECK_EQ(vector.getBack(), 3);
        vector.push_back(1);
        CHECK_EQ(vector.getSize(), 3);
        CHECK_EQ(vector.getFront(), 5);
        CHECK_EQ(vector.getBack(), 1);
        vector.Clear();
        CHECK(vector.empty());
        CHECK_EQ(vector.getSize(), 0);
        CHECK_THROWS_WITH(vector.getFront(), "MathVector - try get at from empty vector.");
        CHECK_THROWS_WITH(vector.getBack(), "MathVector - try get at from empty vector.");
    }
    SUBCASE("At and Clear") {
        MathVector<10> vector {1, 4, 5};
        CHECK_EQ(vector.at(0), 1);
        CHECK_EQ(vector.at(1), 4);
        CHECK_EQ(vector.at(2), 5);
        CHECK_THROWS_WITH(vector.at(3), "MathVector - try get at from outside the vector.");
        CHECK_THROWS_WITH(vector.at(24), "MathVector - try get at from outside the vector.");
        vector.Clear();
        CHECK_THROWS_WITH(vector.at(24), "MathVector - try get at from empty vector.");
    }
    SUBCASE("Replace_at and At") {
        MathVector<10> vector {1, 4, 5};
        vector.replace_at(0, 90);
        vector.replace_at(1, 80);
        vector.replace_at(2, 70);
        CHECK_EQ(vector.at(0), 90);
        CHECK_EQ(vector.at(1), 80);
        CHECK_EQ(vector.at(2), 70);
    }
}

TEST_CASE("MathVector - Swap and Clear") {
    MathVector<10> vector1 {1, 4, 5};
    MathVector<10> vector2 {1, 4, 5};
    MathVector<10> vector3;
    MathVector<10> vector4 {5, 4, 3};
    vector1.swap(vector3);
    CHECK_EQ((vector3 == vector2), true);
    CHECK(vector1.empty());
    vector2.swap(vector4);
    CHECK_EQ((vector3 == vector4), true);
    CHECK_EQ((vector2 != vector3), true);
}

TEST_CASE("MathVector - Compare") {
    SUBCASE("Compare with not empty vector") {
        MathVector<10> vector1 {5, 4, 3};
        MathVector<10> vector2 {5, 4, 3};
        MathVector<10> vector3 {5, 4, 1};
        CHECK_EQ((vector1 == vector2), true);
        CHECK_EQ((vector1 != vector3), true);
        CHECK_EQ((vector2 != vector3), true);
        CHECK_EQ((vector1 != vector2), false);
        CHECK_EQ((vector1 == vector3), false);
        CHECK_EQ((vector2 == vector3), false);
    }
    SUBCASE("Compare with empty vector") {
        MathVector<10> vector1 {5, 4, 3};
        MathVector<10> vector2;
        MathVector<10> vector3;
        CHECK_EQ((vector1 != vector2), true);
        CHECK_EQ((vector1 != vector3), true);
        CHECK_EQ((vector2 == vector3), true);
        CHECK_EQ((vector1 == vector2), false);
        CHECK_EQ((vector1 == vector3), false);
        CHECK_EQ((vector2 != vector3), false);
    }
}

TEST_CASE("MathVector - Assignment") {
    SUBCASE("Assignment with copy") {
        MathVector<10> vector1 {5, 4, 3};
        MathVector<10> vector2;
        vector2 = vector1;
        CHECK(!vector1.empty());
        CHECK(!vector2.empty());
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), 3);
        CHECK_EQ(vector2.getFront(), 5);
        CHECK_EQ(vector2.at(1), 4);
        vector2.replace_at(2, 30);
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), 30);
        CHECK_EQ(vector2.getFront(), 5);
        CHECK_EQ(vector2.at(1), 4);
        vector2.Clear();
        CHECK(!vector1.empty());
        CHECK(vector2.empty());
    }
    SUBCASE("Assignment with copy empty vector") {
        MathVector<10> vector3;
        MathVector<10> vector4 {5, 4, 3};
        vector4 = vector3;
        CHECK(vector3.empty());
        CHECK(vector4.empty());
        CHECK_EQ(vector3.getSize(), 0);
        CHECK_EQ(vector4.getSize(), 0);
    }
    SUBCASE("Assignment with move") {
        MathVector<10> vector1 {5, 4, 3};
        MathVector<10> vector2;
        vector2 = std::move(vector1);
        CHECK(vector1.empty());
        CHECK(!vector2.empty());
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), 3);
        CHECK_EQ(vector2.getFront(), 5);
        CHECK_EQ(vector2.at(1), 4);
        vector2.replace_at(2, 30);
        CHECK_EQ(vector2.getSize(), 3);
        CHECK_EQ(vector2.getBack(), 30);
        CHECK_EQ(vector2.getFront(), 5);
        CHECK_EQ(vector2.at(1), 4);
        vector2.Clear();
        CHECK(vector1.empty());
        CHECK(vector2.empty());
    }
    SUBCASE("Assignment with move empty vector") {
        MathVector<10> vector3;
        MathVector<10> vector4 {5, 4, 3};
        vector4 = std::move(vector3);
        CHECK(!vector3.empty());
        CHECK(vector4.empty());
        CHECK_EQ(vector3.getSize(), 3);
        CHECK_EQ(vector4.getSize(), 0);
    }
}