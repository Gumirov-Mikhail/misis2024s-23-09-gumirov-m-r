#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <queuearr/queuearr.hpp>

TEST_CASE("QueueArr - Constructors") {
    Complex ch1 {2.3, 6.7};
    Complex ch2 {4.5, 0.9};
    SUBCASE("Default constructor") {
        QueueArr ctor;
        CHECK(ctor.IsEmpty());
    }
    SUBCASE("Constructor Copy") {
        QueueArr ctor_copy1;
        ctor_copy1.Push(ch1);
        ctor_copy1.Push(ch2);
        QueueArr ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy2.IsEmpty());
        CHECK_EQ(ctor_copy2.Top(), ch1);
        CHECK(!ctor_copy1.IsEmpty());
        CHECK_EQ(ctor_copy1.Top(), ch1);
    }
    SUBCASE("Constructor Move") {
        QueueArr ctor_move1;
        ctor_move1.Push(ch1);
        ctor_move1.Push(ch2);
        QueueArr ctor_move2(std::move(ctor_move1));
        CHECK(!ctor_move2.IsEmpty());
        CHECK_EQ(ctor_move2.Top(), ch1);
        CHECK(ctor_move1.IsEmpty());
    }
    SUBCASE("Constructor Copy with empty queue") {
        QueueArr ctor_copy1;
        QueueArr ctor_copy2(ctor_copy1);
        CHECK(ctor_copy2.IsEmpty());
        CHECK(ctor_copy1.IsEmpty());
    }
    SUBCASE("Constructor Move with empty queue") {
        QueueArr ctor_move1;
        QueueArr ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move2.IsEmpty());
        CHECK(ctor_move1.IsEmpty());
    }
}

TEST_CASE("QueueArr - Push, Pop, Top and Clear") {
    Complex ch1 {2.3, 6.7};
    Complex ch2 {4.5, 0.9};
    Complex ch3 {4, 9};
    SUBCASE("Push and Pop") {
        QueueArr Queue1;
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
        QueueArr Queue1;
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
        QueueArr Queue1;
        QueueArr Queue2(Queue1);
        QueueArr Queue3(std::move(Queue1));
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueArr - try get top from empty queue");
        Queue1.Push(ch1);
        Queue1.Pop();
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueArr - try get top from empty queue");
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Clear();
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueArr - try get top from empty queue");
        CHECK_THROWS_WITH(void(Queue2.Top()), "QueueArr - try get top from empty queue");
        CHECK_THROWS_WITH(void(Queue3.Top()), "QueueArr - try get top from empty queue");
    }
}

TEST_CASE("QueueArr - Assignments") {
    Complex ch1 {2.3, 6.7};
    Complex ch2 {4.5, 0.9};
    Complex ch3 {4, 9};
    SUBCASE("Assignments with copy") {
        QueueArr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueArr Queue2;
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
        QueueArr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueArr Queue2;
        Queue1 = Queue2;
        CHECK(Queue2.IsEmpty());
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Assignments with move") {
        QueueArr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueArr Queue2;
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
        QueueArr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueArr Queue2;
        Queue1 = std::move(Queue2);
        CHECK(!Queue2.IsEmpty());
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(Queue1.IsEmpty());
    }
}