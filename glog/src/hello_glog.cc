#include "glog/logging.h"
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize Google’s logging library.
    google::InitGoogleLogging(argv[0]);
    int num_cookies = 5;
    std::cout << "start.\n";
    LOG(INFO) << "Found " << num_cookies << " cookies";
    std::cout << "end.\n";
    return 0;
}