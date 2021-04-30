#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  const std::string home = std::getenv("HOME");
  std::string target = home+"/"+argv[1];
  struct stat sb;
  
  if (stat(target.c_str(),&sb)==-1) {
    std::cout << "doesn't exists.\n";
  } else {
    std::cout << "exists.\n";
  }
  switch (sb.st_mode & S_IFMT) {
    case S_IFDIR : std::cout << "directory.\n";
      break;
    case S_IFLNK : std::cout << "symlink.\n";
      break;
    case S_IFCHR : std::cout << "character device.\n";
      break;
    default :
      std::cout << "unknown.\n";
  }
  std::string file = target + "/" + argv[2];
  std::ifstream f(file.c_str());
  if (f.good()) {
    std::cout << "exist.\n";
  } else {
    std::cout << "not exist.\n";
  }
}