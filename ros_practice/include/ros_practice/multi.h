#ifndef _MULTI_H_
#define _MULTI_H_

#include <ros/ros.h>
#include <ros/callback_queue.h>

namespace multi {
	class Practice {
	public:
		Practice();
		~Practice(){};
		void Run();
	private:
		void callback1(const ros::TimerEvent& timer);
		void callback2(const ros::TimerEvent& timer);
		ros::NodeHandle n_1_;
		ros::NodeHandle n_2_;
		ros::Publisher publisher_a_;
		ros::Publisher publisher_b_;
		ros::CallbackQueue queue_1_;
		ros::CallbackQueue queue_2_;
		ros::Timer timer1_;
		ros::Timer timer2_;
		/*
		ros::AsyncSpinner spinner1(2, &queue_1_);
		ros::AsyncSpinner spinner2(2, &queue_2_);
		*/
	};
} 

#endif