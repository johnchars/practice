#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>

class Collator {
public:
  Collator();
  ~Collator();
  void Run();
private:
  void ScanCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
  void RangeCallback(const sensor_msgs::Range::ConstPtr& msg);
  void PointCloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg);
  void TfCheck(const ros::WallTimerEvent& timer_event);
  ros::NodeHandle nh_;
  ros::NodeHandle nh_private_;
  ros::Subscriber scan_subscriber_;
  ros::Subscriber sonar_subscriber_;
  ros::Subscriber pointcloud_subscriber_;
  tf2_ros::Buffer tfBuffer;
  tf2_ros::TransformListener* tfListener=nullptr;
  ros::Time scan_stamp_;
  ros::Time range_stamp_;
  ros::Time pointcloud_stamp_;
  ros::WallTimer tf_timer_;
  std::string laser_frame_;
  std::string range_frame_;
  std::string reference_frame_;
};

Collator::Collator() {
  tfListener = new tf2_ros::TransformListener(tfBuffer);
  nh_private_.param("reference_frame", 
      reference_frame_, std::string("map"));
  scan_stamp_ = ros::Time::now();
  range_stamp_ = ros::Time::now();
  pointcloud_stamp_ = ros::Time::now();
  laser_frame_ = std::string("laser");
  range_frame_ = std::string("sonar");
  scan_subscriber_ = nh_.subscribe("/scan", 1, &Collator::ScanCallback, this);
  sonar_subscriber_ = 
      nh_.subscribe("/base_driver/sonar_mid", 1, &Collator::RangeCallback, this);
  pointcloud_subscriber_ = nh_.subscribe(
      "/scan_matched2_for_navi", 1, &Collator::PointCloudCallback, this);
  tf_timer_ = nh_.createWallTimer(
      ros::WallDuration(0.1), &Collator::TfCheck, this);
  ROS_INFO("initialized.");
}

Collator::~Collator() {
  delete tfListener;
}

void Collator::Run() {
  ros::spin();
}

void Collator::ScanCallback(
    const sensor_msgs::LaserScan::ConstPtr& msg) {
  scan_stamp_ = msg->header.stamp;
  if (laser_frame_ != msg->header.frame_id)
    laser_frame_ = msg->header.frame_id;
}

void Collator::RangeCallback(
    const sensor_msgs::Range::ConstPtr& msg) {
  range_stamp_ = msg->header.stamp;
  if (range_frame_ != msg->header.frame_id)
    range_frame_ = msg->header.frame_id;
}

void Collator::PointCloudCallback(
    const sensor_msgs::PointCloud2::ConstPtr& msg) {
  pointcloud_stamp_ = msg->header.stamp;
}

void Collator::TfCheck(const ros::WallTimerEvent& timer_event) {
  // geometry_msgs::TransformStamped transformStamped;
  // geometry_msgs::TransformStamped transformStamped2;
  try{
      ros::Time map2laser_stamp = tfBuffer.lookupTransform(
          reference_frame_, laser_frame_, 
          ros::Time(0)).header.stamp;
      ros::Time map2range_stamp = tfBuffer.lookupTransform(
          reference_frame_, range_frame_, 
          ros::Time(0)).header.stamp;
      double scan_vs_range = (scan_stamp_ - range_stamp_).toSec() * 1e3;
      double scan_vs_pcl = (scan_stamp_ - pointcloud_stamp_).toSec() * 1e3;
      double dur_scan_map = (scan_stamp_ - map2laser_stamp).toSec() * 1e3;
      double dur_pcl_map = 
          (pointcloud_stamp_ - map2laser_stamp).toSec() * 1e3;
      double dur_range_map = 
          (range_stamp_ - map2range_stamp).toSec() * 1e3;
      double scan_vs_range_tf = 
          (map2laser_stamp - map2range_stamp).toSec() * 1e3;
      auto func = [&](){
        ROS_INFO("now.");
        std::cout << "scan - range timestamp : " << scan_vs_range << "\n";
        std::cout << "scan - pcl timestamp : " << scan_vs_pcl << "\n";
        std::cout << "scan - map2laser timestamp: " << dur_scan_map << "\n";
        std::cout << "dur_pcl_map: " << dur_pcl_map << "\n";
        std::cout << "range - map2range timestamp: " << dur_range_map << "\n";
        std::cout << "map2laser - map2range: " << scan_vs_range_tf << "\n\n";
      };
      if (std::abs(scan_vs_range) > 200 || std::abs(scan_vs_pcl)>200
          || std::abs(dur_scan_map)>200 || std::abs(dur_pcl_map)>200
          || std::abs(dur_range_map)>200 || std::abs(scan_vs_range_tf)>200)
        func();
      
    }
    catch (tf2::TransformException &ex) {
      ROS_WARN("%s",ex.what());
    }
}

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_time_checker");
  Collator collator;
  collator.Run();
  return 0;
};