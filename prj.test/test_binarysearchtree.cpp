#include <binarysearchtree/binarysearchtree.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("BinarySearchTree - tree only with left-hand side") {
    int ch1 = 10;
    int ch2 = 5;
    int ch3 = 1;
    int ch4 = 8;
    int ch5 = 6;
    int ch6 = 9;
    int ch7 = 7;
    int ch8 = 17;
    // example tree only with left-hand side
    //         10
    //      5
    //    1    8
    //       6   9
    //        7
    BinarySearchTree tree_number_one;
    tree_number_one.add(ch1);
    tree_number_one.add(ch2);
    tree_number_one.add(ch3);
    tree_number_one.add(ch4);
    tree_number_one.add(ch5);
    tree_number_one.add(ch6);
    tree_number_one.add(ch7);
    SUBCASE("BinarySearchTree - root, add, has and find") {
        CHECK_THROWS_WITH(tree_number_one.add(ch1), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(tree_number_one.add(ch7), "BinarySearchTree - try add an existing element");
        SUBCASE("root and find") {
            CHECK_EQ(tree_number_one.root()->data, ch1);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.find(ch5)->data, ch5);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
            CHECK_THROWS_WITH(tree_number_one.find(ch8), "BinarySearchTree - try find an not existing element");
        }
        SUBCASE("root and has") {
            CHECK_EQ(tree_number_one.root()->data, ch1);
            CHECK_EQ(tree_number_one.has(ch1), true);
            CHECK_EQ(tree_number_one.has(ch2), true);
            CHECK_EQ(tree_number_one.has(ch3), true);
            CHECK_EQ(tree_number_one.has(ch4), true);
            CHECK_EQ(tree_number_one.has(ch5), true);
            CHECK_EQ(tree_number_one.has(ch6), true);
            CHECK_EQ(tree_number_one.has(ch7), true);
            CHECK_EQ(tree_number_one.has(ch8), false);
        }
    }
    SUBCASE("BinarySearchTree - remove and find") {
        SUBCASE("remove with two descendants") {
            tree_number_one.remove(ch2);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.has(ch2), false);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.has(ch4), true);
            CHECK_EQ(tree_number_one.has(ch5), true);
            CHECK_EQ(tree_number_one.has(ch6), true);
            CHECK_EQ(tree_number_one.has(ch7), true);
            CHECK_EQ(tree_number_one.has(ch8), false);
        }
        SUBCASE("remove with one descendant") {
            tree_number_one.remove(ch5);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.has(ch5), false);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
        }
        SUBCASE("remove with leaves") {
            tree_number_one.remove(ch3);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.has(ch3), false);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.find(ch5)->data, ch5);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
        }
    }
    BinarySearchTree tree_number_two;
    tree_number_two.add(ch1);
    tree_number_two.add(ch2);
    tree_number_two.add(ch3);
    tree_number_two.add(ch4);
    tree_number_two.add(ch5);
    tree_number_two.add(ch6);
    tree_number_two.add(ch7);
    SUBCASE("BinarySearchTree - min, max") {
        CHECK_EQ(tree_number_two.min(), ch3);
        CHECK_EQ(tree_number_two.max(), ch1);
        tree_number_two.remove(ch3);
        tree_number_two.remove(ch1);
        CHECK_EQ(tree_number_two.min(), ch2);
        CHECK_EQ(tree_number_two.max(), ch6);
        tree_number_two.remove(ch2);
        tree_number_two.remove(ch6);
        CHECK_EQ(tree_number_two.min(), ch5);
        CHECK_EQ(tree_number_two.max(), ch4);
        tree_number_two.remove(ch5);
        tree_number_two.remove(ch4);
        CHECK_EQ(tree_number_two.min(), ch7);
        CHECK_EQ(tree_number_two.max(), ch7);
        CHECK_THROWS_WITH(tree_number_two.remove(ch8), "BinarySearchTree - try remove an not existing element");
    }
}



