#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int hundred = 100;
  uint8_t foo;
  char bar=100;
  cout << "sizeof uint8_t " << sizeof(foo) << ", bar" <<  sizeof(bar) << endl;
  foo = 100;
  std::cout << "foo: " << foo << ", value=100\n";
  std::cout << "bar: " << bar << ", value=100.\n";

  foo = hundred;
  std::cout << "foo: " << foo << ", value=100\n";
  return 0;
}