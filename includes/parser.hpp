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
  std::regex ABBREVIATIONS(R"(\[(.+)\]:\s(.+))");
  std::regex UNDERLINE(R"(_(.+)_)");
  std::regex SPOILER(R"(!!(.+)!!)");
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

struct MODE{
  bool COLLAPSIBLE=false;
  bool CUSTOM_CLASS=false;
  bool BLOCKQUOTE_FENCED=false;
};

inline std::string fence_parse(std::string text) {
  std::string return_buf;
  MODE special_state;

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
    int line_siz = this_line.size()-1;
    if ((this_line.rfind("+++", 0) == 0)){
      if(special_state.COLLAPSIBLE){
        return_buf+="</details>\n";
      }
      else{
        return_buf+="<details><summary>"+this_line.substr(4, line_siz)+"</summary>\n";
        special_state.COLLAPSIBLE=true;
      }
    }
    else if ((this_line.rfind(":::", 0) == 0)){
      if(special_state.CUSTOM_CLASS){
        return_buf+="</div>\n";
      }
      else{
        return_buf+="<div class=\""+this_line.substr(4, line_siz)+"\">\n";
        special_state.CUSTOM_CLASS=true;
      }
    }

    else if ((this_line.rfind("<<<", 0) == 0)){
      if(special_state.BLOCKQUOTE_FENCED){
        return_buf+="</blockquote>\n";
      }
      else{
        /* Add some code to include citation
         * <blockquote cite="wikipedia.org/en/apple"> 
         * apple tastes nice btw
         * </blockquote>
         * from
         * <<< wikipedia.org/en/apple
         * apple tastes nice btw
         * <<<
        */

        return_buf+="<blockquote>\n";
        special_state.BLOCKQUOTE_FENCED = true;
      }
      //special_state.BLOCKQUOTE_FENCED=!special_state.BLOCKQUOTE_FENCED;
    }
    else if ((this_line.rfind("###### ", 0) == 0)){
      return_buf+="<h6>"+this_line.substr(7, line_siz)+"</h6>";
    }
    else if ((this_line.rfind("##### ", 0) == 0)){
      return_buf+="<h5>"+this_line.substr(6, line_siz)+"</h5>";
    }

    else if ((this_line.rfind("#### ", 0) == 0)){
      return_buf+="<h4>"+this_line.substr(4, line_siz)+"</h4>";
    }
    else if ((this_line.rfind("### ", 0) == 0)){
      return_buf+="<h3>"+this_line.substr(3, line_siz)+"</h3>";
    }

    else if ((this_line.rfind("## ", 0) == 0)){
      return_buf+="<h2>"+this_line.substr(2, line_siz)+"</h2>";
    }
    else if ((this_line.rfind("# ", 0) == 0)){
      return_buf+="<h1>"+this_line.substr(1, line_siz)+"</h1>";
    }
    else if ((this_line.rfind("> ", 0) == 0)){
      return_buf+="<blockquote>"+this_line.substr(1, line_siz)+"</blockquote>";
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
  return fence_parse(file_c);
}
