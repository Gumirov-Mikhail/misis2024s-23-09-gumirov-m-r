#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("QueueLstPr - Constructors") {
    float ch1 = 2.3;
    float ch2 = 4.5;
    SUBCASE("Default constructor") {
        QueueLstPr ctor;
        CHECK(ctor.IsEmpty());
    }
    SUBCASE("Constructor Copy") {
        QueueLstPr ctor_copy1;
        ctor_copy1.Push(ch1);
        ctor_copy1.Push(ch2);
        QueueLstPr ctor_copy2(ctor_copy1);
        CHECK(!ctor_copy2.IsEmpty());
        CHECK_EQ(ctor_copy2.Top(), ch1);
        CHECK(!ctor_copy1.IsEmpty());
        CHECK_EQ(ctor_copy1.Top(), ch1);
    }
    SUBCASE("Constructor Move") {
        QueueLstPr ctor_move1;
        ctor_move1.Push(ch1);
        ctor_move1.Push(ch2);
        QueueLstPr ctor_move2(std::move(ctor_move1));
        CHECK(!ctor_move2.IsEmpty());
        CHECK_EQ(ctor_move2.Top(), ch1);
        CHECK(ctor_move1.IsEmpty());
    }
    SUBCASE("Constructor Copy with empty priority_queue") {
        QueueLstPr ctor_copy1;
        QueueLstPr ctor_copy2(ctor_copy1);
        CHECK(ctor_copy2.IsEmpty());
        CHECK(ctor_copy1.IsEmpty());
    }
    SUBCASE("Constructor Move with empty priority_queue") {
        QueueLstPr ctor_move1;
        QueueLstPr ctor_move2(std::move(ctor_move1));
        CHECK(ctor_move2.IsEmpty());
        CHECK(ctor_move1.IsEmpty());
    }
}

TEST_CASE("QueueLstPr - Push, Pop, Top and Clear") {
    float ch1 = 2.3;
    float ch2 = 4.5;
    float ch3 = 3.9;
    SUBCASE("Push and Pop") {
        QueueLstPr Queue1;
        Queue1.Push(ch1);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch2);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch3);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Pop();
        CHECK_EQ(Queue1.Top(), ch3);
        Queue1.Pop();
        CHECK_EQ(Queue1.Top(), ch2);
        Queue1.Pop();
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Push and Clear") {
        QueueLstPr Queue1;
        Queue1.Push(ch1);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch2);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Push(ch3);
        CHECK_EQ(Queue1.Top(), ch1);
        Queue1.Clear();
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Top with empty priority_queue") {
        QueueLstPr Queue1;
        QueueLstPr Queue2(Queue1);
        QueueLstPr Queue3(std::move(Queue1));
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueLstPr - try get top from empty priority_queue");
        Queue1.Push(ch1);
        Queue1.Pop();
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueLstPr - try get top from empty priority_queue");
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Clear();
        CHECK_THROWS_WITH(void(Queue1.Top()), "QueueLstPr - try get top from empty priority_queue");
        CHECK_THROWS_WITH(void(Queue2.Top()), "QueueLstPr - try get top from empty priority_queue");
        CHECK_THROWS_WITH(void(Queue3.Top()), "QueueLstPr - try get top from empty priority_queue");
    }
}

TEST_CASE("QueueLstPr - Assignments") {
    float ch1 = 2.3;
    float ch2 = 4.5;
    float ch3 = 3.9;
    SUBCASE("Assignments with copy") {
        QueueLstPr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLstPr Queue2;
        Queue2 = Queue1;
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(!Queue2.IsEmpty());
        CHECK_EQ(Queue1.Top(), ch1);
        CHECK(!Queue1.IsEmpty());
        Queue2.Pop();
        CHECK_EQ(Queue2.Top(), ch3);
        Queue2.Clear();
        CHECK(Queue2.IsEmpty());
    }
    SUBCASE("Assignments with copy empty priority_queue") {
        QueueLstPr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLstPr Queue2;
        Queue1 = Queue2;
        CHECK(Queue2.IsEmpty());
        CHECK(Queue1.IsEmpty());
    }
    SUBCASE("Assignments with move") {
        QueueLstPr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLstPr Queue2;
        Queue2 = std::move(Queue1);
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(!Queue2.IsEmpty());
        CHECK(Queue1.IsEmpty());
        Queue2.Pop();
        CHECK_EQ(Queue2.Top(), ch3);
        Queue2.Clear();
        CHECK(Queue2.IsEmpty());
    }
    SUBCASE("Assignments with move empty priority_queue") {
        QueueLstPr Queue1;
        Queue1.Push(ch1);
        Queue1.Push(ch2);
        Queue1.Push(ch3);
        QueueLstPr Queue2;
        Queue1 = std::move(Queue2);
        CHECK(!Queue2.IsEmpty());
        CHECK_EQ(Queue2.Top(), ch1);
        CHECK(Queue1.IsEmpty());
    }
}

