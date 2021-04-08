#include <iostream>
#include "eigen3/Eigen/Eigen"
#include "eigen3/Eigen/Dense"
#include <cmath>

int main() { 
    Eigen::Vector3f v(1,2,3);
    std::cout << "v=[" << v(0) <<", " << v(1) << ", " << v(2)
      << "]\n";
    std::cout << "UnitX()= " << Eigen::Vector3f::UnitX() << std::endl;
    Eigen::Quaternionf q(0.707107, 0, 0, 0.707107);
    Eigen::AngleAxisf bar(q);
    std::cout << "angle: " << bar.angle() << std::endl;

    if ( std::abs(3.2 - 3.20000004768) < 0.05) {
    	std::cout << "true\n";
    } else {
    	std::cout << "bad\n";
    }

    return 0;
}