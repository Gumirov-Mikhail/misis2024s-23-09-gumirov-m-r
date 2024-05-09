#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include <queuelstprt/queuelstprt.hpp>
#include "unittest.hpp"

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("QueueLstPrT", T, queuelstprt) {
    QueueLstPrT<T> queue;
    CHECK(queue.IsEmpty());

    std::vector<T> data;
    const int size = 4;
    FillData(size, data);

    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];

    queue.Push(c1);
    CHECK(!queue.IsEmpty());
    CHECK_EQ(queue.Top(), c1);
    queue.Push(c2);
    CHECK_EQ(queue.Top(), c1);
    queue.Push(c3);
    CHECK_EQ(queue.Top(), c1);

    QueueLstPrT<T> queue_copy(queue);
    CHECK(!queue.IsEmpty());
    CHECK(!queue_copy.IsEmpty());
    CHECK_EQ(queue_copy.Top(), c1);
    queue_copy.Pop();
    CHECK_EQ(queue_copy.Top(), c2);
    queue_copy.Pop();
    CHECK_EQ(queue_copy.Top(), c3);
    queue_copy.Pop();
    CHECK(queue_copy.IsEmpty());

    QueueLstPrT<T> queue_copy_assignment;
    queue_copy_assignment = queue;
    CHECK(!queue.IsEmpty());
    CHECK(!queue_copy_assignment.IsEmpty());
    CHECK_EQ(queue_copy_assignment.Top(), c1);
    queue_copy_assignment.Clear();
    CHECK(queue_copy_assignment.IsEmpty());

    CHECK_THROWS_WITH((void) queue_copy.Top(), "QueueLstPrT - try get top from empty priority_queue");
    CHECK_THROWS_WITH((void) queue_copy_assignment.Top(), "QueueLstPrT - try get top from empty priority_queue");

    QueueLstPrT<T> queue2;
    queue2 = queue;

    QueueLstPrT<T> queue_move(std::move(queue));
    CHECK(queue.IsEmpty());
    CHECK(!queue_move.IsEmpty());
    CHECK_EQ(queue_move.Top(), c1);
    queue_move.Pop();
    CHECK_EQ(queue_move.Top(), c2);
    queue_move.Pop();
    CHECK_EQ(queue_move.Top(), c3);
    queue_move.Pop();
    CHECK(queue_move.IsEmpty());

    QueueLstPrT<T> queue_move_assignments;
    queue_move_assignments = std::move(queue2);
    CHECK(queue2.IsEmpty());
    CHECK(!queue_move_assignments.IsEmpty());
    CHECK_EQ(queue_move_assignments.Top(), c1);
    queue_move_assignments.Clear();
    CHECK(queue_move_assignments.IsEmpty());
}


TEST_CASE_TEMPLATE_INVOKE(queuelstprt, TYPES);