TEST_CASE("BinarySearchTree - tree only with right-hand side") {
    int ch1 = 10;
    int ch2 = 15;
    int ch3 = 20;
    int ch4 = 13;
    int ch5 = 11;
    int ch6 = 14;
    int ch7 = 12;
    int ch8 = 17;
    // example tree only with right-hand side
    //        10
    //               15
    //           13      20
    //        11    14
    //          12
    BinarySearchTree tree_number_one;
    tree_number_one.add(ch1);
    tree_number_one.add(ch2);
    tree_number_one.add(ch3);
    tree_number_one.add(ch4);
    tree_number_one.add(ch5);
    tree_number_one.add(ch6);
    tree_number_one.add(ch7);
    SUBCASE("BinarySearchTree - root, add, has and find") {
        CHECK_THROWS_WITH(tree_number_one.add(ch1), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(tree_number_one.add(ch7), "BinarySearchTree - try add an existing element");
        SUBCASE("root and find") {
            CHECK_EQ(tree_number_one.root()->data, ch1);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.find(ch5)->data, ch5);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
            CHECK_THROWS_WITH(tree_number_one.find(ch8), "BinarySearchTree - try find an not existing element");
        }
        SUBCASE("root and has") {
            CHECK_EQ(tree_number_one.root()->data, ch1);
            CHECK_EQ(tree_number_one.has(ch1), true);
            CHECK_EQ(tree_number_one.has(ch2), true);
            CHECK_EQ(tree_number_one.has(ch3), true);
            CHECK_EQ(tree_number_one.has(ch4), true);
            CHECK_EQ(tree_number_one.has(ch5), true);
            CHECK_EQ(tree_number_one.has(ch6), true);
            CHECK_EQ(tree_number_one.has(ch7), true);
            CHECK_EQ(tree_number_one.has(ch8), false);
        }
    }
    SUBCASE("BinarySearchTree - remove and find") {
        SUBCASE("remove with two descendants") {
            tree_number_one.remove(ch2);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.has(ch2), false);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.has(ch4), true);
            CHECK_EQ(tree_number_one.has(ch5), true);
            CHECK_EQ(tree_number_one.has(ch6), true);
            CHECK_EQ(tree_number_one.has(ch7), true);
            CHECK_EQ(tree_number_one.has(ch8), false);
        }
        SUBCASE("remove with one descendant") {
            tree_number_one.remove(ch5);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.has(ch5), false);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
        }
        SUBCASE("remove with leaves") {
            tree_number_one.remove(ch3);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.has(ch3), false);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.find(ch5)->data, ch5);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
        }
    }
    BinarySearchTree tree_number_two;
    tree_number_two.add(ch1);
    tree_number_two.add(ch2);
    tree_number_two.add(ch3);
    tree_number_two.add(ch4);
    tree_number_two.add(ch5);
    tree_number_two.add(ch6);
    tree_number_two.add(ch7);
    SUBCASE("BinarySearchTree - min, max") {
        CHECK_EQ(tree_number_two.min(), ch1);
        CHECK_EQ(tree_number_two.max(), ch3);
        tree_number_two.remove(ch3);
        tree_number_two.remove(ch1);
        CHECK_EQ(tree_number_two.min(), ch5);
        CHECK_EQ(tree_number_two.max(), ch2);
        tree_number_two.remove(ch2);
        tree_number_two.remove(ch5);
        CHECK_EQ(tree_number_two.min(), ch7);
        CHECK_EQ(tree_number_two.max(), ch6);
        tree_number_two.remove(ch7);
        tree_number_two.remove(ch6);
        CHECK_EQ(tree_number_two.min(), ch4);
        CHECK_EQ(tree_number_two.max(), ch4);
        CHECK_THROWS_WITH(tree_number_two.remove(ch8), "BinarySearchTree - try remove an not existing element");
    }
}



TEST_CASE("BinarySearchTree - empty tree") {
    int ch1 = 10;
    int ch2 = 20;
    BinarySearchTree bst;
    SUBCASE("Checking throws") {
        CHECK_THROWS_WITH(bst.min(), "BinarySearchTree - try get min from empty tree");
        CHECK_THROWS_WITH(bst.max(), "BinarySearchTree - try get max from empty tree");
        CHECK_THROWS_WITH(bst.remove(ch1), "BinarySearchTree - try remove from empty tree");
        CHECK_THROWS_WITH(bst.find(ch1), "BinarySearchTree - try find an not existing element");
        bst.add(ch1);
        bst.add(ch2);
        bst.remove(ch1);
        bst.remove(ch2);
        CHECK_THROWS_WITH(bst.min(), "BinarySearchTree - try get min from empty tree");
        CHECK_THROWS_WITH(bst.max(), "BinarySearchTree - try get max from empty tree");
        CHECK_THROWS_WITH(bst.remove(ch1), "BinarySearchTree - try remove from empty tree");
        CHECK_THROWS_WITH(bst.find(ch1), "BinarySearchTree - try find an not existing element");
    }
}



