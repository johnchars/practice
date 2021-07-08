#include <stdlib.h>
#include <iostream>

int main(int argc, char** argv) {
	std::cout << "rand(): " << (double)rand()/RAND_MAX << std::endl;
	return 0;
}