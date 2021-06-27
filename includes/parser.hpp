#include <iostream>
#include <string>
#include <fstream>
#include <cerrno>
#include <regex>
#include <string>
#include <array>

std::string readfile(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
}

std::string reg_parse(){
  std::regex CUSTOM_CLASS("");
  std::regex BOLD("");
  std::regex ITALIC("");
  std::regex STRIKETHROUGH("");
  std::regex IMAGE_SIZE("");
  std::regex COLLAPSIBLE("");
  std::regex ABBREVIATIONS("");
  std::regex UNDERLINE("");
  std::regex SPOILER("");
  return "";
}
