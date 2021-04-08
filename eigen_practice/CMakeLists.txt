cmake_minimum_required(VERSION 3.0.2)
project(eigen_practice)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

find_package(Eigen3 REQUIRED)
#find_package(OpenCV REQUIRED)
#find_package(glog 0.4.0 REQUIRED)

MESSAGE( WARNING "Eigen library direcotory is ${EIGEN3_INCLUDE_DIRS}")


generate_messages(
  DEPENDENCIES
  std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(${PROJECT_NAME}
   src/practice.cpp
)

add_executable(${PROJECT_NAME}_node src/practice_node.cpp)

add_executable(eigen_node src/Eigen.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)

add_executable(eigen2 src/eigen2.cpp)

target_link_libraries(eigen2
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)

target_link_libraries(eigen_node
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)

add_executable(test_type src/testing_type.cpp)

target_link_libraries(test_type
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)


add_executable(map_container src/map_container.cpp)
target_link_libraries( map_container
  ${catkin_LIBRARIES}
)

#add_executable(glog src/log.cpp)
#target_link_libraries( glog glog::glog)

add_executable(vector_element src/vector.cc)

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_eigen_practice.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
