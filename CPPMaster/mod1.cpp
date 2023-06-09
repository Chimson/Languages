#include <iostream>
#include "header1.h"
int main() {
  extern int p;     // reads extern p from header1.h
  extern const int N;  // reads from header1.h
  std::cout << p << std::endl;
  std::cout << N << std::endl;
  return 0;
}