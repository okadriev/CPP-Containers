SHELL = /bin/sh

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror --std=c++17 -g
GFLAGS = -lgtest -lstdc++
#DIRECTORIES = . tests/ s21_array/ s21_list/ s21_map/ s21_multiset/ s21_queue/ s21_set/ s21_stack/ s21_vector/
DIRECTORIES = . tests/ ss21_queue/ s21_set/ s21_stack/ s21_vector/
ALL_SRC = $(foreach DIR, $(DIRECTORIES), $(wildcard $(DIR)/*.tpp))
ALL_HEADERS = $(foreach DIR, $(DIRECTORIES), $(wildcard $(DIR)/*.hpp))
TEST_FILES = $(wildcard tests/*.cpp)

all: clear clean test

clean:
	rm -rf *.o *.a test *.gcno *.gcda *.info
	rm -rf report

test: clear clean
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o test $(GFLAGS)
	./test
	rm test

gcov_report: clear clean
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o test $(GFLAGS) --coverage
	./test
	lcov --no-external -t "test" -o test.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	genhtml -o report test.info -rc lcov_branch_coverage=1
	rm -rf *.gcno *.gcda *.gcov

clang-format:
	clang-format -i $(ALL_SRC) $(ALL_HEADERS)

clang-check:
	clang-format -n $(ALL_SRC) $(ALL_HEADERS)

valgrind: clean
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o test $(GFLAGS)
	valgrind --tool=memcheck --leak-check=yes ./test
	rm test

clear:
	clear

.PHONY: all clean test gcov_report clang-format clang-check valgrind clear