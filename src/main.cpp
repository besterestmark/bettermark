#include <iostream>
#include <string>
#include "parser.hpp"

int main(int argc, const char** argv) {
  std::cout << main_parse(argv[1]) << std::endl;
  return 0;
}
