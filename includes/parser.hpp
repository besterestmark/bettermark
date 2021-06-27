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

//TODO: implement CUSTOM_CLASS and ABBREVIATIONS
std::string reg_parse(std::string text){
  std::regex BOLD(R"(\*\*(.*)\*\*)");
  std::regex ITALIC(R"(\*(.*)\*)");
  std::regex STRIKETHROUGH(R"(~~(.*)~~)");
  std::regex IMAGE_SIZE(R"(!\[(.*)\]\((.*) (.*) =(.*?)x(.*?)\))");
  std::regex ABBREVIATIONS(R"(\*\[(.*)\]:\s(.*))");
  std::regex UNDERLINE(R"(_(.*)_)");
  std::regex SPOILER(R"(!!(.*)!!)");
  std::regex HEADING_1(R"(#\s(.*))");
  std::regex HEADING_2(R"(##\s(.*))");
  std::regex HEADING_3(R"(###\s(.*))");
  std::regex HEADING_4(R"(####\s(.*))");
  std::regex HEADING_5(R"(#####\s(.*))");
  std::regex HEADING_6(R"(######\s(.*))");
  text = regex_replace(text, HEADING_6, "<h6>$1</h6>");
  text = regex_replace(text, HEADING_5, "<h5>$1</h5>");
  text = regex_replace(text, HEADING_4, "<h4>$1</h4>");
  text = regex_replace(text, HEADING_3, "<h3>$1</h3>");
  text = regex_replace(text, HEADING_2, "<h2>$1</h2>");
  text = regex_replace(text, HEADING_1, "<h1>$1</h1>");
  text = regex_replace(text, SPOILER, "<span class=\"spoiler\">$1</span>");
  text = regex_replace(text, UNDERLINE, "<u>$1</u>");
  text = regex_replace(text, ABBREVIATIONS, "<abbr title=\"$1\">$2</abbr>");
  text = regex_replace(text, IMAGE_SIZE, "<img src=\"$2\" title=$3 alt=\"$1\" width=\"$4\" height=\"$5\">");
  text = regex_replace(text, STRIKETHROUGH, "<s>$1</s>");
  text = regex_replace(text, BOLD, "<strong>$1</strong>");
  text = regex_replace(text, ITALIC, "<em>$1</em>");
  return text;
}

std::string main_parse(const char *filename){
  std::string file_c = readfile(filename);
  return reg_parse(file_c);
}
