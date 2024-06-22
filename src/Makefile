SHELL = /bin/sh 

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g

all: clang-format build

build:
	$(CXX) $(CXXFLAGS) s21_vector/main.cpp -o s21_vector/main
	s21_vector/main

clang-format:
	clang-format -i *.cpp *.hpp */*.cpp */*.hpp

clang-check:
	clang-format -n *.cpp *.hpp */*.cpp */*.hpp