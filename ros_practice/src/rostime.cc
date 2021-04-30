#include <iostream>
#include <ctime>
#include "ros/ros.h"

int main(int argc, char** argv) {
  ros::init(argc, argv, "time_monitor");
  ros::NodeHandle node_handle;
  ROS_INFO("Start time monitor");

  ros::Rate rate(10.0);
  ros::Time last = ros::Time::now();
  ros::Time now = ros::Time::now();
  time_t last_t = time(0);
  time_t now_t = time(0);
  while (node_handle.ok()){
    now = ros::Time::now();
    now_t = time(0);
    if (now<last) {
      std::cout << "ROS:\n"
        << "last: " << static_cast<double>(last.toSec()) 
        << ", now: " << static_cast<double>(now.toSec())
        << "\n";
    }
    if (now_t<last_t) {
      std::cout <<  "WARNING:\n" << "last: " << last_t 
        << ", now: " << now_t << "\n";
    }
    rate.sleep();
  }

  return 0;
}