#include "ros_practice/multi.h"
#include <iostream>

using std::cout;
using std::endl;
using namespace multi;

int main(int argc, char** argv) {
	ros::init(argc, argv, "multi_cb", ros::init_options::AnonymousName);
	Practice foobar;
	foobar.Run();
	std::cout << "Finished.\n";
	return 0;
}