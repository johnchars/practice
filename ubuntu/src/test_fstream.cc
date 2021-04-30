#include <iostream>
#include <fstream>
#include <ctime>

int main(int argc, char** argv) {
  std::string config_file = argv[1];
  time_t now = time(0); 
  std::ofstream out;
  out.open(config_file, std::ios::trunc);
  if (out.is_open()) {
    std::cout << "opened.\n";
  } else 
    std::cout << "failed to open.\n";
  out << "time: " << ctime(&now)
    << "cnt_one_cycle: " << 4096 << "\n";
  out.close();
  return 0;
}