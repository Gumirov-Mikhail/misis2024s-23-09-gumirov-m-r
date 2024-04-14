#include <stacklst/stacklst.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("StackLst - Constructors") {
    SUBCASE("Default Constructor") {
        StackLst ctor;
        CHECK(ctor.IsEmpty() == true);
    }
    SUBCASE("Constructor Copy") {
        StackLst copy_ctor1;
        copy_ctor1.Push(Complex(5,6));
        copy_ctor1.Push(Complex(2,3));
        StackLst copy_ctor2(copy_ctor1);
        CHECK(copy_ctor1.IsEmpty() == false);
        CHECK(copy_ctor1.Top() == Complex(2,3));
        CHECK(copy_ctor2.IsEmpty() == false);
        CHECK(copy_ctor2.Top() == Complex(2,3));
    }
    SUBCASE("Constructor Move") {
        StackLst move_ctor1;
        move_ctor1.Push(Complex(5,6));
        move_ctor1.Push(Complex(2,3));
        StackLst move_ctor2(std::move(move_ctor1));
        CHECK(move_ctor1.IsEmpty() == true);
        CHECK(move_ctor2.IsEmpty() == false);
        CHECK(move_ctor2.Top() == Complex(2,3));
    }
    SUBCASE("Constructor Copy with empty stack") {
        StackLst copy_ctor1;
        StackLst copy_ctor2(copy_ctor1);
        CHECK(copy_ctor1.IsEmpty() == true);
        CHECK(copy_ctor2.IsEmpty() == true);
    }
    SUBCASE("Constructor Move with empty stack") {
        StackLst move_ctor1;
        StackLst move_ctor2(std::move(move_ctor1));
        CHECK(move_ctor1.IsEmpty() == true);
        CHECK(move_ctor2.IsEmpty() == true);
    }
}

TEST_CASE("StackLst - Push, Pop, Top and Clear") {
    SUBCASE("Push and Pop") {
        StackLst stl;
        CHECK(stl.IsEmpty() == true);
        stl.Push(Complex(2, 3));
        CHECK(stl.Top() == Complex(2, 3));
        CHECK(stl.IsEmpty() == false);
        stl.Push(Complex(5, 6));
        CHECK(stl.Top() == Complex(5, 6));
        CHECK(stl.IsEmpty() == false);
        stl.Pop();
        CHECK(stl.Top() == Complex(2, 3));
        CHECK(stl.IsEmpty() == false);
        stl.Pop();
        CHECK(stl.IsEmpty() == true);
    }
    SUBCASE("Push and Clear") {
        StackLst stl;
        CHECK(stl.IsEmpty() == true);
        stl.Push(Complex(2, 3));
        CHECK(stl.Top() == Complex(2, 3));
        CHECK(stl.IsEmpty() == false);
        stl.Push(Complex(5, 6));
        CHECK(stl.Top() == Complex(5, 6));
        CHECK(stl.IsEmpty() == false);
        stl.Clear();
        CHECK(stl.IsEmpty() == true);
    }
    SUBCASE("Top with empty stack") {
        StackLst stl;
        CHECK_THROWS_WITH(stl.Top(), "StackLst - try get top from empty stack.");
        stl.Push(Complex(2, 3));
        stl.Pop();
        CHECK_THROWS_WITH(stl.Top(), "StackLst - try get top from empty stack.");
    }
}

TEST_CASE("StackLst - Assignment") {
    SUBCASE("Assignment with copy") {
        StackLst st1;
        st1.Push(Complex(1, 1));
        st1.Push(Complex(2, 3));
        st1.Push(Complex(5, 6));
        StackLst st2;
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
        StackLst st3;
        StackLst st4;
        st4.Push(Complex(1, 1));
        st4.Push(Complex(2, 3));
        st4.Push(Complex(5, 6));
        st4 = st3;
        CHECK(st3.IsEmpty() == true);
        CHECK(st4.IsEmpty() == true);
        CHECK_THROWS_WITH(st3.Top(), "StackLst - try get top from empty stack.");
        CHECK_THROWS_WITH(st4.Top(), "StackLst - try get top from empty stack.");
    }
    SUBCASE("Assignment with move") {
        StackLst st1;
        st1.Push(Complex(1, 1));
        st1.Push(Complex(2, 3));
        st1.Push(Complex(5, 6));
        StackLst st2;
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
        StackLst st3;
        StackLst st4;
        st4.Push(Complex(1, 1));
        st4.Push(Complex(2, 3));
        st4.Push(Complex(5, 6));
        st3 = std::move(st4);
        CHECK(st3.IsEmpty() == false);
        CHECK(st4.IsEmpty() == true);
        CHECK(st3.Top() == Complex(5,6));
        CHECK_THROWS_WITH(st4.Top(), "StackLst - try get top from empty stack.");
    }
}