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
    BinarySearchTree bst;
    bst.add(ch1);
    bst.add(ch2);
    bst.add(ch3);
    bst.add(ch4);
    bst.add(ch5);
    bst.add(ch6);
    bst.add(ch7);

    SUBCASE("BinarySearchTree - root, add, has and find") {
        CHECK_THROWS_WITH(bst.add(ch1), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(bst.add(ch7), "BinarySearchTree - try add an existing element");
        SUBCASE("root and find") {
            CHECK_EQ(bst.root()->data, ch1);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.find(ch5)->data, ch5);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
            CHECK_THROWS_WITH(bst.find(ch8), "BinarySearchTree - try find an not existing element");
        }
        SUBCASE("root and has") {
            CHECK_EQ(bst.root()->data, ch1);
            CHECK_EQ(bst.has(ch1), true);
            CHECK_EQ(bst.has(ch2), true);
            CHECK_EQ(bst.has(ch3), true);
            CHECK_EQ(bst.has(ch4), true);
            CHECK_EQ(bst.has(ch5), true);
            CHECK_EQ(bst.has(ch6), true);
            CHECK_EQ(bst.has(ch7), true);
            CHECK_EQ(bst.has(ch8), false);
        }
    }

    SUBCASE("BinarySearchTree - remove and find") {
        SUBCASE("remove with two descendants") {
            bst.remove(ch2);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.has(ch2), false);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.has(ch4), true);
            CHECK_EQ(bst.has(ch5), true);
            CHECK_EQ(bst.has(ch6), true);
            CHECK_EQ(bst.has(ch7), true);
            CHECK_EQ(bst.has(ch8), false);
        }
        SUBCASE("remove with one descendant") {
            bst.remove(ch5);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.has(ch5), false);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
        }
        SUBCASE("remove with leaves") {
            bst.remove(ch3);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.has(ch3), false);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.find(ch5)->data, ch5);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
        }
    }

    SUBCASE("BinarySearchTree - min, max") {
        CHECK_EQ(bst.min(), ch3);
        CHECK_EQ(bst.max(), ch1);
        bst.remove(ch3);
        bst.remove(ch1);
        CHECK_EQ(bst.min(), ch2);
        CHECK_EQ(bst.max(), ch6);
        bst.remove(ch2);
        bst.remove(ch6);
        CHECK_EQ(bst.min(), ch5);
        CHECK_EQ(bst.max(), ch4);
        bst.remove(ch5);
        bst.remove(ch4);
        CHECK_EQ(bst.min(), ch7);
        CHECK_EQ(bst.max(), ch7);
        CHECK_THROWS_WITH(bst.remove(ch8), "BinarySearchTree - try remove an not existing element");
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
    BinarySearchTree bst;
    bst.add(ch1);
    bst.add(ch2);
    bst.add(ch3);
    bst.add(ch4);
    bst.add(ch5);
    bst.add(ch6);
    bst.add(ch7);

    SUBCASE("BinarySearchTree - root, add, has and find") {
        CHECK_THROWS_WITH(bst.add(ch1), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(bst.add(ch7), "BinarySearchTree - try add an existing element");
        SUBCASE("root and find") {
            CHECK_EQ(bst.root()->data, ch1);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.find(ch5)->data, ch5);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
            CHECK_THROWS_WITH(bst.find(ch8), "BinarySearchTree - try find an not existing element");
        }
        SUBCASE("root and has") {
            CHECK_EQ(bst.root()->data, ch1);
            CHECK_EQ(bst.has(ch1), true);
            CHECK_EQ(bst.has(ch2), true);
            CHECK_EQ(bst.has(ch3), true);
            CHECK_EQ(bst.has(ch4), true);
            CHECK_EQ(bst.has(ch5), true);
            CHECK_EQ(bst.has(ch6), true);
            CHECK_EQ(bst.has(ch7), true);
            CHECK_EQ(bst.has(ch8), false);
        }
    }

    SUBCASE("BinarySearchTree - remove and find") {
        SUBCASE("remove with two descendants") {
            bst.remove(ch2);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.has(ch2), false);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.has(ch4), true);
            CHECK_EQ(bst.has(ch5), true);
            CHECK_EQ(bst.has(ch6), true);
            CHECK_EQ(bst.has(ch7), true);
            CHECK_EQ(bst.has(ch8), false);
        }
        SUBCASE("remove with one descendant") {
            bst.remove(ch5);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.has(ch5), false);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
        }
        SUBCASE("remove with leaves") {
            bst.remove(ch3);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.has(ch3), false);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.find(ch5)->data, ch5);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
        }
    }

    SUBCASE("BinarySearchTree - min, max") {
        CHECK_EQ(bst.min(), ch1);
        CHECK_EQ(bst.max(), ch3);
        bst.remove(ch3);
        bst.remove(ch1);
        CHECK_EQ(bst.min(), ch5);
        CHECK_EQ(bst.max(), ch2);
        bst.remove(ch2);
        bst.remove(ch5);
        CHECK_EQ(bst.min(), ch7);
        CHECK_EQ(bst.max(), ch6);
        bst.remove(ch7);
        bst.remove(ch6);
        CHECK_EQ(bst.min(), ch4);
        CHECK_EQ(bst.max(), ch4);
        CHECK_THROWS_WITH(bst.remove(ch8), "BinarySearchTree - try remove an not existing element");
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

    BinarySearchTree bst;
    bst.add(ch1);
    bst.add(ch2);
    bst.add(ch3);
    bst.add(ch4);
    bst.add(ch5);
    bst.add(ch6);
    bst.add(ch7);

    bst.add(ch12);
    bst.add(ch13);
    bst.add(ch14);
    bst.add(ch15);
    bst.add(ch16);
    bst.add(ch17);

    SUBCASE("BinarySearchTree - root, add, has and find") {
        CHECK_THROWS_WITH(bst.add(ch1), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(bst.add(ch7), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(bst.add(ch12), "BinarySearchTree - try add an existing element");
        CHECK_THROWS_WITH(bst.add(ch17), "BinarySearchTree - try add an existing element");
        SUBCASE("root and find") {
            CHECK_EQ(bst.root()->data, ch1);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.find(ch5)->data, ch5);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);
            CHECK_THROWS_WITH(bst.find(ch8), "BinarySearchTree - try find an not existing element");

            CHECK_EQ(bst.find(ch12)->data, ch12);
            CHECK_EQ(bst.find(ch13)->data, ch13);
            CHECK_EQ(bst.find(ch14)->data, ch14);
            CHECK_EQ(bst.find(ch15)->data, ch15);
            CHECK_EQ(bst.find(ch16)->data, ch16);
            CHECK_EQ(bst.find(ch17)->data, ch17);
            CHECK_THROWS_WITH(bst.find(ch18), "BinarySearchTree - try find an not existing element");
        }
        SUBCASE("root and has") {
            CHECK_EQ(bst.root()->data, ch1);
            CHECK_EQ(bst.has(ch1), true);
            CHECK_EQ(bst.has(ch2), true);
            CHECK_EQ(bst.has(ch3), true);
            CHECK_EQ(bst.has(ch4), true);
            CHECK_EQ(bst.has(ch5), true);
            CHECK_EQ(bst.has(ch6), true);
            CHECK_EQ(bst.has(ch7), true);
            CHECK_EQ(bst.has(ch8), false);

            CHECK_EQ(bst.has(ch12), true);
            CHECK_EQ(bst.has(ch13), true);
            CHECK_EQ(bst.has(ch14), true);
            CHECK_EQ(bst.has(ch15), true);
            CHECK_EQ(bst.has(ch16), true);
            CHECK_EQ(bst.has(ch17), true);
            CHECK_EQ(bst.has(ch18), false);
        }
    }

    SUBCASE("BinarySearchTree - remove and find") {
        SUBCASE("remove with two descendants") {
            bst.remove(ch2);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.has(ch2), false);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.has(ch4), true);
            CHECK_EQ(bst.has(ch5), true);
            CHECK_EQ(bst.has(ch6), true);
            CHECK_EQ(bst.has(ch7), true);
            CHECK_EQ(bst.has(ch8), false);

            bst.remove(ch12);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.has(ch12), false);
            CHECK_EQ(bst.find(ch13)->data, ch13);
            CHECK_EQ(bst.has(ch14), true);
            CHECK_EQ(bst.has(ch15), true);
            CHECK_EQ(bst.has(ch16), true);
            CHECK_EQ(bst.has(ch17), true);
            CHECK_EQ(bst.has(ch18), false);
        }
        SUBCASE("remove with one descendant") {
            bst.remove(ch5);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.find(ch3)->data, ch3);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.has(ch5), false);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);

            bst.remove(ch15);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch12)->data, ch12);
            CHECK_EQ(bst.find(ch13)->data, ch13);
            CHECK_EQ(bst.find(ch14)->data, ch14);
            CHECK_EQ(bst.has(ch15), false);
            CHECK_EQ(bst.find(ch16)->data, ch16);
            CHECK_EQ(bst.find(ch17)->data, ch17);
        }
        SUBCASE("remove with leaves") {
            bst.remove(ch3);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch2)->data, ch2);
            CHECK_EQ(bst.has(ch3), false);
            CHECK_EQ(bst.find(ch4)->data, ch4);
            CHECK_EQ(bst.find(ch5)->data, ch5);
            CHECK_EQ(bst.find(ch6)->data, ch6);
            CHECK_EQ(bst.find(ch7)->data, ch7);

            bst.remove(ch13);
            CHECK_EQ(bst.find(ch1)->data, ch1);
            CHECK_EQ(bst.find(ch12)->data, ch12);
            CHECK_EQ(bst.has(ch13), false);
            CHECK_EQ(bst.find(ch14)->data, ch14);
            CHECK_EQ(bst.find(ch15)->data, ch15);
            CHECK_EQ(bst.find(ch16)->data, ch16);
            CHECK_EQ(bst.find(ch17)->data, ch17);
        }
    }

    SUBCASE("BinarySearchTree - min, max") {
        CHECK_EQ(bst.min(), ch3);
        CHECK_EQ(bst.max(), ch13);
        bst.remove(ch13);
        bst.remove(ch3);
        CHECK_EQ(bst.min(), ch2);
        CHECK_EQ(bst.max(), ch12);
        bst.remove(ch2);
        bst.remove(ch12);
        CHECK_EQ(bst.min(), ch5);
        CHECK_EQ(bst.max(), ch16);
        bst.remove(ch5);
        bst.remove(ch16);
        CHECK_EQ(bst.min(), ch7);
        CHECK_EQ(bst.max(), ch14);
        bst.remove(ch7);
        bst.remove(ch14);
        CHECK_EQ(bst.min(), ch4);
        CHECK_EQ(bst.max(), ch17);
        bst.remove(ch4);
        bst.remove(ch17);
        CHECK_EQ(bst.min(), ch6);
        CHECK_EQ(bst.max(), ch15);
        bst.remove(ch6);
        bst.remove(ch15);
        CHECK_EQ(bst.min(), ch1);
        CHECK_EQ(bst.max(), ch1);
        CHECK_THROWS_WITH(bst.remove(ch8), "BinarySearchTree - try remove an not existing element");
        CHECK_THROWS_WITH(bst.remove(ch18), "BinarySearchTree - try remove an not existing element");
    }
}