TEST_CASE("BinarySearchTree - tree with both sides") {
    int ch1 = 10;
    int ch2 = 5;
    int ch3 = 1;
    int ch4 = 8;
    int ch5 = 6;
    int ch6 = 9;
    int ch7 = 7;
    int ch8 = 17;

    int ch12 = 15;
    int ch13 = 20;
    int ch14 = 13;
    int ch15 = 11;
    int ch16 = 14;
    int ch17 = 12;
    int ch18 = 17;
    // example with both sides
    //             10
    //      5                15
    //    1    8         13      20
    //       6   9    11    14
    //        7         12

    BinarySearchTree tree_number_one;
    tree_number_one.add(ch1);
    tree_number_one.add(ch2);
    tree_number_one.add(ch3);
    tree_number_one.add(ch4);
    tree_number_one.add(ch5);
    tree_number_one.add(ch6);
    tree_number_one.add(ch7);

    tree_number_one.add(ch12);
    tree_number_one.add(ch13);
    tree_number_one.add(ch14);
    tree_number_one.add(ch15);
    tree_number_one.add(ch16);
    tree_number_one.add(ch17);

    SUBCASE("BinarySearchTree - root, add, has and find") {
        CHECK_THROWS_WITH(tree_number_one.add(ch1), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(tree_number_one.add(ch7), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(tree_number_one.add(ch12), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(tree_number_one.add(ch17), "BinarySearchTree - try add an existing element");
        SUBCASE("root and find") {
            CHECK_EQ(tree_number_one.root()->data, ch1);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.find(ch5)->data, ch5);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);
            CHECK_THROWS_WITH(tree_number_one.find(ch8), "BinarySearchTree - try find an not existing element");

            CHECK_EQ(tree_number_one.find(ch12)->data, ch12);
            CHECK_EQ(tree_number_one.find(ch13)->data, ch13);
            CHECK_EQ(tree_number_one.find(ch14)->data, ch14);
            CHECK_EQ(tree_number_one.find(ch15)->data, ch15);
            CHECK_EQ(tree_number_one.find(ch16)->data, ch16);
            CHECK_EQ(tree_number_one.find(ch17)->data, ch17);
            CHECK_THROWS_WITH(tree_number_one.find(ch18), "BinarySearchTree - try find an not existing element");
        }
        SUBCASE("root and has") {
            CHECK_EQ(tree_number_one.root()->data, ch1);
            CHECK_EQ(tree_number_one.has(ch1), true);
            CHECK_EQ(tree_number_one.has(ch2), true);
            CHECK_EQ(tree_number_one.has(ch3), true);
            CHECK_EQ(tree_number_one.has(ch4), true);
            CHECK_EQ(tree_number_one.has(ch5), true);
            CHECK_EQ(tree_number_one.has(ch6), true);
            CHECK_EQ(tree_number_one.has(ch7), true);
            CHECK_EQ(tree_number_one.has(ch8), false);

            CHECK_EQ(tree_number_one.has(ch12), true);
            CHECK_EQ(tree_number_one.has(ch13), true);
            CHECK_EQ(tree_number_one.has(ch14), true);
            CHECK_EQ(tree_number_one.has(ch15), true);
            CHECK_EQ(tree_number_one.has(ch16), true);
            CHECK_EQ(tree_number_one.has(ch17), true);
            CHECK_EQ(tree_number_one.has(ch18), false);
        }
    }
    SUBCASE("BinarySearchTree - remove and find") {
        SUBCASE("remove with two descendants") {
            tree_number_one.remove(ch2);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.has(ch2), false);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.has(ch4), true);
            CHECK_EQ(tree_number_one.has(ch5), true);
            CHECK_EQ(tree_number_one.has(ch6), true);
            CHECK_EQ(tree_number_one.has(ch7), true);
            CHECK_EQ(tree_number_one.has(ch8), false);

            tree_number_one.remove(ch12);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.has(ch12), false);
            CHECK_EQ(tree_number_one.find(ch13)->data, ch13);
            CHECK_EQ(tree_number_one.has(ch14), true);
            CHECK_EQ(tree_number_one.has(ch15), true);
            CHECK_EQ(tree_number_one.has(ch16), true);
            CHECK_EQ(tree_number_one.has(ch17), true);
            CHECK_EQ(tree_number_one.has(ch18), false);
        }
        SUBCASE("remove with one descendant") {
            tree_number_one.remove(ch5);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.find(ch3)->data, ch3);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.has(ch5), false);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);

            tree_number_one.remove(ch15);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch12)->data, ch12);
            CHECK_EQ(tree_number_one.find(ch13)->data, ch13);
            CHECK_EQ(tree_number_one.find(ch14)->data, ch14);
            CHECK_EQ(tree_number_one.has(ch15), false);
            CHECK_EQ(tree_number_one.find(ch16)->data, ch16);
            CHECK_EQ(tree_number_one.find(ch17)->data, ch17);
        }
        SUBCASE("remove with leaves") {
            tree_number_one.remove(ch3);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch2)->data, ch2);
            CHECK_EQ(tree_number_one.has(ch3), false);
            CHECK_EQ(tree_number_one.find(ch4)->data, ch4);
            CHECK_EQ(tree_number_one.find(ch5)->data, ch5);
            CHECK_EQ(tree_number_one.find(ch6)->data, ch6);
            CHECK_EQ(tree_number_one.find(ch7)->data, ch7);

            tree_number_one.remove(ch13);
            CHECK_EQ(tree_number_one.find(ch1)->data, ch1);
            CHECK_EQ(tree_number_one.find(ch12)->data, ch12);
            CHECK_EQ(tree_number_one.has(ch13), false);
            CHECK_EQ(tree_number_one.find(ch14)->data, ch14);
            CHECK_EQ(tree_number_one.find(ch15)->data, ch15);
            CHECK_EQ(tree_number_one.find(ch16)->data, ch16);
            CHECK_EQ(tree_number_one.find(ch17)->data, ch17);
        }
    }

    BinarySearchTree tree_number_two;
    tree_number_two.add(ch1);
    tree_number_two.add(ch2);
    tree_number_two.add(ch3);
    tree_number_two.add(ch4);
    tree_number_two.add(ch5);
    tree_number_two.add(ch6);
    tree_number_two.add(ch7);

    tree_number_two.add(ch12);
    tree_number_two.add(ch13);
    tree_number_two.add(ch14);
    tree_number_two.add(ch15);
    tree_number_two.add(ch16);
    tree_number_two.add(ch17);

    SUBCASE("BinarySearchTree - min, max") {
        CHECK_EQ(tree_number_two.min(), ch3);
        CHECK_EQ(tree_number_two.max(), ch13);
        tree_number_two.remove(ch13);
        tree_number_two.remove(ch3);
        CHECK_EQ(tree_number_two.min(), ch2);
        CHECK_EQ(tree_number_two.max(), ch12);
        tree_number_two.remove(ch2);
        tree_number_two.remove(ch12);
        CHECK_EQ(tree_number_two.min(), ch5);
        CHECK_EQ(tree_number_two.max(), ch16);
        tree_number_two.remove(ch5);
        tree_number_two.remove(ch16);
        CHECK_EQ(tree_number_two.min(), ch7);
        CHECK_EQ(tree_number_two.max(), ch14);
        tree_number_two.remove(ch7);
        tree_number_two.remove(ch14);
        CHECK_EQ(tree_number_two.min(), ch4);
        CHECK_EQ(tree_number_two.max(), ch17);
        tree_number_two.remove(ch4);
        tree_number_two.remove(ch17);
        CHECK_EQ(tree_number_two.min(), ch6);
        CHECK_EQ(tree_number_two.max(), ch15);
        tree_number_two.remove(ch6);
        tree_number_two.remove(ch15);
        CHECK_EQ(tree_number_two.min(), ch1);
        CHECK_EQ(tree_number_two.max(), ch1);
        CHECK_THROWS_WITH(tree_number_two.remove(ch8), "BinarySearchTree - try remove an not existing element");
        CHECK_THROWS_WITH(tree_number_two.remove(ch18), "BinarySearchTree - try remove an not existing element");
    }
}