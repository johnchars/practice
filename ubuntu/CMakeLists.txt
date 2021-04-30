cmake_minimum_required(VERSION 3.0)
project(ubuntu)
add_executable(test_stat src/test_stat.cc)
target_link_libraries(test_stat 
  
)

add_executable(test_time src/test_time.cc)

add_executable(test_fstream src/test_fstream.cc)