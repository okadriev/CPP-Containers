CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17 
TEST_FLAGS = -lgtest -pthread
TEST_TARGET = test

all: test

clean:
	@echo "Deleting unnecessary files..."
	@rm -rf *.o *.a *.out *.log $(TEST_TARGET)

test: clear clean
	@$(CC) $(CFLAGS) tests/*.cpp -lstdc++ -lsupc++ -lgcc $(TEST_FLAGS) -o $(TEST_TARGET)
	./$(TEST_TARGET)

leaks: 
	@valgrind --tool=memcheck --leak-check=yes ./test

check_style:
	@find . \( -name '*.hpp' -o -name '*.tpp' \) -print0 | xargs -0 clang-format -n -style=Google

gcov_report: clear clean
	$(CXX) $(CXXFLAGS) $(TEST_FILES) -o test $(GFLAGS) --coverage
	./test
	lcov --no-external -t "test" -o test.info -c -d . -rc lcov_branch_coverage=1 --exclude "$(PWD)/tests/*"
	genhtml -o report test.info -rc lcov_branch_coverage=1
	rm -rf *.gcno *.gcda *.gcov

clear:
	clear

.PHONY: all clean test gcov_report clang-format clang-check valgrind clear