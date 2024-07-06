#include "tests.hpp"

namespace s21 {
TEST(ArrayTest, size) {
  array<int, 5> arr;
  EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, size_empty) {
  array<int, 0> arr;
  EXPECT_EQ(arr.size(), 0);
}

TEST(ArrayTest, at) {
  array<int, 3> arr;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  EXPECT_THROW(arr.at(-1), std::out_of_range);
  EXPECT_EQ(arr[0], 10);
  EXPECT_EQ(arr[1], 20);
  EXPECT_EQ(arr[2], 30);
  EXPECT_THROW(arr.at(3), std::out_of_range);
}

TEST(ArrayTest, at_empty) {
  array<int, 0> arr;

  EXPECT_THROW(arr.at(0), std::length_error);
}

TEST(ArrayTest, at_const) {
  const array<int, 3> arr{10, 20, 30};

  EXPECT_THROW(arr.at(-1), std::out_of_range);
  EXPECT_EQ(arr.at(0), 10);
  EXPECT_EQ(arr.at(1), 20);
  EXPECT_EQ(arr.at(2), 30);
  EXPECT_THROW(arr.at(3), std::out_of_range);
}

TEST(ArrayTest, at_const_empty) {
  const array<int, 0> arr;

  EXPECT_THROW(arr.at(0), std::length_error);
}

TEST(ArrayTest, front) {
  array<int, 3> arr{10, 20, 30};

  EXPECT_EQ(arr.front(), 10);
}

TEST(ArrayTest, front_const) {
  const array<int, 3> arr{10, 20, 30};
  EXPECT_EQ(arr.front(), 10);
}

TEST(ArrayTest, front_empty) {
  array<int, 0> arr;

  EXPECT_THROW(arr.front(), std::length_error);
}

TEST(ArrayTest, back) {
  array<int, 3> arr{10, 20, 30};
  EXPECT_EQ(arr.back(), 30);
}

TEST(ArrayTest, back_const) {
  const array<int, 3> arr{10, 20, 30};
  EXPECT_EQ(arr.back(), 30);
}

TEST(ArrayTest, back_empty) {
  array<int, 0> arr;

  EXPECT_THROW(arr.back(), std::length_error);
}

TEST(ArrayTest, front_back_single_element) {
  array<int, 1> arr{42};

  EXPECT_EQ(arr.front(), 42);
  EXPECT_EQ(arr.back(), 42);
  EXPECT_EQ(arr.front(), arr.back());
}

TEST(ArrayTest, front_back_const_single_element) {
  const array<int, 1> arr{42};

  EXPECT_EQ(arr.front(), 42);
  EXPECT_EQ(arr.back(), 42);
  EXPECT_EQ(arr.front(), arr.back());
}

TEST(ArrayTest, data) {
  array<int, 3> arr{10, 20, 30};

  int* data = arr.data();
  EXPECT_EQ(data[0], 10);
  EXPECT_EQ(data[1], 20);
  EXPECT_EQ(data[2], 30);
}

TEST(ArrayTest, data_const) {
  const array<int, 3> arr{1, 2, 3};

  EXPECT_EQ(arr.data()[0], 1);
  EXPECT_EQ(arr.data()[1], 2);
  EXPECT_EQ(arr.data()[2], 3);
}

TEST(ArrayTest, data_modify) {
  array<int, 3> arr{1, 2, 3};
  arr.data()[0] = 10;
  arr.data()[1] = 20;
  arr.data()[2] = 30;

  EXPECT_EQ(arr.data()[0], 10);
  EXPECT_EQ(arr.data()[1], 20);
  EXPECT_EQ(arr.data()[2], 30);
}

TEST(ArrayTest, data_empty) {
  array<int, 0> arr;
  EXPECT_EQ(arr.data(), nullptr);
}

TEST(ArrayTest, operator_brackets) {
  array<int, 3> arr{1, 2, 3};
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, operator_brackets_modify) {
  array<int, 3> arr{1, 2, 3};
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  EXPECT_EQ(arr[0], 10);
  EXPECT_EQ(arr[1], 20);
  EXPECT_EQ(arr[2], 30);
}

TEST(ArrayTest, operator_brackets_const) {
  const array<int, 3> arr{1, 2, 3};
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
}

TEST(ArrayTest, operator_brackets_empty) {
  array<int, 0> arr;
  EXPECT_THROW(arr[0], std::length_error);
}

TEST(ArrayTest, operator_brackets_out_of_range) {
  array<int, 3> arr{1, 2, 3};
  EXPECT_THROW(arr[3], std::out_of_range);
}

TEST(ArrayTest, operator_brackets_const_empty) {
  const array<int, 0> arr;
  EXPECT_THROW(arr[0], std::length_error);
}

TEST(ArrayTest, operator_brackets_const_out_of_range) {
  const array<int, 3> arr{1, 2, 3};
  EXPECT_THROW(arr[3], std::out_of_range);
}

}  // namespace s21
