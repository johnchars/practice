#include <ros/ros.h>
#include "practice/practice.h"
#include "std_msgs/String.h"
#include <string>
#include "opencv/cv.hpp"

using namespace practice;

ros::Publisher foo_pub;
ros::WallTimer foo_pub_timer;

void publisher(const ros::WallTimerEvent& unused_timer_event) {
	std_msgs::String msg;
	msg.data = std::string("Hello WallTimer");
	foo_pub.publish(msg);
}

int main(int argc, char** argv) {
	ros::init(argc, argv, "practice");
	ros::NodeHandle node_handle;
	std::cout << "Enter q to escape.\n";
	char flag=std::cin.get();
	while (flag!='q' && flag!='Q') {
			Foo bar;
			int id;
			std::string name;
			float anyway;
			std::cout << "Enter ID:\t";
			std::cin >> id;
			std::cout << "\nEnter Name:\t";
			std::cin >> name;
			std::cout << std::endl;
			bar.fill(id,name);
			bar.show();
			// 清空当前行输入
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

			std::cout << "Enter float:\n";
			std::cin >> anyway;
			bar.FillInfo(id,name,anyway);
			bar.ShowInfo();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "getchar()\n";
			flag = std::cin.get();
	}

	float angle;
	float temp[3];
	Vector3f axis;
	Foo bar;
	axis = Vector3f(1,2,3);
	cv::Point2f point(1, 2);
	/*
	cout << "Enter an angle \n an axis:\n";
	cin >> angle;
	cin >> temp[0] >> temp[1] >> temp[2];
	axis=Vector3f(temp[0],temp[1],temp[2]);
	cout << "angle is : " << angle << "\nAxis is : "
		<< axis << endl;
	bar.FillRotation(angle,axis);
	bar.ToQuaternion();
	*/
	cout << "point2f " << point.x << ", "<< point.y<< endl;
	cout << "enter an angle.\n";
	cin >> angle;
	while (angle <= -360 || angle >= 360) {
		if (angle < 0) {
			angle +=360;
		}
		else angle -=360;
	}
	cout << "angle = " << angle << "std::vector.head<2> :" 
		<< axis[0] << ", " << axis[1] << endl;

	cout << "point = " << point << endl;
	cin.get();
	foo_pub = node_handle.advertise<std_msgs::String>(
              "practice", 10, true /* latched */);
	foo_pub_timer = node_handle.createWallTimer(ros::WallDuration(1),
                                       publisher);
	ros::spin();
	return 0;
}