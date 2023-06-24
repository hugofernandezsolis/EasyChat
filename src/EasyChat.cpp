#include <iostream>

#include <Error.h>
#include <Socket.h>

using namespace chat;
using namespace error;

int main(void) {
  std::cout << error_c() << std::endl;
  return 0;
}