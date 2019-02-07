//
// Created by simone on 07.02.19.
//

#include <iostream>

int main(int argc, const char *argv[]) {

  auto lambda = [](int i) { return i + 1; };
  std::cout << lambda(5);
  return 0;
}