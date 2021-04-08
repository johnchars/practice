#include <ros/ros.h>
#include "nav_msgs/OccupancyGrid.h"

#include <iostream>

int main(int argc, char** argv) {
	ros::init(argc, argv, "map_publisher");
	ros::NodeHandle nh;
	ros::Publisher publisher( nh.advertise<nav_msgs::OccupancyGrid>("map", 1, true) ); 
	// ros::Timer timer(nh.createTimer(
	// 			ros::Duration(1.0), callback, this));
	ros::Rate loop_rate(1);

	while (ros::ok()) {
		nav_msgs::OccupancyGrid map;
		// nav_msgs::OccupancyGridPtr map_ptr=map;
		publisher.publish(map);
		ROS_INFO("publishing ...");
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}