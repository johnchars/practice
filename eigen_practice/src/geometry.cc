#include <iostream>
#include "eigen3/Eigen/Core"
#include "eigen3/Eigen/Geometry"

int main(int argc, char** argv) {
  float test = 5;
  std::cout << "UnitX(): " << Eigen::Vector3f::UnitX() << "\n";
  std::cout << "float * UnitX(): " << test*Eigen::Vector3f::UnitX() << "\n";
  return 0;
}