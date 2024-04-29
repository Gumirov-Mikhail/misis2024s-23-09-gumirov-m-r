#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <queuelst/queuelst.hpp>

TEST_CASE("QueueLst - Constructors") {
    Complex ch1 {2.3, 6.7};
    Complex ch2 {4.5, 0.9};
    SUBCASE("Default constructor") {
        QueueLst ctor;
        CHECK(ctor.IsEmpty());
    }
    SUBCASE("Constructor Copy") {
        QueueLst ctor_copy1;
        ctor_copy1.Push(ch1);
        ctor_copy1.Push(ch2);
        QueueLst ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy2.IsEmpty());
        CHECK_EQ(ctor_copy2.Top(), ch1);
        CHECK(!ctor_copy1.IsEmpty());
        CHECK_EQ(ctor_copy1.Top(), ch1);
    }
    SUBCASE("Constructor Move") {
        QueueLst ctor_move1;
        ctor_move1.Push(ch1);
        ctor_move1.Push(ch2);
        QueueLst ctor_move2(std::move(ctor_move1));
        CHECK(!ctor_move2.IsEmpty());
        CHECK_EQ(ctor_move2.Top(), ch1);
        CHECK(ctor_move1.IsEmpty());
    }
    SUBCASE("Constructor Copy with empty queue") {
        QueueLst ctor_copy1;
        QueueLst ctor_copy2(ctor_copy1);
        CHECK(ctor_copy2.IsEmpty());
        CHECK(ctor_copy1.IsEmpty());
    }
    SUBCASE("Constructor Move with empty queue") {
        QueueLst ctor_move1;
        QueueLst ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move2.IsEmpty());
        CHECK(ctor_move1.IsEmpty());
    }
}

TEST_CASE("QueueLst - Push, Pop, Top and Clear") {
    Complex ch1 {2.3, 6.7};
    Complex ch2 {4.5, 0.9};
    Complex ch3 {4, 9};
    SUBCASE("Push and Pop") {
        QueueLst Queue1;
        Queue1.Push(ch1);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch2);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch3);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Pop();
        CHECK_EQ(Queue1.Top(), ch2);
        Queue1.Pop();
        CHECK_EQ(Queue1.Top(), ch3);
        Queue1.Pop();
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Push and Clear") {
        QueueLst Queue1;
        Queue1.Push(ch1);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch2);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch3);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Clear();
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Top with empty queue") {
        QueueLst Queue1;
        QueueLst Queue2(Queue1);
        QueueLst Queue3(std::move(Queue1));
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueLst - try get top from empty queue");
        Queue1.Push(ch1);
        Queue1.Pop();
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueLst - try get top from empty queue");
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Clear();
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueLst - try get top from empty queue");
        CHECK_THROWS_WITH(void(Queue2.Top()), "QueueLst - try get top from empty queue");
        CHECK_THROWS_WITH(void(Queue3.Top()), "QueueLst - try get top from empty queue");
    }
}

TEST_CASE("QueueLst - Assignments") {
    Complex ch1 {2.3, 6.7};
    Complex ch2 {4.5, 0.9};
    Complex ch3 {4, 9};
    SUBCASE("Assignments with copy") {
        QueueLst Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLst Queue2;
        Queue2 = Queue1;
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(!Queue2.IsEmpty());
        CHECK_EQ(Queue1.Top(), ch1);
        CHECK(!Queue1.IsEmpty());
        Queue2.Pop();
        CHECK_EQ(Queue2.Top(), ch2);
        Queue2.Clear();
        CHECK(Queue2.IsEmpty());
    }
    SUBCASE("Assignments with copy empty queue") {
        QueueLst Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLst Queue2;
        Queue1 = Queue2;
        CHECK(Queue2.IsEmpty());
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Assignments with move") {
        QueueLst Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLst Queue2;
        Queue2 = std::move(Queue1);
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(!Queue2.IsEmpty());
        CHECK(Queue1.IsEmpty());
        Queue2.Pop();
        CHECK_EQ(Queue2.Top(), ch2);
        Queue2.Clear();
        CHECK(Queue2.IsEmpty());
    }
    SUBCASE("Assignments with move empty queue") {
        QueueLst Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLst Queue2;
        Queue1 = std::move(Queue2);
        CHECK(!Queue2.IsEmpty());
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(Queue1.IsEmpty());
    }
}