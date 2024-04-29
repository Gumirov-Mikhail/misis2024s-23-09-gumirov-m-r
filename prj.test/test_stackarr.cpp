#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stackarr/stackarr.hpp>

TEST_CASE("StackArr - Constructors") {
    Complex ch1 {5, 6};
    Complex ch2 {2, 3};
    SUBCASE("Default Constructor") {
        StackArr ctor;
        CHECK(ctor.IsEmpty());
    }
    SUBCASE("Constructor Copy") {
        StackArr copy_ctor1;
        copy_ctor1.Push(ch1);
        copy_ctor1.Push(ch2);
        StackArr copy_ctor2(copy_ctor1);
        CHECK(!copy_ctor1.IsEmpty());
        CHECK_EQ(copy_ctor1.Top(), ch2);
        CHECK(!copy_ctor2.IsEmpty());
        CHECK_EQ(copy_ctor2.Top(), ch2);
    }
    SUBCASE("Constructor Move") {
        StackArr move_ctor1;
        move_ctor1.Push(ch1);
        move_ctor1.Push(ch2);
        StackArr move_ctor2(std::move(move_ctor1));
        CHECK(move_ctor1.IsEmpty());
        CHECK(!move_ctor2.IsEmpty());
        CHECK_EQ(move_ctor2.Top(), ch2);
    }
    SUBCASE("Constructor Copy with empty stack") {
        StackArr copy_ctor1;
        StackArr copy_ctor2(copy_ctor1);
        CHECK(copy_ctor1.IsEmpty());
        CHECK(copy_ctor2.IsEmpty());
    }
    SUBCASE("Constructor Move with empty stack") {
        StackArr move_ctor1;
        StackArr move_ctor2(std::move(move_ctor1));
        CHECK(move_ctor1.IsEmpty());
        CHECK(move_ctor2.IsEmpty());
    }
}

TEST_CASE("StackArr - Push, Pop, Top and Clear") {
    Complex ch1 {5, 6};
    Complex ch2 {2, 3};
    SUBCASE("Push and Pop") {
        StackArr st1;
        CHECK(st1.IsEmpty());
        st1.Push(ch2);
        CHECK_EQ(st1.Top(), ch2);
        CHECK(!st1.IsEmpty());
        st1.Push(ch1);
        CHECK_EQ(st1.Top(), ch1);
        CHECK(!st1.IsEmpty());
        st1.Pop();
        CHECK_EQ(st1.Top(), ch2);
        CHECK(!st1.IsEmpty());
        st1.Pop();
        CHECK(st1.IsEmpty());
    }
    SUBCASE("Push and Clear") {
        StackArr st1;
        CHECK(st1.IsEmpty());
        st1.Push(ch2);
        CHECK_EQ(st1.Top(), ch2);
        CHECK(!st1.IsEmpty());
        st1.Push(ch1);
        CHECK_EQ(st1.Top(), ch1);
        CHECK(!st1.IsEmpty());
        st1.Clear();
        CHECK(st1.IsEmpty());
    }
    SUBCASE("Top with empty stack") {
        StackArr st1;
        StackArr st2(st1);
        StackArr st3(std::move(st1));
        CHECK(st1.IsEmpty());
        CHECK_THROWS_WITH(st1.Top(), "StackArr - try get top from empty stack.");
        CHECK(st2.IsEmpty());
        CHECK_THROWS_WITH(st2.Top(), "StackArr - try get top from empty stack.");
        CHECK(st3.IsEmpty());
        CHECK_THROWS_WITH(st3.Top(), "StackArr - try get top from empty stack.");
        st1.Push(ch2);
        CHECK_EQ(st1.Top(), ch2);
        st1.Pop();
        CHECK_THROWS_WITH(st1.Top(), "StackArr - try get top from empty stack.");
    }
}

TEST_CASE("StackArr - Assignment") {
    Complex ch1 {5, 6};
    Complex ch2 {2, 3};
    Complex ch3 {1, 1};
    SUBCASE("Assignment with copy") {
        StackArr st1;
        st1.Push(ch3);
        st1.Push(ch2);
        st1.Push(ch1);
        StackArr st2;
        st2 = st1;
        CHECK(!st1.IsEmpty());
        CHECK(!st2.IsEmpty());
        CHECK_EQ(st2.Top(), ch1);
        st2.Pop();
        CHECK_EQ(st2.Top(), ch2);
        st2.Clear();
        CHECK(st2.IsEmpty());
    }
    SUBCASE("Assignment with copy empty stack") {
        StackArr st3;
        StackArr st4;
        st4.Push(ch3);
        st4.Push(ch2);
        st4.Push(ch1);
        st4 = st3;
        CHECK(st3.IsEmpty());
        CHECK(st4.IsEmpty());
        CHECK_THROWS_WITH(st3.Top(), "StackArr - try get top from empty stack.");
        CHECK_THROWS_WITH(st4.Top(), "StackArr - try get top from empty stack.");
    }
    SUBCASE("Assignment with move") {
        StackArr st1;
        st1.Push(ch3);
        st1.Push(ch2);
        st1.Push(ch1);
        StackArr st2;
        st2 = std::move(st1);
        CHECK(st1.IsEmpty());
        CHECK(!st2.IsEmpty());
        CHECK_EQ(st2.Top(), ch1);
        st2.Pop();
        CHECK_EQ(st2.Top(), ch2);
        st2.Clear();
        CHECK(st2.IsEmpty());
    }
    SUBCASE("Assignment with move empty stack") {
        StackArr st3;
        StackArr st4;
        st4.Push(ch3);
        st4.Push(ch2);
        st4.Push(ch1);
        st3 = std::move(st4);
        CHECK(!st3.IsEmpty());
        CHECK(st4.IsEmpty());
        CHECK_EQ(st3.Top(), ch1);
        CHECK_THROWS_WITH(st4.Top(), "StackArr - try get top from empty stack.");
    }
}