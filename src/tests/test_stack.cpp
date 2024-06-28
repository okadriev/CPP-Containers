#include "tests.hpp"

TEST(Constructor, stack_constructor) {
  stack<int> v;

  EXPECT_EQ(v.size(), 0);
}

TEST(Operator, stack_equal) {
  stack<int> v;
  v.push(1);
  stack<int> v2 = v;

  EXPECT_EQ(v2.top(), v.top());
}

TEST(Method, stack_push) {
  stack<int> v;
  v.push(1);

  EXPECT_EQ(v.top(), 1);
}

TEST(Method, stack_top) {
  stack<int> v;
  v.push(1);

  EXPECT_EQ(v.top(), 1);
}

TEST(Method, stack_pop) {
  stack<int> v;
  v.push(1);
  v.push(2);

  v.pop();

  EXPECT_EQ(v.top(), 1);
  EXPECT_EQ(v.size(), 1);
}
stack < in TEST(Method, stack_empty) {
  t > v;
  v.push(1);

  EXPECT_EQ(v.empty(), false);
}

TEST(Method, stack_empty) {
  stack<int> v;

  EXPECT_EQ(v.empty(), true);
}
