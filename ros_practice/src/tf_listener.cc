#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_listener");

  ros::NodeHandle node;

  tf2_ros::Buffer tfBuffer;
  tf2_ros::TransformListener tfListener(tfBuffer);

  ros::Rate rate(10.0);
  while (node.ok()){
    geometry_msgs::TransformStamped transformStamped;
    geometry_msgs::TransformStamped transformStamped2;
    try{
      transformStamped = tfBuffer.lookupTransform("parent", "child",
                               ros::Time(0));
      transformStamped2 = tfBuffer.lookupTransform("child", "parent",
                               ros::Time(0));
      ROS_INFO("get tf.");
      std::cout << "position:[ " << transformStamped.transform.translation.x
        << ", " << transformStamped.transform.translation.y 
        << ", " << transformStamped.transform.translation.z << " ]\n";
      std::cout << "position.inverse() : [ " 
        << transformStamped2.transform.translation.x
        << ", " << transformStamped2.transform.translation.y 
        << ", " << transformStamped2.transform.translation.z << " ]\n";
    }
    catch (tf2::TransformException &ex) {
      ROS_WARN("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    rate.sleep();
  }
  return 0;
};