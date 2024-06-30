#include "tests.hpp"

TEST(VectorConstructorTest, DefaultConstructor_Int) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), 0U);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(VectorConstructorTest, DefaultConstructor_Double) {
  vector<double> v;
  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), 0U);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(VectorConstructorTest, ParameterizedConstructor_Int) {
  vector<int> v(6);
  EXPECT_EQ(v.size(), 6U);
  EXPECT_EQ(v.capacity(), 6U);
  EXPECT_NE(v.data(), nullptr);
}

TEST(VectorConstructorTest, ParameterizedConstructor_InvalidSize) {
  vector<int>::size_type invalid_size =
      std::numeric_limits<vector<int>::size_type>::max() / sizeof(int) + 1;
  EXPECT_THROW(vector<int> v(invalid_size), std::invalid_argument);
}

TEST(VectorConstructorTest, InitConstructor) {
  vector<int> v = {1, 2, 3};

  EXPECT_EQ(v.size(), 3U);
  EXPECT_EQ(v.capacity(), 3U);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorConstructorTest, CopyConstructor) {
  vector<int> v = {1, 2, 3};
  vector<int> other(v);

  EXPECT_EQ(v.size(), other.size());
  EXPECT_EQ(v.capacity(), other.capacity());
  EXPECT_EQ(v[0], other[0]);
  EXPECT_EQ(v[1], other[1]);
  EXPECT_EQ(v[2], other[2]);
}

TEST(VectorConstructorTest, MoveConstructor) {
  vector<int> v = {1, 2, 3};
  vector<int> other(std::move(v));

  EXPECT_EQ(other.size(), 3U);
  EXPECT_EQ(other.capacity(), 3U);
  EXPECT_EQ(other[0], 1);
  EXPECT_EQ(other[1], 2);
  EXPECT_EQ(other[2], 3);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(VectorMethodTest, OverloadMethod) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(VectorMethodTest, AtMethod) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(1), 2);
  EXPECT_EQ(v.at(2), 3);
}

TEST(VectorMethodTest, AtMethod_EmptyContainer) {
  vector<int> v;
  EXPECT_THROW(v.at(0), std::out_of_range);
}

TEST(VectorMethodTest, AtMethod_OutOfBounds) {
  vector<int> v = {1, 2, 3};
  EXPECT_THROW(v.at(3), std::out_of_range);
}

TEST(VectorMethodTest, OperatorBracket_EmptyContainer) {
  vector<int> v;
  EXPECT_THROW(v[0], std::out_of_range);
}

TEST(VectorMethodTest, OperatorBracket_OutOfBounds) {
  vector<int> v = {1, 2, 3};
  EXPECT_THROW(v[3], std::out_of_range);
}

TEST(VectorMethodTest, FrontMethod) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.front(), 1);
}

TEST(VectorMethodTest, FrontMethod_EmptyContainer) {
  vector<int> v;
  EXPECT_THROW(v.front(), std::out_of_range);
}

TEST(VectorMethodTest, BackMethod) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.back(), 3);
}

TEST(VectorMethodTest, BackMethod_EmptyContainer) {
  vector<int> v;
  EXPECT_THROW(v.back(), std::out_of_range);
}

TEST(VectorMethodTest, DataMethod) {
  vector<int> v = {1, 2, 3};
  int *ptr = v.data();

  EXPECT_EQ(*ptr, 1);
  EXPECT_EQ(ptr[0], 1);
  EXPECT_EQ(ptr[1], 2);
  EXPECT_EQ(ptr[2], 3);
}

