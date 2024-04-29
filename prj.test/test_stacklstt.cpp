#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stacklstt/stacklstt.hpp>

#define TYPE_TEST int, float, double, long long

TEST_CASE_TEMPLATE("StackLstT - Constructors", T, TYPE_TEST) {
    int size_empty = 0;
    T ch1 = 1;
    T ch2 = 2;
    T ch3 = 3;
    T ch4 = 4;
    SUBCASE("Default constructor") {
        StackLstT<T> ctor;
        CHECK(ctor.empty());
        CHECK_EQ(ctor.size(), size_empty);
    }
    SUBCASE("Constructor copy") {
        StackLstT<T> ctor_copy1;
        ctor_copy1.push(ch1);
        ctor_copy1.push(ch4);
        StackLstT<T> ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.top(), ch4);
        CHECK_EQ(ctor_copy2.size(), 2);
    }
    SUBCASE("Constructor move") {
        StackLstT<T> ctor_move1;
        ctor_move1.push(ch1);
        ctor_move1.push(ch4);
        StackLstT<T> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK(!ctor_move2.empty());
        CHECK_EQ(ctor_move2.top(), ch4);
        CHECK_EQ(ctor_move2.size(), 2);
    }
    SUBCASE("Initializer list") {
        StackLstT<T> init_list {ch1, ch2, ch3, ch4};
        CHECK(!init_list.empty());
        CHECK_EQ(init_list.top(), ch4);
        CHECK_EQ(init_list.size(), 4);
    }
    SUBCASE("Constructor copy with empty stack") {
        StackLstT<T> ctor_copy1;
        StackLstT<T> ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.empty());
        CHECK(ctor_copy2.empty());
        CHECK_EQ(ctor_copy2.size(), size_empty);
    }
    SUBCASE("Constructor move with empty stack") {
        StackLstT<T> ctor_move1;
        StackLstT<T> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty());
        CHECK(ctor_move2.empty());
        CHECK_EQ(ctor_move1.size(), size_empty);
        CHECK_EQ(ctor_move2.size(), size_empty);
    }
}

TEST_CASE_TEMPLATE("StackLstT - Push, Pop and Top", T, TYPE_TEST) {
    int size_empty = 0;
    T ch1 = 1;
    T ch2 = 2;
    T ch3 = 3;
    T ch4 = 4;
    SUBCASE("Push and Pop") {
        StackLstT<T> st1;
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
        StackLstT<T> st1;
        CHECK_THROWS_WITH(st1.pop(), "StackLstT - try pop from empty stack.");
        CHECK_THROWS_WITH(st1.top(), "StackLstT - try get top from empty stack.");
        st1.push(ch4);
        CHECK_EQ(st1.top(), ch4);
        CHECK_EQ(st1.size(), 1);
        st1.pop();
        CHECK_THROWS_WITH(st1.pop(), "StackLstT - try pop from empty stack.");
        CHECK_THROWS_WITH(st1.top(), "StackLstT - try get top from empty stack.");
    }
}

TEST_CASE_TEMPLATE("StackLstT - Swap and Merge", T, TYPE_TEST) {
    T ch1 = 5;
    T ch2 = 4;
    T ch3 = 3;
    T ch4 = 6;
    T ch5 = 7;
    T ch6 = 8;
    SUBCASE("Swap") {
        StackLstT<T> st1 {ch1, ch2, ch3};
        StackLstT<T> st2 {ch1, ch2, ch3};
        StackLstT<T> st3;
        StackLstT<T> st4 {ch2, ch3, ch4};
        st1.swap(st3);
        CHECK(st3 == st2);
        CHECK(st1.empty());
        st2.swap(st4);
        CHECK(st3 == st4);
        CHECK(st2 != st3);
    }
    SUBCASE("Merge") {
        StackLstT<T> st_merge {ch1, ch2, ch3, ch4, ch5, ch6};
        StackLstT<T> st_merge_empty;
        SUBCASE("Default Merge") {
            StackLstT<T> st1 {ch1, ch2, ch3};
            StackLstT<T> st2 {ch4, ch5, ch6};
            st1.merge(st2);
            CHECK((st1 == st_merge));
        }
        SUBCASE("Merge empty and full") {
            StackLstT<T> st3;
            StackLstT<T> st4 {ch1, ch2, ch3, ch4, ch5, ch6};
            st3.merge(st4);
            CHECK(st3 == st_merge);
        }
        SUBCASE("Merge full and empty") {
            StackLstT<T> st5{ch1, ch2, ch3, ch4, ch5, ch6};
            StackLstT<T> st6;
            st5.merge(st6);
            CHECK(st5 == st_merge);
        }
        SUBCASE("Merge empty and empty") {
            StackLstT<T> st7;
            StackLstT<T> st8;
            st7.merge(st8);
            CHECK(st7 == st_merge_empty);
        }
    }
}

TEST_CASE_TEMPLATE("StackLstT - Compare", T, TYPE_TEST) {
    T ch1 = 5;
    T ch2 = 4;
    T ch3 = 3;
    T ch4 = 1;
    SUBCASE("Compare with not empty stack") {
        StackLstT<T> st1 {ch1, ch2, ch3};
        StackLstT<T> st2 {ch1, ch2, ch3};
        StackLstT<T> st3 {ch1, ch2, ch4};
        CHECK(st1 == st2);
        CHECK(st1 != st3);
        CHECK(st2 != st3);
        CHECK(!(st1 != st2));
        CHECK(!(st1 == st3));
        CHECK(!(st2 == st3));
    }
    SUBCASE("Compare with empty stack") {
        StackLstT<T> st1 {ch1, ch2, ch3};
        StackLstT<T> st2;
        StackLstT<T> st3;
        CHECK(st1 != st2);
        CHECK(st1 != st3);
        CHECK(st2 == st3);
        CHECK(!(st1 == st2));
        CHECK(!(st1 == st3));
        CHECK(!(st2 != st3));
    }
}

TEST_CASE_TEMPLATE("StackLstT - Assignment", T, TYPE_TEST) {
    int size_empty = 0;
    T ch1 = 5;
    T ch2 = 4;
    T ch3 = 3;
    T ch4 = 1;
    SUBCASE("Assignment with copy") {
        StackLstT<T> st1{ch1, ch2, ch3};
        StackLstT<T> st2;
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
        StackLstT<T> st3;
        StackLstT<T> st4 {ch1, ch2, ch3};
        st4 = st3;
        CHECK(st3.empty());
        CHECK(st4.empty());
        CHECK_EQ(st3.size(), size_empty);
        CHECK_EQ(st4.size(), size_empty);
    }
    SUBCASE("Assignment with move") {
        StackLstT<T> st1{ch1, ch2, ch3};
        StackLstT<T> st2;
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
        StackLstT<T> st3;
        StackLstT<T> st4 {ch1, ch2, ch3};
        st4 = std::move(st3);
        CHECK(!st3.empty());
        CHECK(st4.empty());
        CHECK_EQ(st3.size(), ch3);
        CHECK_EQ(st4.size(), size_empty);
    }
}





