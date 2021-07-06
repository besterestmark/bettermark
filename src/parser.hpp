#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
std::string readfile(const char *filename);
std::string reg_converter(std::string text);
std::string fence_converter(std::string text);
std::string main_parse(const char *filename);
#endif

