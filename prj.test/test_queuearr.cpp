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


TEST_CASE("queuearr ctor") {
    Complex c11(1, 2);
    Complex c12(2, 1);
    Complex c21(3, 4);
    Complex c22(4, 3);
    Complex c31(5, 6);
    Complex c32(6, 5);
    Complex c41(7, 8);
    Complex c42(8, 7);
    QueueArr q1;
    CHECK_EQ(q1.IsEmpty(), 1);
    CHECK_THROWS(q1.Top());
    q1.Pop();
    QueueArr cp(q1);
    QueueArr cpp = q1;

    cp.Push(c11);
    CHECK_EQ(cp.Top(), c11);
    CHECK_EQ(cp.IsEmpty(), 0);

    cpp.Push(c11);
    CHECK_EQ(cpp.Top(), c11);
    CHECK_EQ(cpp.IsEmpty(), 0);

    q1.Push(c11);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c12);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c21);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c22);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c31);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c32);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c41);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c42);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArr test_copy_1(q1);
    QueueArr ravno1 = q1;

    q1.Pop();
    CHECK_EQ(q1.Top(), c12);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c21);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c22);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c31);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c32);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c41);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c42);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_THROWS(q1.Top());
    CHECK_EQ(q1.IsEmpty(), 1);

    q1.Push(c11);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c12);
    CHECK_EQ(q1.Top(), c11);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArr q2;
    CHECK_EQ(q2.IsEmpty(), 1);
    CHECK_THROWS(q2.Top());
    q2.Pop();

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c21);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c12);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c21);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c22);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c31);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c32);
    CHECK_EQ(q2.Top(), c21);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c41);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    QueueArr test_copy_2(q2);
    QueueArr ravno2 = q2;

    q2.Push(c42);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c32);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c41);
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Push(c42);
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Clear();
    CHECK_EQ(q2.IsEmpty(), 1);
    CHECK_THROWS(q2.Top());
    q2.Pop();

    q2.Push(c11);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Push(c12);
    CHECK_EQ(q2.Top(), c11);
    CHECK_EQ(q2.IsEmpty(), 0);

    q2.Pop();
    CHECK_EQ(q2.Top(), c12);
    CHECK_EQ(q2.IsEmpty(), 0);
    q2.Pop();
    CHECK_THROWS(q2.Top());
    CHECK_EQ(q2.IsEmpty(), 1);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c12);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c21);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c22);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c31);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c32);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c41);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_EQ(test_copy_1.Top(), c42);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Pop();
    CHECK_THROWS(test_copy_1.Top());
    CHECK_EQ(test_copy_1.IsEmpty(), 1);

    test_copy_1.Push(c11);
    CHECK_EQ(test_copy_1.Top(), c11);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    test_copy_1.Push(c12);
    CHECK_EQ(test_copy_1.Top(), c11);
    CHECK_EQ(test_copy_1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c12);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c21);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c22);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c31);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c32);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c41);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_EQ(ravno1.Top(), c42);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Pop();
    CHECK_THROWS(ravno1.Top());
    CHECK_EQ(ravno1.IsEmpty(), 1);

    ravno1.Push(c11);
    CHECK_EQ(ravno1.Top(), c11);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno1.Push(c12);
    CHECK_EQ(ravno1.Top(), c11);
    CHECK_EQ(ravno1.IsEmpty(), 0);

    ravno2.Push(c42);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c32);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c41);
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c42);
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Clear();
    CHECK_EQ(ravno2.IsEmpty(), 1);
    CHECK_THROWS(ravno2.Top());
    ravno2.Pop();

    ravno2.Push(c11);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Push(c12);
    CHECK_EQ(ravno2.Top(), c11);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_EQ(ravno2.Top(), c12);
    CHECK_EQ(ravno2.IsEmpty(), 0);

    ravno2.Pop();
    CHECK_THROWS(ravno2.Top());
    CHECK_EQ(ravno2.IsEmpty(), 1);

    test_copy_2.Push(c42);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c32);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c41);
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c42);
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Clear();
    CHECK_EQ(test_copy_2.IsEmpty(), 1);
    CHECK_THROWS(test_copy_2.Top());
    test_copy_2.Pop();
    test_copy_2.Push(c11);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Push(c12);
    CHECK_EQ(test_copy_2.Top(), c11);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_EQ(test_copy_2.Top(), c12);
    CHECK_EQ(test_copy_2.IsEmpty(), 0);

    test_copy_2.Pop();
    CHECK_THROWS(test_copy_2.Top());
    CHECK_EQ(test_copy_2.IsEmpty(), 1);

}