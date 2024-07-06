#include "../s21_array/s21_array.hpp"
#include "tests.hpp"

namespace s21 {
TEST(ArrayTest, Size) {
  array<int, 5> arr;
  EXPECT_EQ(arr.size(), 5);
}

TEST(ArrayTest, EmptyArray) {
  array<int, 0> arr;
  EXPECT_EQ(arr.size(), 0);
  EXPECT_EQ(arr.data(), nullptr);
}

TEST(ArrayTest, ElementAccess) {
  array<int, 3> arr;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  EXPECT_EQ(arr[0], 10);
  EXPECT_EQ(arr[1], 20);
  EXPECT_EQ(arr[2], 30);
}

TEST(ArrayTest, ElementAccessOutOfBounds) {
  array<int, 3> arr;
  EXPECT_THROW(arr.at(3), std::out_of_range);
  EXPECT_THROW(arr.at(-1), std::out_of_range);
}

TEST(ArrayTest, AtFunction) {
  array<int, 3> arr;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  EXPECT_EQ(arr.at(0), 10);
  EXPECT_EQ(arr.at(1), 20);
  EXPECT_EQ(arr.at(2), 30);
  EXPECT_THROW(arr.at(3), std::out_of_range);
}

TEST(ArrayTest, AtFunctionConst) {
  const array<int, 3> arr{10, 20, 30};

  EXPECT_EQ(arr.at(0), 10);
  EXPECT_EQ(arr.at(1), 20);
  EXPECT_EQ(arr.at(2), 30);
  EXPECT_THROW(arr.at(3), std::out_of_range);
}

TEST(ArrayTest, FrontBack) {
  array<int, 3> arr;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  EXPECT_EQ(arr.front(), 10);
  EXPECT_EQ(arr.back(), 30);
}

TEST(ArrayTest, FrontBackSingleElement) {
  array<int, 1> arr;
  arr[0] = 42;

  EXPECT_EQ(arr.front(), 42);
  EXPECT_EQ(arr.back(), 42);
}

TEST(ArrayTest, Data) {
  array<int, 3> arr;
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  int* data = arr.data();
  EXPECT_EQ(data[0], 10);
  EXPECT_EQ(data[1], 20);
  EXPECT_EQ(data[2], 30);
}

TEST(ArrayTest, DataEmptyArray) {
  array<int, 0> arr;
  EXPECT_EQ(arr.data(), nullptr);
}

TEST(ArrayTest, ConstArray) {
  const array<int, 3> arr = {10, 20, 30};
  EXPECT_EQ(arr.front(), 10);
  EXPECT_EQ(arr.back(), 30);
  EXPECT_EQ(arr[1], 20);
  EXPECT_EQ(arr.at(2), 30);
}

TEST(ArrayTest, ExceptionSafety) {
  array<int, 3> arr = {1, 2, 3};

  try {
    arr.at(3);
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "Index out of range");
  }

  try {
    arr.at(4);
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "Index out of range");
  }
}

TEST(ArrayTest, ModifyArrayThroughData) {
  array<int, 3> arr = {1, 2, 3};
  int* data = arr.data();
  data[0] = 10;
  data[1] = 20;
  data[2] = 30;

  EXPECT_EQ(arr[0], 10);
  EXPECT_EQ(arr[1], 20);
  EXPECT_EQ(arr[2], 30);
}

TEST(ArrayTest, ConstArrayAccess) {
  const array<int, 3> arr = {1, 2, 3};
  const int* data = arr.data();

  EXPECT_EQ(data[0], 1);
  EXPECT_EQ(data[1], 2);
  EXPECT_EQ(data[2], 3);
}

}  // namespace s21
