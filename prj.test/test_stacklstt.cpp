#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <stacklstt/stacklstt.hpp>

TEST_CASE_TEMPLATE("StackLstT - Constructors", T, int, float, double, long long) {
    SUBCASE("Default constructor") {
        StackLstT<T> ctor;
        CHECK(ctor.empty() == true);
        CHECK(ctor.size() == 0);
    }
    SUBCASE("Constructor copy") {
        StackLstT<T> ctor_copy1;
        ctor_copy1.push(1);
        ctor_copy1.push(5);
        StackLstT<T> ctor_copy2(ctor_copy1);
        CHECK(ctor_copy2.empty() == false);
        CHECK(ctor_copy2.top() == 5);
        CHECK(ctor_copy2.size() == 2);
    }
    SUBCASE("Constructor move") {
        StackLstT<T> ctor_move1;
        ctor_move1.push(1);
        ctor_move1.push(5);
        StackLstT<T> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty() == true);
        CHECK(ctor_move2.empty() == false);
        CHECK(ctor_move2.top() == 5);
        CHECK(ctor_move2.size() == 2);
    }
    SUBCASE("Initializer list") {
        StackLstT<T> init_list {1, 2, 3, 4};
        CHECK(init_list.empty() == false);
        CHECK(init_list.top() == 4);
        CHECK(init_list.size() == 4);
    }
    SUBCASE("Constructor copy with empty stack") {
        StackLstT<T> ctor_copy1;
        StackLstT<T> ctor_copy2(ctor_copy1);
        CHECK(ctor_copy1.empty() == true);
        CHECK(ctor_copy2.empty() == true);
        CHECK(ctor_copy2.size() == 0);
    }
    SUBCASE("Constructor move with empty stack") {
        StackLstT<T> ctor_move1;
        StackLstT<T> ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move1.empty() == true);
        CHECK(ctor_move2.empty() == true);
        CHECK(ctor_move1.size() == 0);
        CHECK(ctor_move2.size() == 0);
    }
}

TEST_CASE_TEMPLATE("StackLstT - Push, Pop and Top", T, int, float, double, long long) {
    SUBCASE("Push and Pop") {
        StackLstT<T> st1;
        CHECK(st1.empty() == true);
        CHECK(st1.size() == 0);
        st1.push(5);
        CHECK(st1.top() == 5);
        CHECK(st1.size() == 1);
        st1.push(4);
        CHECK(st1.top() == 4);
        CHECK(st1.size() == 2);
        st1.pop();
        CHECK(st1.top() == 5);
        CHECK(st1.size() == 1);
        st1.pop();
        CHECK(st1.empty() == true);
        CHECK(st1.size() == 0);
    }
    SUBCASE("Pop and Top with empty stack") {
        StackLstT<T> st1;
        CHECK_THROWS_WITH(st1.pop(), "StackLstT - try pop from empty stack.");
        CHECK_THROWS_WITH(st1.top(), "StackLstT - try get top from empty stack.");
        st1.push(5);
        CHECK(st1.top() == 5);
        CHECK(st1.size() == 1);
        st1.pop();
        CHECK_THROWS_WITH(st1.pop(), "StackLstT - try pop from empty stack.");
        CHECK_THROWS_WITH(st1.top(), "StackLstT - try get top from empty stack.");
    }
}

