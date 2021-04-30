#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>

void poseCallback(const ros::WallTimerEvent& unused_timer_event){
  static tf2_ros::TransformBroadcaster br;
  geometry_msgs::TransformStamped transformStamped;
  
  transformStamped.header.stamp = ros::Time::now();
  transformStamped.header.frame_id = "parent";
  transformStamped.child_frame_id = "child";
  transformStamped.transform.translation.x = 3;
  transformStamped.transform.translation.y = 4;
  transformStamped.transform.translation.z = 0.0;
  tf2::Quaternion q;
  q.setRPY(0, 0, 0);
  transformStamped.transform.rotation.x = q.x();
  transformStamped.transform.rotation.y = q.y();
  transformStamped.transform.rotation.z = q.z();
  transformStamped.transform.rotation.w = q.w();

  br.sendTransform(transformStamped);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "tf_broadcaster");

  ros::NodeHandle node;
  ros::WallTimer tf_wall_timer = node.createWallTimer(ros::WallDuration(0.1), &poseCallback);

  ros::spin();
  return 0;
};