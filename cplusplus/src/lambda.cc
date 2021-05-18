#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <functional>

using Callback = std::function<void(int, int)>;

void print(int lhs, int rhs) {
	// std::cout << "first: " << lhs << ", second: " << rhs << std::endl;
	std::cout << "lambda internal function.\n";
}

void test(Callback call_back) {
	std::cout << "test.\n";
}

int main(int argc, char** argv) {
  test([](int lhs, int rhs){print(lhs,rhs);});
  return 0;
}