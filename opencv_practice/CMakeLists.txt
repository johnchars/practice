cmake_minimum_required(VERSION 3.0.2)
project(opencv_practice)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
#find_package(glog 0.4.0 REQUIRED)

MESSAGE( WARNING "Eigen library direcotory is ${EIGEN3_INCLUDE_DIRS}")


include_directories(
  include
  ${Eigen_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

## Declare a C++ library
#add_library(${PROJECT_NAME}
#   src/practice.cpp
#)

add_executable(histogram src/histogram.cc)

target_link_libraries(histogram
  ${OpenCV_LIBRARIES}
)

#add_executable(glog src/log.cpp)
#target_link_libraries( glog glog::glog)
