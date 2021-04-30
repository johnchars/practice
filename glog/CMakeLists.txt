cmake_minimum_required (VERSION 3.0.2)
project (glog_test VERSION 1.0)
set(CMAKE_INCLUDE_PATH /usr/include/)
set(CMAKE_LIBRARY_PATH /usr/lib/)
INCLUDE_DIRECTORIES(/usr/include/)
LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)
# FIND_PATH(Glog)
# set(CXXFLAGS -fPIC)
# find_package (Glog 0.4 REQUIRED)
#message(STATUS ${glog_LIBRARIES})
find_package(Threads)
# find_package(Unwind)

include_directories(/usr/include/glog/)
add_executable (hello_glog src/hello_glog.cc)

target_link_libraries (hello_glog 
  /usr/lib/x86_64-linux-gnu/libglog.a
  /usr/lib/x86_64-linux-gnu/libgflags.a
  ${CMAKE_THREAD_LIBS_INIT}
  /usr/lib/x86_64-linux-gnu/libunwind.so.8.0.1
)