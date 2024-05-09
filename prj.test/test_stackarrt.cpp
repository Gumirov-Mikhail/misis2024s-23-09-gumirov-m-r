#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stackarrt/stackarrt.hpp>

#define TYPE_TEST int, float, double, long long

TEST_CASE_TEMPLATE("StackArrT - Constructors", T, TYPE_TEST) {
    int size_empty = 0;
    T ch1 = 1;
    T ch2 = 2;
    T ch3 = 3;
    T ch4 = 4;
    SUBCASE("Default constructor") {
        StackArrT<T> ctor;
        CHECK(ctor.empty());
        CHECK_EQ(ctor.size(), size_empty);
    }
    SUBCASE("Constructor copy") {
        StackArrT<T> ctor_copy1;
        ctor_copy1.push(ch1);
        ctor_copy1.push(ch4);
        StackArrT<T> ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.top(), ch4);
        CHECK_EQ(ctor_copy2.size(), 2);
    }
    SUBCASE("Constructor move") {
        StackArrT<T> ctor_move1;
        ctor_move1.push(ch1);
        ctor_move1.push(ch4);
        StackArrT<T> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK(!ctor_move2.empty());
        CHECK_EQ(ctor_move2.top(), ch4);
        CHECK_EQ(ctor_move2.size(), 2);
    }
    SUBCASE("Initializer list") {
        StackArrT<T> init_list {ch1, ch2, ch3, ch4};
        CHECK(!init_list.empty());
        CHECK_EQ(init_list.top(), ch4);
        CHECK_EQ(init_list.size(), 4);
    }
    SUBCASE("Constructor copy with empty stack") {
        StackArrT<T> ctor_copy1;
        StackArrT<T> ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.empty());
        CHECK(ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.size(), size_empty);
    }
    SUBCASE("Constructor move with empty stack") {
        StackArrT<T> ctor_move1;
        StackArrT<T> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK(ctor_move2.empty());
        CHECK_EQ(ctor_move1.size(), size_empty);
        CHECK_EQ(ctor_move2.size(), size_empty);
    }
}

TEST_CASE_TEMPLATE("StackArrT - Push, Pop and Top", T, TYPE_TEST) {
    int size_empty = 0;
    T ch3 = 3;
    T ch4 = 4;
    SUBCASE("Push and Pop") {
        StackArrT<T> st1;
        CHECK(st1.empty());
        CHECK_EQ(st1.size(), size_empty);
        st1.push(ch4);
        CHECK_EQ(st1.top(), ch4);
        CHECK_EQ(st1.size(), 1);
        st1.push(ch3);
        CHECK_EQ(st1.top(), ch3);
        CHECK_EQ(st1.size(), 2);
        st1.pop();
        CHECK_EQ(st1.top(), ch4);
        CHECK_EQ(st1.size(), 1);
        st1.pop();
        CHECK(st1.empty());
        CHECK_EQ(st1.size(), size_empty);
    }
    SUBCASE("Pop and Top with empty stack") {
        StackArrT<T> st1;
        CHECK_THROWS_WITH(void(st1.pop()), "StackArrT - try pop from empty stack.");
        CHECK_THROWS_WITH(void(st1.top()), "StackArrT - try get top from empty stack.");
        st1.push(ch4);
        CHECK_EQ(st1.top(), ch4);
        CHECK_EQ(st1.size(), 1);
        st1.pop();
        CHECK_THROWS_WITH(void(st1.pop()), "StackArrT - try pop from empty stack.");
        CHECK_THROWS_WITH(void(st1.top()), "StackArrT - try get top from empty stack.");
    }
}

