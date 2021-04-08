#include <iostream>
#include <map>
#include <vector>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::vector;

struct Candinate
{
	int k;
	//vector<float> points;
	vector<int> num;
	Candinate() {
		k = -1;
		num.push_back(0);
	}
	Candinate(int lhs, vector<int>& rhs) {
		k = lhs;
		num = rhs;
	}
	Candinate operator=(Candinate& other) {
		k = other.k;
		num = other.num;
		return *this;
	}
};

int main(){
	cout << "\n===分割线===\n";
	map<int, Candinate> foobar;
	map<int, float> temp;

	vector<int> bar;
	for (int i=10; i>0; i--) {
		for (int j=0; j<5; j++) {
			bar.push_back(j);
		}
		Candinate foo= Candinate(i, bar);

		foobar.insert( pair<int, Candinate>(bar.size(), foo) );
		bar.clear();
	}
	cout << "size: " << foobar.size() << ", "
		<< "max_size: " << foobar.max_size() << endl;

	cout << "Last element: " << foobar.lower_bound(foobar.end()->first)->first 
	<< ", " << foobar.lower_bound(foobar.end()->first)->second.k << ", "
	<<  foobar.lower_bound(foobar.end()->first)->second.num.size() << ", "
	<< foobar.lower_bound(foobar.end()->first)->second.num[4] << endl;
	//	<< endl;

	/*	
	cout << "start: \n";
	temp.insert(pair<int, float>(1, 1.5));
	temp.insert(pair<int, float>(5, 5.5));
	temp.insert(pair<int, float>(0, 0.5));
	cout << "print: \n";
	cout << "temp last element: " << temp.lower_bound(temp.end()->first)->first 
	<< temp.lower_bound(temp.end()->first)->second << endl;
	*/
	return 0;
}