TEST_CASE_TEMPLATE("StackLstT - Swap and Merge", T, int, float, double, long long) {
    SUBCASE("Swap") {
        StackLstT<T> st1 {5, 4, 3};
        StackLstT<T> st2 {5, 4, 3};
        StackLstT<T> st3;
        StackLstT<T> st4 {4, 3, 2};
        st1.swap(st3);
        CHECK((st3 == st2) == true);
        CHECK(st1.empty() == true);
        st2.swap(st4);
        CHECK((st3 == st4) == true);
        CHECK((st2 != st3) == true);
    }
    SUBCASE("Merge") {
        StackLstT<T> st_merge {5, 4, 3, 6, 7, 8};
        StackLstT<T> st_merge_empty;
        SUBCASE("Default Merge") {
            StackLstT<T> st1 {5, 4, 3};
            StackLstT<T> st2 {6, 7, 8};
            st1.merge(st2);
            CHECK((st1 == st_merge) == true);
        }
        SUBCASE("Merge empty and full") {
            StackLstT<T> st3;
            StackLstT<T> st4 {5, 4, 3, 6, 7, 8};
            st3.merge(st4);
            CHECK((st3 == st_merge) == true);
        }
        SUBCASE("Merge full and empty") {
            StackLstT<T> st5{5, 4, 3, 6, 7, 8};
            StackLstT<T> st6;
            st5.merge(st6);
            CHECK((st5 == st_merge) == true);
        }
        SUBCASE("Merge empty and empty") {
            StackLstT<T> st7;
            StackLstT<T> st8;
            st7.merge(st8);
            CHECK((st7 == st_merge_empty) == true);
        }
    }
}

TEST_CASE_TEMPLATE("StackLstT - Compare", T, int, float, double, long long) {
    SUBCASE("Compare with not empty stack") {
        StackLstT<T> st1 {5, 4, 3};
        StackLstT<T> st2 {5, 4, 3};
        StackLstT<T> st3 {5, 4, 1};
        CHECK((st1 == st2) == true);
        CHECK((st1 != st3) == true);
        CHECK((st2 != st3) == true);
        CHECK((st1 != st2) == false);
        CHECK((st1 == st3) == false);
        CHECK((st2 == st3) == false);
    }
    SUBCASE("Compare with empty stack") {
        StackLstT<T> st1 {5, 4, 3};
        StackLstT<T> st2;
        StackLstT<T> st3;
        CHECK((st1 != st2) == true);
        CHECK((st1 != st3) == true);
        CHECK((st2 == st3) == true);
        CHECK((st1 == st2) == false);
        CHECK((st1 == st3) == false);
        CHECK((st2 != st3) == false);
    }
}

TEST_CASE_TEMPLATE("StackLstT - Assignment", T, int, float, double, long long) {
    SUBCASE("Assignment with copy") {
        StackLstT<T> st1{5, 4, 3};
        StackLstT<T> st2;
        st2 = st1;
        CHECK(st1.empty() == false);
        CHECK(st2.empty() == false);
        CHECK(st2.size() == 3);
        CHECK(st2.top() == 3);
        st2.pop();
        CHECK(st2.top() == 4);
        CHECK(st2.size() == 2);
        CHECK(st1.size() == 3);
        CHECK(st1.top() == 3);
        st2.pop();
        st2.pop();
        CHECK(st1.empty() == false);
        CHECK(st2.empty() == true);
    }
    SUBCASE("Assignment with copy empty stack") {
        StackLstT<T> st3;
        StackLstT<T> st4 {5, 4, 3};
        st4 = st3;
        CHECK(st3.empty() == true);
        CHECK(st4.empty() == true);
        CHECK(st3.size() == 0);
        CHECK(st4.size() == 0);
    }
    SUBCASE("Assignment with move") {
        StackLstT<T> st1{5, 4, 3};
        StackLstT<T> st2;
        st2 = std::move(st1);
        CHECK(st1.empty() == true);
        CHECK(st2.empty() == false);
        CHECK(st2.size() == 3);
        CHECK(st2.top() == 3);
        st2.pop();
        CHECK(st2.top() == 4);
        CHECK(st2.size() == 2);
        CHECK(st1.size() == 0);
        st2.pop();
        st2.pop();
        CHECK(st1.empty() == true);
        CHECK(st2.empty() == true);
    }
    SUBCASE("Assignment with move empty stack") {
        StackLstT<T> st3;
        StackLstT<T> st4 {5, 4, 3};
        st4 = std::move(st3);
        CHECK(st3.empty() == false);
        CHECK(st4.empty() == true);
        CHECK(st3.size() == 3);
        CHECK(st4.size() == 0);
    }
}





