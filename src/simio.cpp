#include <fstream>
#include <string>
#include <iostream>

#include "simio.hpp"

std::string Readfile(const char *kFilename)
{
  std::ifstream in(kFilename, std::ios::in | std::ios::binary);
  if (in) {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return (contents);
  }
  std::cerr << "Cannot find file" << std::endl;
  exit(2);
}
