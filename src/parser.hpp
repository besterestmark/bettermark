#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
std::string Readfile(const char *kFilename);
std::string RegexConverter(std::string text);
std::string FenceConverter(const std::string *text);
std::string ConverterInitiater(const char *kFilename);
#endif

