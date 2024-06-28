#include "tests.hpp"

TEST(Vector_constructor, default_constructor_1) {
  vector<int> v;
  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), 0U);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(Vector_constructor, default_constructor_2) {
  vector<double> v;
  EXPECT_EQ(v.size(), 0U);
  EXPECT_EQ(v.capacity(), 0U);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(Vector_constructor, parametrized_constructor) {
  vector<int> v(6);
  EXPECT_EQ(v.size(), 6U);
  EXPECT_EQ(v.capacity(), 6U);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(Vector_constructor, init_constructor) {
  vector<int> v = {1, 2, 3};

  EXPECT_EQ(v.size(), 3U);
  EXPECT_EQ(v.capacity(), 3U);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(Vector_constructor, copy_constructor) {
  vector<int> v = {1, 2, 3};
  vector<int> other(v);

  EXPECT_EQ(v.size(), other.size());
  EXPECT_EQ(v.capacity(), other.capacity());
  EXPECT_EQ(v[0], other[0]);
  EXPECT_EQ(v[1], other[1]);
  EXPECT_EQ(v[2], other[2]);
}

TEST(Vector_constructor, move_constructor) {
  vector<int> v = {1, 2, 3};
  vector<int> other(std::move(v));

  EXPECT_EQ(other.size(), 3U);
  EXPECT_EQ(other.capacity(), 3U);
  EXPECT_EQ(other[0], 1);
  EXPECT_EQ(other[1], 2);
  EXPECT_EQ(other[2], 3);
  EXPECT_EQ(v.data(), nullptr);
}

TEST(Vector_method, overload_method) {
  vector<int> v = {1, 2, 3};
  s21::vector<int> other;

  other = v;

  EXPECT_EQ(other.size(), 3U);
  EXPECT_EQ(other.capacity(), 3U);

  EXPECT_EQ(other[0], 1);
  EXPECT_EQ(other[1], 2);
  EXPECT_EQ(other[2], 3);

  EXPECT_EQ(v.size(), 3U);
  EXPECT_EQ(v.capacity(), 3U);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);

  EXPECT_NE(v.data(), other.data());
}

TEST(Vector_method, at_method) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(1), 2);
  EXPECT_EQ(v.at(2), 3);
}

TEST(Vector_method, front_method) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.front(), 1);
}

TEST(Vector_method, back_method) {
  vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.back(), 3);
}

TEST(Vector_method, data_method) {
  vector<int> v = {1, 2, 3};
  int *ptr = v.data();

  EXPECT_EQ(*ptr, 1);
  EXPECT_EQ(ptr[0], 1);
  EXPECT_EQ(ptr[1], 2);
  EXPECT_EQ(ptr[2], 3);
}

TEST(Vector_method, begin_method) {
  vector<int> v = {1, 2, 3};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(Vector_method, cbegin_method) {
  vector<int> v = {1, 2, 3};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
  ++it;
  EXPECT_EQ(*it, 2);
}

TEST(Vector_method, end_method) {
  vector<int> v = {1, 2, 3};
  auto it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
}

TEST(Vector_method, cend_method) {
  vector<int> v = {1, 2, 3};
  auto it = v.end();
  --it;
  EXPECT_EQ(*it, 3);
}

TEST(Vector_method, empty_method) {
  vector<int> v;
  EXPECT_EQ(v.empty(), 1);
}

TEST(Vector_method, max_size_method) {
  vector<int> v = {1, 2, 3};
  auto size = std::numeric_limits<size_type>::max() / sizeof(int);
  EXPECT_EQ(v.max_size(), size);
}

TEST(Vector_method, reserve_method) {
  vector<int> v = {1, 2, 3};
  v.reserve(6);
  EXPECT_EQ(v.capacity(), 6U);
}

TEST(Vector_method, capacity_method) {
  vector<int> v;
  EXPECT_EQ(v.capacity(), 0U);
}

TEST(Vector_method, shrink_to_fit_method) {
  vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.capacity(), 6U);
  EXPECT_EQ(v.shrink_to_fit(), 4U);
}

TEST(Vector_method, clear_method) {
  vector<int> v = {1, 2, 3};
  v.clear();
  EXPECT_EQ(v.size(), 0U);
}

TEST(Vector_method, insert_method) {
  vector<int> v = {1, 2, 3};
  v.insert(v.end(), 4);
  EXPECT_EQ(v.size(), 4U);
  EXPECT_EQ(v[3], 4);
}

TEST(Vector_method, erase_method) {
  vector<int> v = {1, 2, 3};
  v.erase(v.end() - 1);
  EXPECT_EQ(v.size(), 2U);
  EXPECT_EQ(v[1], 2);
  EXPECT_THROW(v.at(2), std::out_of_range);
}

TEST(Vector_method, push_back_method) {
  vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4U);
  EXPECT_EQ(v[3], 4);
}

TEST(Vector_method, pop_back_method) {
  vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2U);
  EXPECT_EQ(v[1], 2);
}

TEST(Vector_method, swap_method) {
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

TEST(Vector_method, insert_many_method) {
  vector<int> v = {1, 2, 3};
  v.insert_many_back(4, 5, 6, 7, 8);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v.size(), 8U);
}

TEST(Vector_method, insert_many_back_method) {
  vector<int> v = {1, 2, 3};
  v.insert_many(v.cbegin(), 4, 5, 6);
  EXPECT_EQ(vct[0], 4);
  EXPECT_EQ(vct[2], 6);
  EXPECT_EQ(vct[3], 1);
  EXPECT_EQ(vct.size(), 6U);
}