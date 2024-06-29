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

TEST(Method1, queue_push) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.front(), 1);
}

TEST(Method2, queue_front) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.front(), 1);
}

TEST(Method3, queue_back) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.back(), 1);
}

TEST(Method4, queue_pop) {
  queue<int> v;
  v.push(1);
  v.push(2);

  v.pop();

  EXPECT_EQ(v.front(), 2);
  EXPECT_EQ(v.size(), 1);
}

TEST(Method5, queue_empty) {
  queue<int> v;
  v.push(1);

  EXPECT_EQ(v.empty(), false);
}

TEST(Method6, queue_empty2) {
  queue<int> v;

  EXPECT_EQ(v.empty(), true);
}


TEST(QueueTest, PushAndPop) {
  s21::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  EXPECT_EQ(q.front(), 1);
  EXPECT_EQ(q.back(), 3);
  q.pop();
  EXPECT_EQ(q.front(), 2);
  EXPECT_EQ(q.back(), 3);
}

TEST(QueueTest, DefaultConstructor) {
    s21::queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0);
}

TEST(QueueTest, InitializerListConstructor) {
    s21::queue<int> q{1, 2, 3, 4, 5};
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.size(), 5);
    EXPECT_EQ(q.front(), 1);
    EXPECT_EQ(q.back(), 5);
}

TEST(QueueTest, CopyConstructor) {
    s21::queue<int> q1{1, 2, 3};
    s21::queue<int> q2(q1);
    EXPECT_EQ(q2.size(), 3);
    EXPECT_EQ(q2.front(), 1);
    EXPECT_EQ(q2.back(), 3);
}

