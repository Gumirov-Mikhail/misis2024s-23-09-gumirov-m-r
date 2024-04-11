#include <stacklst/stacklst.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

TEST_CASE("stacklst") {
    StackLst stack;
    Complex a;
    Complex b{2.9, 3.5};
    CHECK(stack.IsEmpty() == true);
    stack.Push(a);
    CHECK(stack.IsEmpty() == false);
    CHECK(stack.Top() == Complex());
    stack.Pop();
    CHECK(stack.IsEmpty() == true);
    CHECK_THROWS_WITH(stack.Top(), "Stack is empty");
    stack.Push(a);
    stack.Clear();
    CHECK(stack.IsEmpty() == true);
    stack.Push(a);
    stack.Push(b);
    CHECK(stack.Top() == Complex{2.9, 3.5});
}