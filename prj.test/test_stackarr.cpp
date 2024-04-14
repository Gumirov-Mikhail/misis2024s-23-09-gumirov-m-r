#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stackarr/stackarr.hpp>

TEST_CASE("StackArr - Constructors") {
    SUBCASE("Constructor default") {
        StackArr ctor;
        CHECK(ctor.IsEmpty() == true);
    }
    SUBCASE("Constructor copy") {
        StackArr ctor_copy1;
        CHECK(ctor_copy1.IsEmpty() == true);
        ctor_copy1.Push(Complex(2,3));
        ctor_copy1.Push(Complex(5, 6));
        StackArr ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.IsEmpty() == false);
        CHECK(ctor_copy1.Top() == Complex(5,6));
        CHECK(ctor_copy2.IsEmpty() == false);
        CHECK(ctor_copy2.Top() == Complex(5,6));
    }
    SUBCASE("Constructor move") {
        StackArr ctor_move1;
        ctor_move1.Push(Complex(2,3));
        ctor_move1.Push(Complex(5, 6));
        StackArr ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move2.IsEmpty() == false);
        CHECK(ctor_move2.Top() == Complex(5,6));
        CHECK(ctor_move1.IsEmpty() == true);
    }
    SUBCASE("Constructor copy with empty stack") {
        StackArr ctor_copy1;
        StackArr ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.IsEmpty() == true);
        CHECK(ctor_copy2.IsEmpty() == true);
    }
    SUBCASE("Constructor move with empty stack") {
        StackArr ctor_move1;
        StackArr ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.IsEmpty() == true);
        CHECK(ctor_move2.IsEmpty() == true);
    }
}

TEST_CASE("StackArr - Push, Pop, Top and Clear") {
    SUBCASE("Push and Pop") {
        StackArr st1;
        st1.Push(Complex(2,3));
        CHECK(st1.Top() == Complex(2,3));
        st1.Push(Complex(5,6));
        CHECK(st1.Top() == Complex(5,6));
        StackArr st2(st1);
        CHECK(st2.Top() == Complex(5,6));
        st2.Pop();
        CHECK(st2.Top() == Complex(2,3));
        st2.Pop();
        CHECK(st2.IsEmpty() == true);
        CHECK(st1.IsEmpty() == false);
        CHECK(st1.Top() == Complex(5,6));
    }
    SUBCASE("Push and Clear") {
        StackArr st1;
        st1.Push(Complex(2,3));
        st1.Push(Complex(5,6));
        StackArr st2(st1);
        st1.Clear();
        CHECK(st1.IsEmpty() == true);
        CHECK(st2.IsEmpty() == false);
    }
    SUBCASE("Top with empty stack") {
        StackArr st1;
        StackArr st2(st1);
        StackArr st3(std::move(st1));
        CHECK(st1.IsEmpty() == true);
        CHECK_THROWS_WITH(st1.Top(), "StackArr - try get top from empty stack.");
        CHECK(st2.IsEmpty() == true);
        CHECK_THROWS_WITH(st2.Top(), "StackArr - try get top from empty stack.");
        CHECK(st3.IsEmpty() == true);
        CHECK_THROWS_WITH(st3.Top(), "StackArr - try get top from empty stack.");
    }
}

TEST_CASE("StackArr - Assignment") {
    SUBCASE("Assignment with copy") {
        StackArr st1;
        st1.Push(Complex(1, 1));
        st1.Push(Complex(2, 3));
        st1.Push(Complex(5, 6));
        StackArr st2;
        st2 = st1;
        CHECK(st1.IsEmpty() == false);
        CHECK(st2.IsEmpty() == false);
        CHECK(st2.Top() == Complex(5, 6));
        st2.Pop();
        CHECK(st2.Top() == Complex(2, 3));
        st2.Clear();
        CHECK(st2.IsEmpty() == true);
    }
    SUBCASE("Assignment with copy empty stack") {
        StackArr st3;
        StackArr st4;
        st4.Push(Complex(1, 1));
        st4.Push(Complex(2, 3));
        st4.Push(Complex(5, 6));
        st4 = st3;
        CHECK(st3.IsEmpty() == true);
        CHECK(st4.IsEmpty() == true);
        CHECK_THROWS_WITH(st3.Top(), "StackArr - try get top from empty stack.");
        CHECK_THROWS_WITH(st4.Top(), "StackArr - try get top from empty stack.");
    }
    SUBCASE("Assignment with move") {
        StackArr st1;
        st1.Push(Complex(1, 1));
        st1.Push(Complex(2, 3));
        st1.Push(Complex(5, 6));
        StackArr st2;
        st2 = std::move(st1);
        CHECK(st1.IsEmpty() == true);
        CHECK(st2.IsEmpty() == false);
        CHECK(st2.Top() == Complex(5, 6));
        st2.Pop();
        CHECK(st2.Top() == Complex(2, 3));
        st2.Clear();
        CHECK(st2.IsEmpty() == true);
    }
    SUBCASE("Assignment with move empty stack") {
        StackArr st3;
        StackArr st4;
        st4.Push(Complex(1, 1));
        st4.Push(Complex(2, 3));
        st4.Push(Complex(5, 6));
        st3 = std::move(st4);
        CHECK(st3.IsEmpty() == false);
        CHECK(st4.IsEmpty() == true);
        CHECK(st3.Top() == Complex(5,6));
        CHECK_THROWS_WITH(st4.Top(), "StackArr - try get top from empty stack.");
    }
}