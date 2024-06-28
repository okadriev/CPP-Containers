#include "tests.hpp"

TEST(Constructor, queue_constructor) {
  queue<int> v;

  EXPECT_EQ(v.size(), 0);
}

TEST(Operator, queue_equal) {
  queue<int> v;
  v.push(1);
  queue<int> v2 = v;

  EXPECT_EQ(v2.front(), v.front());
}

TEST(Method, queue_push) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.front(), 1);
}

TEST(Method, queue_front) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.front(), 1);
}

TEST(Method, queue_back) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.back(), 1);
}

TEST(Method, queue_pop) {
  queue<int> v;
  v.push(1);
  v.push(2);

  v.pop();

  EXPECT_EQ(v.front(), 2);
  EXPECT_EQ(v.size(), 1);
}

TEST(Method, queue_empty) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.empty(), false);
}

TEST(Method, queue_empty) {
  queue<int> v;

  EXPECT_EQ(v.empty(), true);
}