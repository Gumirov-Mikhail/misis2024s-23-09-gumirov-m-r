#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <dynarr/dynarr.hpp>

TEST_CASE("DynArr - Constructors") {

    SUBCASE("Default constructor") {
        DynArr ctor;
        CHECK(ctor.Size() == 0);
    }
    SUBCASE("Constructor copy") {
        DynArr ctor_copy1(10);
        ctor_copy1[0] = 5;
        ctor_copy1[1] = 8;
        DynArr ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.Size() == 10);
        CHECK(ctor_copy2.Size() == 10);
        CHECK(ctor_copy1[0] == 5);
        CHECK(ctor_copy1[1] == 8);
        CHECK(ctor_copy2[0] == 5);
        CHECK(ctor_copy2[1] == 8);
    }
    SUBCASE("Constructor move") {
        DynArr ctor_move1(10);
        ctor_move1[0] = 5;
        ctor_move1[1] = 8;
        DynArr ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.Size() == 0);
        CHECK(ctor_move2.Size() == 10);
        CHECK(ctor_move2[0] == 5);
        CHECK(ctor_move2[1] == 8);
    }
    SUBCASE("Constructor copy with empty array") {
        DynArr ctor_copy1;
        DynArr ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.Size() == 0);
        CHECK(ctor_copy2.Size() == 0);
    }
    SUBCASE("Constructor move with empty array") {
        DynArr ctor_move1;
        DynArr ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.Size() == 0);
        CHECK(ctor_move2.Size() == 0);
    }
    SUBCASE("Constructor with size") {
        DynArr ctor_size(100);
        CHECK(ctor_size.Size() == 100);
    }
}

TEST_CASE("DynArr - Resize and Indexation") {
    SUBCASE("Resize more size") {
        DynArr arr(10);
        CHECK(arr.Size() == 10);
        arr.Resize(25);
        CHECK(arr.Size() == 25);
    }
    SUBCASE("Resize less size") {
        const int size = 5;
        DynArr arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
        CHECK(arr.Size() == size);
        arr.Resize(3);
        CHECK(arr.Size() == 3);
        CHECK(arr[0] == 0);
        CHECK(arr[1] == 1);
        CHECK(arr[2] == 2);
        CHECK_THROWS_WITH(arr[3], "DynArr - try get element with invalid index");
    }
    SUBCASE("Resize equal size") {
        const int size = 5;
        DynArr arr(size);
        for (int i = 0; i < size; i++) {
            arr[i] = i;
        }
        CHECK(arr.Size() == size);
        arr.Resize(9);
        CHECK(arr.Size() == 9);
        CHECK(arr[4] == 4);
    }
    SUBCASE("Resize with empty array") {
        DynArr arr;
        CHECK_THROWS_WITH(arr.Resize(-4), "DynArr - try Resize DynArr with negative size");
        CHECK_THROWS_WITH(arr.Resize(0), "DynArr - try Resize DynArr of zero size");
    }
    SUBCASE("Indexation") {
        DynArr arr(10);
        CHECK(arr.Size() == 10);
        arr[0] = 56;
        arr[2] = 67;
        arr[8] = 2;
        CHECK(arr[0] == 56);
        CHECK(arr[1] == 0);
        CHECK(arr[2] == 67);
        CHECK(arr[8] == 2);
        CHECK(arr[9] == 0);
    }
    SUBCASE("Indexation with empty array") {
        DynArr arr;
        CHECK_THROWS_WITH(arr[-13], "DynArr - try get element with negative index");
        CHECK_THROWS_WITH(arr[5], "DynArr - try get element with invalid index");
    }
}

TEST_CASE("DynArr - Assignment") {
    SUBCASE("Assignment with copy") {
    DynArr arr1(10);
        arr1[0] = 5;
        arr1[5] = 6;
        DynArr arr2;
        arr2 = arr1;
        CHECK(arr2.Size() == 10);
        CHECK(arr2[0] == 5);
        CHECK(arr2[5] == 6);
        CHECK(arr2[8] == 0);
        arr2.Resize(4);
        CHECK(arr2.Size() == 4);
        CHECK(arr1.Size() == 10);
    }
    SUBCASE("Assignment with move") {
        DynArr arr1(10);
        arr1[0] = 5;
        arr1[5] = 6;
        DynArr arr2;
        arr2 = std::move(arr1);
        CHECK(arr2.Size() == 10);
        CHECK(arr2[0] == 5);
        CHECK(arr2[5] == 6);
        CHECK(arr2[8] == 0);
        arr2.Resize(4);
        CHECK(arr2.Size() == 4);
        CHECK(arr1.Size() == 0);
    }
    SUBCASE("Assignment with copy empty array") {
        DynArr arr1(10);
        arr1[0] = 5;
        arr1[5] = 6;
        DynArr arr2;
        arr1 = arr2;
        CHECK(arr2.Size() == 0);
        CHECK(arr1.Size() == 0);
        arr1.Resize(16);
        CHECK(arr2.Size() == 0);
        CHECK(arr1.Size() == 16);
    }
    SUBCASE("Assignment with move empty array") {
        DynArr arr1(10);
        arr1[0] = 5;
        arr1[5] = 6;
        DynArr arr2;
        arr1 = std::move(arr2);
        CHECK(arr2.Size() == 10);
        CHECK(arr1.Size() == 0);
        CHECK(arr2[0] == 5);
        CHECK(arr2[5] == 6);
        CHECK(arr2[8] == 0);
        arr2.Resize(4);
        arr1.Resize(16);
        CHECK(arr2.Size() == 4);
        CHECK(arr1.Size() == 16);
    }
}