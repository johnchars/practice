#include "ros/ros.h"
#include "yaml-cpp/yaml.h"
#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <ctime>

using namespace std;
using namespace YAML;

int main(int argc, char** argv) {
  std::string config_file = std::getenv("HOME");
  std::cout << "HOME" << config_file << "\n";
  config_file += std::string("/log/odom_param.yaml");
  boost::filesystem::path p(config_file);
  if (!boost::filesystem::exists(p)){
      std::cout << "file doesn't exits.\n";
      return 1;
    }
  std::cout << "loadfile failed.\n";
  YAML::Node config = YAML::LoadFile(config_file);
  std::cout << "loadfile success.\n";
  if (config["time"]) {
    std::cout << "time " << config["time"].as<std::string>() << "\n";
  }
  time_t t = time(0);
  std::cout << "now : " << t << "\n";
  if (config["data_time"]) {
    std::cout << "Data_time " << config["data_time"].as<time_t>() << "\n";
  }
  if (config["update_time"]) {
    time_t last = config["update_time"].as<time_t>();
    std::cout << "update: " << last << "\n";
    time_t now = time(0);
    if (difftime(now, last)>5)
      std::cout << "update: " << last << ", " << now << "\n";
    std::cout << "left_radius: " << config["left_radius"].as<double>() << "\n";
    std::cout << "right_radius: " << config["right_radius"].as<double>() << "\n";
  }
  std::cout << "start invalid.\n";
  bool flag = false;
  if (config["invalid"]) {
    std::cout << "invalid: " << config["invalid"].as<string>() << "\n";
    flag = true;
  } else {
    std::cout << "Read invalid value error.\n";
  }
  if (!flag) {
    std::cout << "invalid: " << config["invalid"].as<float>() << "\n";
  } else {
    std::cout << "Read invalid value error.\n";
  }
  return 0;
}