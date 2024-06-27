#include <gtest/gtest.h>

#include "../s21_queue/s21_queue.hpp"
#include "../s21_stack/s21_stack.hpp"

using namespace s21;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

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

TEST(Method, stack_empty) {
  stack<int> v;
  v.push(1);

  EXPECT_EQ(v.empty(), false);
}

TEST(Method, stack_empty) {
  stack<int> v;

  EXPECT_EQ(v.empty(), true);
}



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