TEST_CASE_TEMPLATE("StackArrT - Swap and Merge", T, TYPE_TEST) {
    T ch1 = 5;
    T ch2 = 4;
    T ch3 = 3;
    T ch4 = 6;
    T ch5 = 7;
    T ch6 = 8;
    SUBCASE("Swap") {
        StackArrT<T> st1 {ch1, ch2, ch3};
        StackArrT<T> st2 {ch1, ch2, ch3};
        StackArrT<T> st3;
        StackArrT<T> st4 {ch2, ch3, ch4};
        st1.swap(st3);
        CHECK(st3 == st2);
        CHECK(st1.empty());
        st2.swap(st4);
        CHECK(st3 == st4);
        CHECK(st2 != st3);
    }
    SUBCASE("Merge") {
        StackArrT<T> st_merge {ch1, ch2, ch3, ch4, ch5, ch6};
        StackArrT<T> st_merge_empty;
        SUBCASE("Default Merge") {
            StackArrT<T> st1 {ch1, ch2, ch3};
            StackArrT<T> st2 {ch4, ch5, ch6};
            st1.merge(st2);
            CHECK((st1 == st_merge));
        }
        SUBCASE("Merge empty and full") {
            StackArrT<T> st3;
            StackArrT<T> st4 {ch1, ch2, ch3, ch4, ch5, ch6};
            st3.merge(st4);
            CHECK(st3 == st_merge);
        }
        SUBCASE("Merge full and empty") {
            StackArrT<T> st5{ch1, ch2, ch3, ch4, ch5, ch6};
            StackArrT<T> st6;
            st5.merge(st6);
            CHECK(st5 == st_merge);
        }
        SUBCASE("Merge empty and empty") {
            StackArrT<T> st7;
            StackArrT<T> st8;
            st7.merge(st8);
            CHECK(st7 == st_merge_empty);
        }
    }
}

TEST_CASE_TEMPLATE("StackArrT - Compare", T, TYPE_TEST) {
    T ch1 = 5;
    T ch2 = 4;
    T ch3 = 3;
    T ch4 = 1;
    SUBCASE("Compare with not empty stack") {
        StackArrT<T> st1 {ch1, ch2, ch3};
        StackArrT<T> st2 {ch1, ch2, ch3};
        StackArrT<T> st3 {ch1, ch2, ch4};
        CHECK(st1 == st2);
        CHECK(st1 != st3);
        CHECK(st2 != st3);
        CHECK(!(st1 != st2));
        CHECK(!(st1 == st3));
        CHECK(!(st2 == st3));
    }
    SUBCASE("Compare with empty stack") {
        StackArrT<T> st1 {ch1, ch2, ch3};
        StackArrT<T> st2;
        StackArrT<T> st3;
        CHECK(st1 != st2);
        CHECK(st1 != st3);
        CHECK(st2 == st3);
        CHECK(!(st1 == st2));
        CHECK(!(st1 == st3));
        CHECK(!(st2 != st3));
    }
}

TEST_CASE_TEMPLATE("StackArrT - Assignment", T, TYPE_TEST) {
    int size_empty = 0;
    T ch1 = 5;
    T ch2 = 4;
    T ch3 = 3;
    SUBCASE("Assignment with copy") {
        StackArrT<T> st1{ch1, ch2, ch3};
        StackArrT<T> st2;
        st2 = st1;
        CHECK(!st1.empty());
        CHECK(!st2.empty());
        CHECK_EQ(st2.size(), 3);
        CHECK_EQ(st2.top(), ch3);
        st2.pop();
        CHECK_EQ(st2.top(), ch2);
        CHECK_EQ(st2.size(), 2);
        CHECK_EQ(st1.size(), 3);
        CHECK_EQ(st1.top(), ch3);
        st2.pop();
        st2.pop();
        CHECK(!st1.empty());
        CHECK(st2.empty());
    }
    SUBCASE("Assignment with copy empty stack") {
        StackArrT<T> st3;
        StackArrT<T> st4 {ch1, ch2, ch3};
        st4 = st3;
        CHECK(st3.empty());
        CHECK(st4.empty());
        CHECK_EQ(st3.size(), size_empty);
        CHECK_EQ(st4.size(), size_empty);
    }
    SUBCASE("Assignment with move") {
        StackArrT<T> st1{ch1, ch2, ch3};
        StackArrT<T> st2;
        st2 = std::move(st1);
        CHECK(st1.empty());
        CHECK(!st2.empty());
        CHECK_EQ(st2.size(), 3);
        CHECK_EQ(st2.top(), ch3);
        st2.pop();
        CHECK_EQ(st2.top(), ch2);
        CHECK_EQ(st2.size(), 2);
        CHECK_EQ(st1.size(), size_empty);
        st2.pop();
        st2.pop();
        CHECK(st1.empty());
        CHECK(st2.empty());
    }
    SUBCASE("Assignment with move empty stack") {
        StackArrT<T> st3;
        StackArrT<T> st4 {ch1, ch2, ch3};
        st4 = std::move(st3);
        CHECK(!st3.empty());
        CHECK(st4.empty());
        CHECK_EQ(st3.size(), ch3);
        CHECK_EQ(st4.size(), size_empty);
    }
}

