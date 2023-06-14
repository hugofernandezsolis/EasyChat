#include <iostream>

#include <Exception.h>

int main_func(void) {
  std::cout << "Hola mundo desde main_func()" << std::endl;
  return 0;
}

int main(void) {
  main_func();

  Exception e;
}