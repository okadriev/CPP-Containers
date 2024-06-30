#include "tests.hpp"

TEST(MapConstructor, set_default) {
  map<int, std::string> test;

  EXPECT_EQ(test.size(), 0);
  EXPECT_EQ(test.empty(), true);
}

TEST(MapConstructor, set_param_1) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2(test1);

  EXPECT_EQ(test2.size(), 3);
  EXPECT_EQ(test2.contains(2), true);
}

TEST(MapConstructor, set_param_2) {
  map<int, std::string> test1;
  map<int, std::string> test2(test1);

  EXPECT_EQ(test2.size(), 0);
  EXPECT_EQ(test2.empty(), true);
}

TEST(MapMethod, set_copy) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2;

  test2 = test1;

  EXPECT_EQ(test2.size(), 3);
  EXPECT_EQ(test2.empty(), false);
}

TEST(MapMethod, set_move) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2;

  test2 = std::move(test1);

  EXPECT_EQ(test1.empty(), true);
  EXPECT_EQ(test2.size(), 3);
  EXPECT_EQ(test2.empty(), false);
}

TEST(MapMethod, set_clear_1) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  test1.clear();

  EXPECT_EQ(test1.size(), 0);
  EXPECT_EQ(test1.empty(), true);
}

TEST(MapMethod, set_clear_2) {
  map<int, std::string> test1;
  test1.clear();

  EXPECT_EQ(test1.size(), 0);
  EXPECT_EQ(test1.empty(), true);
}

TEST(MapMethod, set_insert) {
  map<int, std::string> test1;
  pair<int, std::string> element{2, "B"};

  test1.insert({1, "A"});
  pair<map<int, std::string>::iterator, bool> pair = test1.insert({2, "B"});
  test1.insert({3, "C"});

  EXPECT_EQ(test1.size(), 3);
  EXPECT_EQ(pair.second, true);
  EXPECT_EQ(*pair.first, element);
}

TEST(MapMethod, set_erase_1) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  test1.erase(2);

  EXPECT_EQ(test1.size(), 2);
  EXPECT_EQ(test1.contains(2), false);
}

TEST(MapMethod, set_erase_2) {
  map<int, std::string> test1{
      {1, "A"},  {2, "B"},  {3, "C"},  {4, "D"},  {5, "E"},  {6, "F"},
      {7, "G"},  {8, "H"},  {9, "I"},  {10, "J"}, {11, "K"}, {12, "L"},
      {13, "M"}, {14, "N"}, {15, "O"}, {16, "P"}, {17, "Q"}, {18, "R"},
      {19, "S"}, {20, "T"}, {21, "U"}, {22, "V"}, {23, "W"}, {24, "X"},
      {25, "Y"}, {26, "Z"}, {27, "a"}, {28, "b"}, {29, "c"}, {30, "d"}};
  test1.erase(11);
  test1.erase(6);
  test1.erase(12);
  test1.erase(22);
  test1.erase(1);
  test1.erase(26);
  test1.erase(30);
  test1.erase(19);
  test1.erase(9);
  test1.erase(18);
  test1.erase(4);
  test1.erase(2);
  test1.erase(15);
  test1.erase(23);
  test1.erase(27);
  test1.erase(24);
  test1.erase(7);
  test1.erase(14);
  test1.erase(21);
  test1.erase(8);
  test1.erase(29);
  test1.erase(5);
  test1.erase(28);
  test1.erase(10);
  test1.erase(13);
  test1.erase(25);
  test1.erase(3);
  test1.erase(17);
  test1.erase(16);
  test1.erase(20);

  EXPECT_EQ(test1.size(), 0);
  EXPECT_EQ(test1.empty(), true);
}

TEST(MapMethod, set_erase_ptr) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  test1.erase(test1.find(2));

  EXPECT_EQ(test1.size(), 2);
  EXPECT_EQ(test1.contains(2), false);
}

TEST(MapMethod, set_swap) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2{{4, "D"}, {5, "E"}, {6, "F"},
                              {7, "G"}, {8, "H"}, {9, "I"}};

  test1.swap(test2);

  EXPECT_EQ(test1.size(), 6);
  EXPECT_EQ(test2.size(), 3);

  EXPECT_EQ(test1.contains(4), true);
  EXPECT_EQ(test1.contains(5), true);
  EXPECT_EQ(test1.contains(6), true);
  EXPECT_EQ(test1.contains(7), true);
  EXPECT_EQ(test1.contains(8), true);
  EXPECT_EQ(test1.contains(9), true);

  EXPECT_EQ(test2.contains(1), true);
  EXPECT_EQ(test2.contains(2), true);
  EXPECT_EQ(test2.contains(3), true);
}

TEST(MapMethod, set_merge) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2{{4, "D"}, {5, "E"}, {6, "F"},
                              {7, "G"}, {8, "H"}, {9, "I"}};

  test1.merge(test2);

  EXPECT_EQ(test1.size(), 9);
  EXPECT_EQ(test2.size(), 6);

  EXPECT_EQ(test1.contains(4), true);
  EXPECT_EQ(test1.contains(5), true);
  EXPECT_EQ(test1.contains(6), true);
  EXPECT_EQ(test1.contains(7), true);
  EXPECT_EQ(test1.contains(8), true);
  EXPECT_EQ(test1.contains(9), true);
}

TEST(MapMethod, set_find) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  pair<int, std::string> element(2, "B");
  map<int, std::string>::iterator it = test1.find(2);

  EXPECT_EQ(*it, element);

  it = test1.find(10);

  EXPECT_EQ(it == test1.end(), true);
}

TEST(MapMethod, set_begin) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2{{3, "C"}, {2, "B"}, {1, "A"}};
  map<int, std::string> test3{{10, "J"}, {15, "K"}, {5, "I"}, {6, "H"},
                              {7, "G"},  {8, "F"},  {9, "E"}, {11, "D"},
                              {12, "C"}, {13, "B"}, {14, "A"}};

  pair<int, std::string> element1{1, "A"};
  pair<int, std::string> element2{3, "C"};
  pair<int, std::string> element3{10, "J"};

  EXPECT_EQ(*test1.begin(), element1);
  EXPECT_EQ(*test2.begin(), element2);
  EXPECT_EQ(*test3.begin(), element3);
}

TEST(MapMethod, set_end) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};
  map<int, std::string> test2{{3, "C"}, {2, "B"}, {1, "A"}};
  map<int, std::string> test3{{10, "J"}, {15, "K"}, {5, "I"}, {6, "H"},
                              {7, "G"},  {8, "F"},  {9, "E"}, {11, "D"},
                              {12, "C"}, {13, "B"}, {14, "A"}};

  map<int, std::string>::iterator result =
      (map<int, std::string>::iterator) nullptr;

  EXPECT_EQ(test1.end(), result);
  EXPECT_EQ(test1.end(), result);
  EXPECT_EQ(test3.end(), result);
}

TEST(MapMethod, set_max_size) {
  map<int, std::string> test1{{1, "A"}, {2, "B"}, {3, "C"}};

  EXPECT_GT(test1.max_size(), 1000);
}