#include "unittest.hpp"

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("StackArrT", T, stackarrt) {
    StackArrT<T> stack;
    CHECK(stack.empty());

    std::vector<T> data;
    const int size = 4;
    FillData(size, data);

    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];

    stack.push(c1);
    CHECK(!stack.empty());
    CHECK_EQ(stack.top(), c1);
    stack.push(c2);
    CHECK_EQ(stack.top(), c2);
    stack.push(c3);
    CHECK_EQ(stack.top(), c3);

    StackArrT<T> stack_copy(stack);
    CHECK(!stack.empty());
    CHECK(!stack_copy.empty());
    CHECK_EQ(stack_copy.top(), c3);
    stack_copy.pop();
    CHECK_EQ(stack_copy.top(), c2);
    stack_copy.pop();
    CHECK_EQ(stack_copy.top(), c1);
    stack_copy.pop();
    CHECK(stack_copy.empty());

    StackArrT<T> stack_copy_assignment;
    stack_copy_assignment = stack;
    CHECK(!stack.empty());
    CHECK(!stack_copy_assignment.empty());
    CHECK_EQ(stack_copy_assignment.top(), c3);
    stack_copy_assignment.pop();
    CHECK_EQ(stack_copy_assignment.top(), c2);
    stack_copy_assignment.pop();
    CHECK_EQ(stack_copy_assignment.top(), c1);
    stack_copy_assignment.pop();
    CHECK(stack_copy_assignment.empty());

    CHECK_THROWS_WITH((void) stack_copy.top(), "StackArrT - try get top from empty stack.");
    CHECK_THROWS_WITH((void) stack_copy_assignment.top(), "StackArrT - try get top from empty stack.");

    StackArrT<T> stack2;
    stack2 = stack;

    StackArrT<T> stack_move(std::move(stack));
    CHECK(stack.empty());
    CHECK(!stack_move.empty());
    CHECK_EQ(stack_move.top(), c3);
    stack_move.pop();
    CHECK_EQ(stack_move.top(), c2);
    stack_move.pop();
    CHECK_EQ(stack_move.top(), c1);
    stack_move.pop();
    CHECK(stack_move.empty());

    StackArrT<T> stack_move_assignments;
    stack_move_assignments = std::move(stack2);
    CHECK(stack2.empty());
    CHECK(!stack_move_assignments.empty());
    CHECK_EQ(stack_move_assignments.top(), c3);
    CHECK_EQ(stack_move_assignments.top(), c3);
    stack_move_assignments.pop();
    CHECK_EQ(stack_move_assignments.top(), c2);
    stack_move_assignments.pop();
    CHECK_EQ(stack_move_assignments.top(), c1);
    stack_move_assignments.pop();
    CHECK(stack_move_assignments.empty());
}


TEST_CASE_TEMPLATE_INVOKE(stackarrt, TYPES);



