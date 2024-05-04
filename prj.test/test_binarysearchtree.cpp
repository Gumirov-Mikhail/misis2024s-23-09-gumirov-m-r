#include <binarysearchtree/binarysearchtree.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("BinarySearchTree - root, add, has and find") {
    int ch1 = 10;
    int ch2 = 5;
    int ch3 = 1;
    int ch4 = 8;
    int ch5 = 6;
    int ch6 = 9;
    int ch7 = 7;
    int ch8 = 17;
    BinarySearchTree tree;
    tree.add(ch1);
    tree.add(ch2);
    tree.add(ch3);
    tree.add(ch4);
    tree.add(ch5);
    tree.add(ch6);
    tree.add(ch7);
    CHECK_THROWS_WITH(tree.add(ch1), "BinarySearchTree - try add an existing element");
    CHECK_THROWS_WITH(tree.add(ch7), "BinarySearchTree - try add an existing element");
    SUBCASE("root and find") {
        CHECK_EQ(tree.root()->data, ch1);
        CHECK_EQ(tree.find(ch1)->data, ch1);
        CHECK_EQ(tree.find(ch2)->data, ch2);
        CHECK_EQ(tree.find(ch3)->data, ch3);
        CHECK_EQ(tree.find(ch4)->data, ch4);
        CHECK_EQ(tree.find(ch5)->data, ch5);
        CHECK_EQ(tree.find(ch6)->data, ch6);
        CHECK_EQ(tree.find(ch7)->data, ch7);
        CHECK_THROWS_WITH(tree.find(ch8), "BinarySearchTree - try find an not existing element");
    }
    SUBCASE("root and has") {
        CHECK_EQ(tree.root()->data, ch1);
        CHECK_EQ(tree.has(ch1), true);
        CHECK_EQ(tree.has(ch2), true);
        CHECK_EQ(tree.has(ch3), true);
        CHECK_EQ(tree.has(ch4), true);
        CHECK_EQ(tree.has(ch5), true);
        CHECK_EQ(tree.has(ch6), true);
        CHECK_EQ(tree.has(ch7), true);
        CHECK_EQ(tree.has(ch8), false);
    }
}

TEST_CASE("BinarySearchTree - remove and find") {
    int ch1 = 10;
    int ch2 = 5;
    int ch3 = 1;
    int ch4 = 8;
    int ch5 = 6;
    int ch6 = 9;
    int ch7 = 7;
    int ch8 = 17;
    BinarySearchTree tree;
    tree.add(ch1);
    tree.add(ch2);
    tree.add(ch3);
    tree.add(ch4);
    tree.add(ch5);
    tree.add(ch6);
    tree.add(ch7);
    SUBCASE("remove with two descendants") {
        tree.remove(ch2);
        CHECK_EQ(tree.find(ch1)->data, ch1);
        CHECK_EQ(tree.has(ch2), false);
        CHECK_EQ(tree.find(ch3)->data, ch3);
        CHECK_EQ(tree.has(ch4), true);
        CHECK_EQ(tree.has(ch5), true);
        CHECK_EQ(tree.has(ch6), true);
        CHECK_EQ(tree.has(ch7), true);
        CHECK_EQ(tree.has(ch8), false);
    }
    SUBCASE("remove with one descendant") {
        tree.remove(ch5);
        CHECK_EQ(tree.find(ch1)->data, ch1);
        CHECK_EQ(tree.find(ch2)->data, ch2);
        CHECK_EQ(tree.find(ch3)->data, ch3);
        CHECK_EQ(tree.find(ch4)->data, ch4);
        CHECK_EQ(tree.has(ch5), false);
        CHECK_EQ(tree.find(ch6)->data, ch6);
        CHECK_EQ(tree.find(ch7)->data, ch7);
    }
    SUBCASE("remove with leaves") {
        tree.remove(ch3);
        CHECK_EQ(tree.find(ch1)->data, ch1);
        CHECK_EQ(tree.find(ch2)->data, ch2);
        CHECK_EQ(tree.has(ch3), false);
        CHECK_EQ(tree.find(ch4)->data, ch4);
        CHECK_EQ(tree.find(ch5)->data, ch5);
        CHECK_EQ(tree.find(ch6)->data, ch6);
        CHECK_EQ(tree.find(ch7)->data, ch7);
    }
}

TEST_CASE("BinarySearchTree - min, max") {
    int ch1 = 10;
    int ch2 = 5;
    int ch3 = 1;
    int ch4 = 8;
    int ch5 = 6;
    int ch6 = 9;
    int ch7 = 7;
    BinarySearchTree tree;
    tree.add(ch1);
    tree.add(ch2);
    tree.add(ch3);
    tree.add(ch4);
    tree.add(ch5);
    tree.add(ch6);
    tree.add(ch7);
    CHECK_EQ(tree.min(), ch3);
    CHECK_EQ(tree.max(), ch1);
    tree.remove(ch3);
    tree.remove(ch1);
    CHECK_EQ(tree.min(), ch2);
    CHECK_EQ(tree.max(), ch6);
    tree.remove(ch2);
    tree.remove(ch6);
    CHECK_EQ(tree.min(), ch5);
    CHECK_EQ(tree.max(), ch4);
    tree.remove(ch5);
    tree.remove(ch4);
    CHECK_EQ(tree.min(), ch7);
    CHECK_EQ(tree.max(), ch7);
}