#include <iostream>
#include <fstream>
#include <string>
#include <boost/filesystem.hpp>
#include <ctime>

int main(int argc, char** argv) {
  std::string config_file = std::getenv("HOME");
  std::cout << "HOME" << config_file << "\n";
  config_file += std::string("/log/odom_param.yaml");
  boost::filesystem::path p(config_file);
  if (!boost::filesystem::exists(p)){
    std::cout << "file doesn't exits.\n";
    if (!boost::filesystem::create_directories(p)) {
      std::cout << "create yaml.\n";
    } else {
      std::cout << "failed create config.\n";
    }
  }
  std::ofstream out(config_file, std::ios::trunc);
  time_t t = time(0);
  out << "update_time: " << t << "\n";
  out << "left_radius: " << 0.07 << "\n";
  out << "right_radius: " << 0.069 << "\n";
  out.close();
  return 0;
}