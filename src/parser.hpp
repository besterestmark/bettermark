#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
std::string Readfile(const char *filename);
std::string RegexConverter(std::string text);
std::string FenceConverter(std::string text);
std::string ConverterInitiater(const char *filename);
#endif

