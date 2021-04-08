#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cmath>

using std::endl;
using std::cout;
using std::vector;

//using print=std::cout;

int main() {
	cout << "Type testing.\n";
	float foo = std::numeric_limits<float>::infinity();
	cout << "infinity: " << foo << endl;
	if (foo == std::numeric_limits<float>::infinity()) {
		cout << "equal.\n";
	} else cout << "not equal.\n";

	vector<int> foobar;
	for (int i=0; i<10; i++) {
		foobar.push_back(i);
	}

	for (vector<int>::iterator it = foobar.begin(); it!=foobar.end(); ++it) {
		cout << " " << *it << endl;
	}

	vector<int>::iterator bar = foobar.end() -1;
	cout << "The element in firse front of the last: " << *bar << endl;

	cout << "last : " << foobar.back() << ", end(): " << *foobar.end() << endl;
	cout << "begin: " << *foobar.begin() << endl;

	cout << "---line---\n";
	std::string home = std::getenv("HOME");
	cout << "${HOME}: " << home << endl;

	cout << "-------line---------\n";
	std::ofstream outfile;
	outfile.open(home+'/'+"angle.txt", std::ios::trunc);
	outfile << float(30);
	outfile.close();

	std::ifstream infile;
	infile.open(home+'/'+"angle.txt");
	float angle;
	infile >> angle ;
	infile.close();
	std::cout << "angle: " << angle << endl;

	float dx = 3.0;
	float dy = 4.0;
	std::cout << "5= " << std::sqrt( std::pow(dx, 2)+std::pow(dy,2) ) << std::endl;
	//print << "print.\n";

	std::cout << "--------line---------\n";


	return 0;
}