#include <cerrno>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "parser.hpp"

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

  std::string 
Readfile(const char *kFilename)
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
  throw(errno);
}

  std::string 
RegexConverter(std::string text) 
{
  std::regex BOLD(R"(\*\*(.+)\*\*)");
  std::regex ITALIC(R"(\*(.+)\*)");
  std::regex STRIKETHROUGH(R"(~~(.+)~~)");
  std::regex IMAGE_SIZE(R"(!\[(.+)\]\((.+) (.+) =(.+)x(.+)\))");
  std::regex ABBREVIATIONS(R"(\*\[(.+)\]:\s(.+))");
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

struct ActiveBlock{
  bool COLLAPSIBLE=false;
  bool CUSTOM_CLASS=false;
  bool BLOCKQUOTE_FENCED=false;
  bool CODE_FENCED=false;

  bool BOLD=false;
  bool ITALIC=false;
};

  std::string 
FenceConverter(std::string text)
{
  std::string return_buffer;
  ActiveBlock active_state;

  size_t start = 0;
  size_t end;

  std::string current_line;
  while (true) {
    current_line="";
    if ((end = text.find("\n", start)) == std::string::npos) {
      if (!(current_line = text.substr(start)).empty()) return_buffer+=current_line+"this shouldn't come";
      return return_buffer;
    }

    current_line = text.substr(start, end - start);
    int line_length = current_line.size()-1;
    bool no_exp = false;




    if(!active_state.CODE_FENCED){
      if ((current_line.rfind("+++", 0) == 0)){
        if (active_state.COLLAPSIBLE) return_buffer+="</details>\n";
        else                           return_buffer+="<details><summary>"+current_line.substr(4, line_length)+"</summary>\n";
        active_state.COLLAPSIBLE= !active_state.COLLAPSIBLE ;
      } 
      else if ((current_line.rfind(":::", 0) == 0)){
        if (active_state.CUSTOM_CLASS) return_buffer+="</div>\n";
        else                            return_buffer+="<div class=\""+current_line.substr(4, line_length)+"\">\n";
        active_state.CUSTOM_CLASS=!active_state.CUSTOM_CLASS;
      }

      else if ((current_line.rfind("<<<", 0) == 0)){
        if (active_state.BLOCKQUOTE_FENCED) return_buffer+="</blockquote>\n";
        else                                 return_buffer+="<blockquote>\n";
        active_state.BLOCKQUOTE_FENCED = !active_state.BLOCKQUOTE_FENCED;
      }

      else if (current_line.rfind(":###### ", 0) == 0) return_buffer+="<h6 align=\"left\">"+current_line.substr(8, line_length)+"</h6>\n";
      else if (current_line.rfind(":##### ",  0) == 0) return_buffer+="<h5 align=\"left\">"+current_line.substr(7, line_length)+"</h5>\n";
      else if (current_line.rfind(":#### ",   0) == 0) return_buffer+="<h4 align=\"left\">"+current_line.substr(6, line_length)+"</h4>\n";
      else if (current_line.rfind(":### ",    0) == 0) return_buffer+="<h3 align=\"left\">"+current_line.substr(5, line_length)+"</h3>\n";
      else if (current_line.rfind(":## ",     0) == 0) return_buffer+="<h2 align=\"left\">"+current_line.substr(4, line_length)+"</h2>\n";
      else if (current_line.rfind(":# ",      0) == 0) return_buffer+="<h1 align=\"left\">"+current_line.substr(3, line_length)+"</h1>\n";

      else if (current_line.rfind("######: ", 0) == 0) return_buffer+="<h6 align=\"right\">"+current_line.substr(8, line_length)+"</h6>\n";
      else if (current_line.rfind("#####: ",  0) == 0) return_buffer+="<h5 align=\"right\">"+current_line.substr(7, line_length)+"</h5>\n";
      else if (current_line.rfind("####: ",   0) == 0) return_buffer+="<h4 align=\"right\">"+current_line.substr(6, line_length)+"</h4>\n";
      else if (current_line.rfind("###: ",    0) == 0) return_buffer+="<h3 align=\"right\">"+current_line.substr(5, line_length)+"</h3>\n";
      else if (current_line.rfind("##: ",     0) == 0) return_buffer+="<h2 align=\"right\">"+current_line.substr(4, line_length)+"</h2>\n";
      else if (current_line.rfind("#: ",      0) == 0) return_buffer+="<h1 align=\"right\">"+current_line.substr(3, line_length)+"</h1>\n";

      else if (current_line.rfind(":######: ", 0) == 0) return_buffer+="<h6 align=\"center\">"+current_line.substr(9, line_length)+"</h6>\n";
      else if (current_line.rfind(":#####: ",  0) == 0) return_buffer+="<h5 align=\"center\">"+current_line.substr(8, line_length)+"</h5>\n";
      else if (current_line.rfind(":####: ",   0) == 0) return_buffer+="<h4 align=\"center\">"+current_line.substr(7, line_length)+"</h4>\n";
      else if (current_line.rfind(":###: ",    0) == 0) return_buffer+="<h3 align=\"center\">"+current_line.substr(6, line_length)+"</h3>\n";
      else if (current_line.rfind(":##: ",     0) == 0) return_buffer+="<h2 align=\"center\">"+current_line.substr(5, line_length)+"</h2>\n";
      else if (current_line.rfind(":#: ",      0) == 0) return_buffer+="<h1 align=\"center\">"+current_line.substr(4, line_length)+"</h1>\n";

      else if (current_line.rfind("###### ", 0) == 0) return_buffer+="<h6>"+current_line.substr(7, line_length)+"</h6>\n";
      else if (current_line.rfind("##### ",  0) == 0) return_buffer+="<h5>"+current_line.substr(6, line_length)+"</h5>\n";
      else if (current_line.rfind("#### ",   0) == 0) return_buffer+="<h4>"+current_line.substr(5, line_length)+"</h4>\n";
      else if (current_line.rfind("### ",    0) == 0) return_buffer+="<h3>"+current_line.substr(4, line_length)+"</h3>\n";
      else if (current_line.rfind("## ",     0) == 0) return_buffer+="<h2>"+current_line.substr(3, line_length)+"</h2>\n";
      else if (current_line.rfind("# ",      0) == 0) return_buffer+="<h1>"+current_line.substr(2, line_length)+"</h1>\n";

      else if (current_line.rfind("> ",      0) == 0) return_buffer+="<blockquote>"+current_line.substr(2, line_length)+"</blockquote>";
      else no_exp=true;
    } else no_exp=true;


/*     if(no_exp) { */
/*  */
/*       if(current_line.find('*') != std::string::npos){ */
/*         for (int i=0;i<line_length;i++) { */
/*           char c = current_line[i]; */
/*  */
/*           if (c == '*'){ */
/*             if(active_state.ITALIC) return_buffer+="</em>"; */
/*             else                     return_buffer+="<em>"; */
/*             active_state.ITALIC=!active_state.ITALIC; */
/*           } */
/*  */
/*         } */
/*       } */
/*     } */

    if ((current_line.rfind("```", 0) == 0)){
      if (active_state.CODE_FENCED) return_buffer+="</code></pre>\n";
      else                            return_buffer+="<pre><code class=\"language-"+current_line.substr(3, line_length)+"\">\n";
      active_state.CODE_FENCED=!active_state.CODE_FENCED;
      no_exp=false;
    }




    if(no_exp){
      if(active_state.CODE_FENCED) return_buffer+=current_line+"\n";
      else if(!current_line.empty())    return_buffer+="\t<p>"+current_line+"</p>\n";
      else                          return_buffer+="\n";
    }
    start = end + 1;
  }
}


  std::string 
ConverterInitiater(const char *kFilename) 
{
  std::string file_c = Readfile(kFilename);
  return RegexConverter(FenceConverter(file_c));
}
