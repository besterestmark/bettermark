#include <array>
#include <cerrno>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

inline std::string readfile(const char *filename) {
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in) {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return (contents);
  }
  throw(errno);
}

// TODO: implement CUSTOM_CLASS and COLLAPSIBLE
inline std::string reg_parse(std::string text) {
  std::regex BOLD(R"(\*\*(.+)\*\*)");
  std::regex ITALIC(R"(\*(.+)\*)");
  std::regex STRIKETHROUGH(R"(~~(.+)~~)");
  std::regex IMAGE_SIZE(R"(!\[(.+)\]\((.+) (.+) =(.+)x(.+)\))");
  std::regex ABBREVIATIONS(R"(\*\[(.+)\]:\s(.+))");
  std::regex UNDERLINE(R"(_(.+)_)");
  std::regex SPOILER(R"(!!(.+)!!)");
  std::regex HEADING_1(R"(#\s(.+))");
  std::regex HEADING_2(R"(##\s(.+))");
  std::regex HEADING_3(R"(###\s(.+))");
  std::regex HEADING_4(R"(####\s(.+))");
  std::regex HEADING_5(R"(#####\s(.+))");
  std::regex HEADING_6(R"(######\s(.+))");
  text = regex_replace(text, HEADING_6, "<h6>$1</h6>");
  text = regex_replace(text, HEADING_5, "<h5>$1</h5>");
  text = regex_replace(text, HEADING_4, "<h4>$1</h4>");
  text = regex_replace(text, HEADING_3, "<h3>$1</h3>");
  text = regex_replace(text, HEADING_2, "<h2>$1</h2>");
  text = regex_replace(text, HEADING_1, "<h1>$1</h1>");
  text = regex_replace(text, SPOILER, "<span class=\"spoiler\">$1</span>");
  text = regex_replace(text, UNDERLINE, "<u>$1</u>");
  text = regex_replace(text, ABBREVIATIONS, "<abbr title=\"$1\">$2</abbr>");
  text = regex_replace(
      text, IMAGE_SIZE,
      "<img src=\"$2\" title=$3 alt=\"$1\" width=\"$4\" height=\"$5\">");
  text = regex_replace(text, STRIKETHROUGH, "<s>$1</s>");
  text = regex_replace(text, BOLD, "<strong>$1</strong>");
  text = regex_replace(text, ITALIC, "<em>$1</em>");
  return text;
}

inline std::string fence_parse(std::string text) {
  std::string return_buf;
  bool COLLAPSIBLE_special_mode;
  bool CUSTOM_CLASS_special_mode;

  size_t start = 0;
  size_t end;
  while (1) {
    std::string this_line;
    if ((end = text.find("\n", start)) == std::string::npos) {
      if (!(this_line = text.substr(start)).empty()) {
        return_buf+=this_line+"this shouldn't come";
      }

      break;
    }

    this_line = text.substr(start, end - start);
    if ((this_line.rfind("+++", 0) == 0)){
      if(COLLAPSIBLE_special_mode){
        return_buf+="</details>\n";
      }
      else{
        return_buf+="<details><summary>"+this_line.substr(4, this_line.size()-1)+"</summary>\n";
        COLLAPSIBLE_special_mode=true;
      }
    }
    else if ((this_line.rfind(":::", 0) == 0)){
      if(COLLAPSIBLE_special_mode){
        return_buf+="</div>\n";
      }
      else{
        return_buf+="<div class=\""+this_line.substr(4, this_line.size()-1)+"\">\n";
        COLLAPSIBLE_special_mode=true;
      }
    }

    else{
    return_buf+=this_line+"\n";
    }
    start = end + 1;
  }
  return return_buf;
}
inline std::string main_parse(const char *filename) {
  std::string file_c = readfile(filename);
  return reg_parse(fence_parse(file_c));
}
