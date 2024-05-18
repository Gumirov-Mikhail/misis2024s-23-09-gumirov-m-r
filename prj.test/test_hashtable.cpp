#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <hashtable/hashtable.hpp>

TEST_CASE_TEMPLATE("HashTable - types of numbers ", T, int, float, double, long long) {
    T num1 = 1;
    T num2 = 2;
    T num3 = 3;
    T num4 = 12;
    hashTable<T, T> h;
    hashTable<T, T> t(20);
    SUBCASE("Insert and Contains") {
        h.insert(num1, num1);
        h.insert(num2, num2);
        h.insert(num4, num4);
        CHECK_THROWS_WITH(h.insert(num1, num3), "HashTable - try insert an existing key");
        CHECK(h.contains(num1));
        CHECK(h.contains(num2));
        CHECK(!h.contains(num3));
        CHECK(h.contains(num4));
    }
    SUBCASE("Operator []") {
        t[num1] = num1;
        t[num2] = num2;
        t[num4] = num4;
        CHECK(t.contains(num1));
        CHECK(t.contains(num2));
        CHECK(!t.contains(num3));
        CHECK(t.contains(num4));
        CHECK_EQ(t[num1], num1);
        CHECK_EQ(t[num2], num2);
        CHECK_EQ(t[num3], 0);
        CHECK_EQ(t[num4], num4);
    }
    SUBCASE("Iterator") {
        hashTable<T, T> iter(30);
        iter.insert(num1, num1);
        iter.insert(num2, num3);
        iter.insert(num4, num4);
        auto it = iter.begin();
        auto it2 = iter.end();
        CHECK_NE(it, it2);
        std::vector<T> v = {num4, num1, num3};
        for (auto el : iter) {
            CHECK_NE(v.end(), std::find(v.begin(), v.end(), el.second));
        }
    }
}

TEST_CASE_TEMPLATE("HashTable - type of string ", T, std::string) {
    hashTable<T, T> h;
    hashTable<T, T> t(20);
    SUBCASE("Insert and Contains") {
        h.insert("Key1", "Value1");
        h.insert("Key2", "Value2");
        h.insert("Key3", "Value3");
        CHECK_THROWS_WITH(h.insert("Key1", "Value4"), "HashTable - try insert an existing key");
        CHECK(h.contains("Key1"));
        CHECK(h.contains("Key2"));
        CHECK(h.contains("Key3"));
        CHECK(!h.contains("Key4"));
    }
    SUBCASE("Operator []") {
        h["Key1"] = "Value1";
        h["Key2"] = "Value2";
        h["Key3"] = "Value3";
        CHECK(h.contains("Key1"));
        CHECK(h.contains("Key2"));
        CHECK(h.contains("Key3"));
        CHECK(!h.contains("Key4"));
        CHECK_EQ(h["Key1"], "Value1");
        CHECK_EQ(h["Key2"], "Value2");
        CHECK_EQ(h["Key3"], "Value3");
        CHECK_EQ(h["Key4"], "");
    }
    SUBCASE("Iterator") {
        hashTable<T, T> iter(30);
        iter.insert("Key1", "Value1");
        iter.insert("Key2", "Value2");
        iter.insert("Key3", "Value3");
        auto it = iter.begin();
        auto it2 = iter.end();
        CHECK_NE(it, it2);
        std::vector<T> v = {"Value1", "Value3", "Value2"};
        for (auto el : iter) {
            CHECK_NE(v.end(), std::find(v.begin(), v.end(), el.second));
        }
    }
}