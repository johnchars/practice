#include "ros_practice/multi.h"
#include "std_msgs/String.h"

namespace multi { 
	Practice::Practice() {

		n_1_.setCallbackQueue(&queue_1_);
		n_2_.setCallbackQueue(&queue_2_);

		publisher_a_ = n_1_.advertise<std_msgs::String>("/topic_1", 5, true);
		timer1_ = n_1_.createTimer(
				ros::Duration(1.0), &Practice::callback1, this);

		publisher_b_ = n_2_.advertise<std_msgs::String>("/topic_2", 10, true);
		timer2_ = n_2_.createTimer(
				ros::Duration(0.1), &Practice::callback2, this);

	}

	void Practice::Run() {
		while (ros::ok()) {
			queue_1_.callAvailable(ros::WallDuration());
			queue_2_.callAvailable(ros::WallDuration());
		}
		/*
		ros::AsyncSpinner spinner1(2, &queue_1_);
		ros::AsyncSpinner spinner2(2, &queue_2_);
		spinner1.start();
		spinner2.start();
		*/
		ros::waitForShutdown();
	}

	void Practice::callback1(const ros::TimerEvent& timer) {
		std_msgs::String msg;
		msg.data = "hello nodehandle 1.";
		publisher_a_.publish(msg);
	}

	void Practice::callback2(const ros::TimerEvent& timer) {
		std_msgs::String msg;
		msg.data = "Oh, This is nodehandle 2.";
		publisher_b_.publish(msg);
	}
}