TEST(VectorMethodTest, BeginMethod) {
  vector<int> v = {1, 2, 3};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorMethodTest, CBeginMethod) {
  vector<int> v = {1, 2, 3};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(VectorMethodTest, EndMethod) {
  vector<int> v = {1, 2, 3};
  auto it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorMethodTest, CEndMethod) {
  vector<int> v = {1, 2, 3};
  auto it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
}

TEST(VectorMethodTest, EmptyMethod) {
  vector<int> v;
  EXPECT_EQ(v.empty(), 1);
}

TEST(VectorMethodTest, MaxSizeMethod) {
  vector<int> v = {1, 2, 3};
  auto size = std::numeric_limits<vector<int>::size_type>::max() / sizeof(int);
  EXPECT_EQ(v.max_size(), size);
}

TEST(VectorMethodTest, ReserveMethod) {
  vector<int> v = {1, 2, 3};
  v.reserve(6);
  EXPECT_EQ(v.capacity(), 6U);
}

TEST(VectorMethodTest, ReserveMethod_InvalidSize) {
  vector<int> v;
  vector<int>::size_type invalid_size =
      std::numeric_limits<vector<int>::size_type>::max() / sizeof(int) + 1;
  EXPECT_THROW(v.reserve(invalid_size), std::invalid_argument);
}

TEST(VectorMethodTest, CapacityMethod) {
  vector<int> v;
  EXPECT_EQ(v.capacity(), 0U);
}

TEST(VectorMethodTest, ShrinkToFitMethod) {
  vector<int> v = {1, 2, 3};

  v.push_back(4);
  EXPECT_EQ(v.capacity(), 6U);
  v.shrink_to_fit();
  EXPECT_EQ(v.capacity(), 4U);
}

TEST(VectorMethodTest, ClearMethod) {
  vector<int> v = {1, 2, 3};
  v.clear();
  EXPECT_EQ(v.size(), 0U);
}

TEST(VectorMethodTest, InsertMethod) {
  vector<int> v = {1, 2, 3};
  v.insert(v.end(), 4);
  EXPECT_EQ(v.size(), 4U);
  EXPECT_EQ(v[3], 4);
}

TEST(VectorMethodTest, InsertMethod_ElementMove) {
  vector<int> v = {1, 2, 3};

  v.reserve(5);
  v.insert(v.begin() + 1, 99);
  
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 99);
  EXPECT_EQ(v[2], 2);
  EXPECT_EQ(v[3], 3);
}

TEST(VectorMethodTest, InsertMethod_OutOfRange) {
  vector<int> v = {1, 2, 3};
  EXPECT_THROW(v.insert(v.end() + 1, 4), std::out_of_range);
}

TEST(VectorMethodTest, InsertMethod_PositionOutOfRange) {
  vector<int> v = {1, 2, 3};
  EXPECT_THROW(v.insert(v.begin() - 1, 4), std::out_of_range);
  EXPECT_THROW(v.insert(v.end() + 1, 4), std::out_of_range);
}

TEST(VectorMethodTest, EraseMethod) {
  vector<int> v = {1, 2, 3};
  v.erase(v.end() - 1);
  EXPECT_EQ(v.size(), 2U);
  EXPECT_EQ(v[1], 2);
  EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(VectorMethodTest, EraseMethod_OutOfRange) {
  vector<int> v = {1, 2, 3};
  EXPECT_THROW(v.erase(v.end()), std::out_of_range);
}

TEST(VectorMethodTest, EraseMethod_EmptyContainer) {
  vector<int> v;
  EXPECT_THROW(v.erase(v.begin()), std::out_of_range);
}

TEST(VectorMethodTest, PushBackMethod) {
  vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4U);
  EXPECT_EQ(v[3], 4);
}

TEST(VectorMethodTest, PopBackMethod) {
  vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2U);
  EXPECT_EQ(v[1], 2);
}

TEST(VectorMethodTest, PopBackMethod_EmptyContainer) {
  vector<int> v;
  EXPECT_THROW(v.pop_back(), std::out_of_range);
}

TEST(VectorMethodTest, SwapMethod) {
  vector<int> v = {1, 2, 3};
  vector<int> other = {4, 5, 6};

  v.swap(other);

  EXPECT_EQ(v[0], 4);
  EXPECT_EQ(v[1], 5);
  EXPECT_EQ(v[2], 6);

  EXPECT_EQ(other[0], 1);
  EXPECT_EQ(other[1], 2);
  EXPECT_EQ(other[2], 3);
}

TEST(VectorMethodTest, InsertManyMethod) {
  vector<int> v = {1, 2, 3};
  v.insert_many_back(4, 5, 6, 7, 8);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v.size(), 8U);
}

TEST(VectorMethodTest, InsertManyMethod_OutOfRange) {
  vector<int> v = {1, 2, 3};
  EXPECT_THROW(v.insert_many(v.end() + 1, 4, 5, 6), std::out_of_range);
}

TEST(VectorMethodTest, InsertManyBackMethod) {
  vector<int> v = {1, 2, 3};
  v.insert_many(v.cbegin(), 4, 5, 6);
  EXPECT_EQ(v[0], 4);
  EXPECT_EQ(v[2], 6);
  EXPECT_EQ(v[3], 1);
  EXPECT_EQ(v.size(), 6U);
}