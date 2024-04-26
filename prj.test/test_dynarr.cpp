#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <dynarr/dynarr.hpp>

TEST_CASE("DynArr - Constructors") {
    int size = 10;
    float ch1 = 5;
    float ch2 = 8;
    SUBCASE("Default constructor") {
        DynArr ctor;
        CHECK_EQ(ctor.Size(), 0);
    }
    SUBCASE("Constructor copy") {
        DynArr ctor_copy1(size);
        ctor_copy1[0] = ch1;
        ctor_copy1[1] = ch2;
        DynArr ctor_copy2(ctor_copy1);
        CHECK_EQ(ctor_copy1.Size(), size);
        CHECK_EQ(ctor_copy2.Size(), size);
        CHECK_EQ(ctor_copy1[0], ch1);
        CHECK_EQ(ctor_copy1[1], ch2);
        CHECK_EQ(ctor_copy2[0], ch1);
        CHECK_EQ(ctor_copy2[1], ch2);
    }
    SUBCASE("Constructor move") {
        DynArr ctor_move1(size);
        ctor_move1[0] = ch1;
        ctor_move1[1] = ch2;
        DynArr ctor_move2(std::move(ctor_move1));
        CHECK_EQ(ctor_move1.Size(), 0);
        CHECK_EQ(ctor_move2.Size(), size);
        CHECK_EQ(ctor_move2[0], ch1);
        CHECK_EQ(ctor_move2[1], ch2);
    }
    SUBCASE("Constructor copy with empty array") {
        DynArr ctor_copy1;
        DynArr ctor_copy2(ctor_copy1);
        CHECK_EQ(ctor_copy1.Size(), 0);
        CHECK_EQ(ctor_copy2.Size(), 0);
    }
    SUBCASE("Constructor move with empty array") {
        DynArr ctor_move1;
        DynArr ctor_move2(std::move(ctor_move1));
        CHECK_EQ(ctor_move1.Size(), 0);
        CHECK_EQ(ctor_move2.Size(), 0);
    }
    SUBCASE("Constructor with size") {
        DynArr ctor_size(size);
        CHECK_EQ(ctor_size.Size(), size);
    }
}

TEST_CASE("DynArr - Resize and Indexation") {
    int size1 = 5;
    int resize1 = 15;
    int resize2 = 3;
    float ch1 = 2;
    float ch2 = 50;
    float ch3 = 69;
    SUBCASE("Resize more size") {
        DynArr arr(size1);
        CHECK_EQ(arr.Size(), size1);
        arr.Resize(resize1);
        CHECK_EQ(arr.Size(), resize1);
    }
    SUBCASE("Resize less size") {
        DynArr arr(size1);
        for (int i = 0; i < size1; i++) {
            arr[i] = (float) i;
        }
        CHECK_EQ(arr.Size(), size1);
        arr.Resize(resize2);
        CHECK_EQ(arr.Size(), resize2);
        CHECK_EQ(arr[0], 0);
        CHECK_EQ(arr[1], 1);
        CHECK_EQ(arr[2], 2);
        CHECK_THROWS_WITH(arr[3], "DynArr - try get element with invalid index");
    }
    SUBCASE("Resize equal size") {
        DynArr arr(size1);
        for (int i = 0; i < size1; i++) {
            arr[i] = (float) i;
        }
        CHECK_EQ(arr.Size(), size1);
        arr.Resize(size1);
        CHECK_EQ(arr.Size(), size1);
        CHECK_EQ(arr[4], 4);
    }
    SUBCASE("Resize with empty array") {
        DynArr arr;
        CHECK_THROWS_WITH(arr.Resize(-4), "DynArr - try Resize DynArr with negative size");
        CHECK_THROWS_WITH(arr.Resize(0), "DynArr - try Resize DynArr of zero size");
    }
    SUBCASE("Indexation") {
        DynArr arr(size1);
        CHECK_EQ(arr.Size(), size1);
        arr[0] = ch1;
        arr[2] = ch2;
        arr[4] = ch3;
        CHECK_EQ(arr[0], ch1);
        CHECK_EQ(arr[1], 0);
        CHECK_EQ(arr[2], ch2);
        CHECK_EQ(arr[3], 0);
        CHECK_EQ(arr[4], ch3);
    }
    SUBCASE("Indexation with empty array") {
        DynArr arr;
        CHECK_THROWS_WITH(arr[-13], "DynArr - try get element with negative index");
        CHECK_THROWS_WITH(arr[5], "DynArr - try get element with invalid index");
    }
}

TEST_CASE("DynArr - Assignment") {
    int size = 10;
    int resize = 4;
    float ch1 = 5;
    float ch2 = 6;
    SUBCASE("Assignment with copy") {
    DynArr arr1(size);
        arr1[0] = ch1;
        arr1[5] = ch2;
        DynArr arr2;
        arr2 = arr1;
        CHECK_EQ(arr2.Size(), size);
        CHECK_EQ(arr2[0], ch1);
        CHECK_EQ(arr2[5], ch2);
        CHECK_EQ(arr2[8], 0);
        arr2.Resize(resize);
        CHECK_EQ(arr2.Size(), resize);
        CHECK_EQ(arr1.Size(), size);
    }
    SUBCASE("Assignment with move") {
        DynArr arr1(size);
        arr1[0] = ch1;
        arr1[5] = ch2;
        DynArr arr2;
        arr2 = std::move(arr1);
        CHECK_EQ(arr2.Size(), size);
        CHECK_EQ(arr2[0], ch1);
        CHECK_EQ(arr2[5], ch2);
        CHECK_EQ(arr2[8], 0);
        arr2.Resize(resize);
        CHECK_EQ(arr2.Size(), resize);
        CHECK_EQ(arr1.Size(), 0);
    }
    SUBCASE("Assignment with copy empty array") {
        DynArr arr1(size);
        arr1[0] = ch1;
        arr1[5] = ch2;
        DynArr arr2;
        arr1 = arr2;
        CHECK_EQ(arr2.Size(), 0);
        CHECK_EQ(arr1.Size(), 0);
        arr1.Resize(resize);
        CHECK_EQ(arr2.Size(), 0);
        CHECK_EQ(arr1.Size(), resize);
    }
    SUBCASE("Assignment with move empty array") {
        DynArr arr1(size);
        arr1[0] = ch1;
        arr1[5] = ch2;
        DynArr arr2;
        arr1 = std::move(arr2);
        CHECK_EQ(arr2.Size(), size);
        CHECK_EQ(arr1.Size(), 0);
        CHECK_EQ(arr2[0], ch1);
        CHECK_EQ(arr2[5], ch2);
        CHECK_EQ(arr2[8], 0);
        arr2.Resize(resize);
        arr1.Resize(size);
        CHECK_EQ(arr2.Size(), resize);
        CHECK_EQ(arr1.Size(), size);
    }
}