#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
int main(int argc, char** argv) {
  time_t current = time(0);
  // struct tm* timeinfo;
  std::cout << "time: " << ctime(&current) << "\n";
  // struct tm* timeinfo = localtime(&current);
  // std::cout << "asctime: " << asctime(timeinfo) << "\n";
  // printf ("The current local time is: %s", ctime (&current));
  return 0;
}