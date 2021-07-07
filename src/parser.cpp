#include <cerrno>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "parser.hpp"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

  std::string 
readfile(const char *filename)
{
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

  std::string 
reg_converter(std::string text) 
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

struct ACTIVE_BLOCK{
  bool COLLAPSIBLE=false;
  bool CUSTOM_CLASS=false;
  bool BLOCKQUOTE_FENCED=false;
  bool CODE_FENCED=false;

  bool BOLD=false;
  bool ITALIC=false;
};

  std::string 
fence_converter(std::string text)
{
  std::string return_buf;
  ACTIVE_BLOCK special_state;

  size_t start = 0;
  size_t end;
  while (true) {
    std::string cur_line;
    if ((end = text.find("\n", start)) == std::string::npos) {
      if (!(cur_line = text.substr(start)).empty()) return_buf+=cur_line+"this shouldn't come";
      return return_buf;
    }

    cur_line = text.substr(start, end - start);
    int line_siz = cur_line.size()-1;
    bool no_exp = false;




    if(!special_state.CODE_FENCED){
      if ((cur_line.rfind("+++", 0) == 0)){
        if (special_state.COLLAPSIBLE) return_buf+="</details>\n";
        else                           return_buf+="<details><summary>"+cur_line.substr(4, line_siz)+"</summary>\n";
        special_state.COLLAPSIBLE= !special_state.COLLAPSIBLE ;
      } 
      else if ((cur_line.rfind(":::", 0) == 0)){
        if (special_state.CUSTOM_CLASS) return_buf+="</div>\n";
        else                            return_buf+="<div class=\""+cur_line.substr(4, line_siz)+"\">\n";
        special_state.CUSTOM_CLASS=!special_state.CUSTOM_CLASS;
      }

      else if ((cur_line.rfind("<<<", 0) == 0)){
        if (special_state.BLOCKQUOTE_FENCED) return_buf+="</blockquote>\n";
        else                                 return_buf+="<blockquote>\n";
        special_state.BLOCKQUOTE_FENCED = !special_state.BLOCKQUOTE_FENCED;
      }

      else if (cur_line.rfind(":###### ", 0) == 0) return_buf+="<h6 align=\"left\">"+cur_line.substr(8, line_siz)+"</h6>\n";
      else if (cur_line.rfind(":##### ",  0) == 0) return_buf+="<h5 align=\"left\">"+cur_line.substr(7, line_siz)+"</h5>\n";
      else if (cur_line.rfind(":#### ",   0) == 0) return_buf+="<h4 align=\"left\">"+cur_line.substr(6, line_siz)+"</h4>\n";
      else if (cur_line.rfind(":### ",    0) == 0) return_buf+="<h3 align=\"left\">"+cur_line.substr(5, line_siz)+"</h3>\n";
      else if (cur_line.rfind(":## ",     0) == 0) return_buf+="<h2 align=\"left\">"+cur_line.substr(4, line_siz)+"</h2>\n";
      else if (cur_line.rfind(":# ",      0) == 0) return_buf+="<h1 align=\"left\">"+cur_line.substr(3, line_siz)+"</h1>\n";

      else if (cur_line.rfind("######: ", 0) == 0) return_buf+="<h6 align=\"right\">"+cur_line.substr(8, line_siz)+"</h6>\n";
      else if (cur_line.rfind("#####: ",  0) == 0) return_buf+="<h5 align=\"right\">"+cur_line.substr(7, line_siz)+"</h5>\n";
      else if (cur_line.rfind("####: ",   0) == 0) return_buf+="<h4 align=\"right\">"+cur_line.substr(6, line_siz)+"</h4>\n";
      else if (cur_line.rfind("###: ",    0) == 0) return_buf+="<h3 align=\"right\">"+cur_line.substr(5, line_siz)+"</h3>\n";
      else if (cur_line.rfind("##: ",     0) == 0) return_buf+="<h2 align=\"right\">"+cur_line.substr(4, line_siz)+"</h2>\n";
      else if (cur_line.rfind("#: ",      0) == 0) return_buf+="<h1 align=\"right\">"+cur_line.substr(3, line_siz)+"</h1>\n";

      else if (cur_line.rfind(":######: ", 0) == 0) return_buf+="<h6 align=\"center\">"+cur_line.substr(9, line_siz)+"</h6>\n";
      else if (cur_line.rfind(":#####: ",  0) == 0) return_buf+="<h5 align=\"center\">"+cur_line.substr(8, line_siz)+"</h5>\n";
      else if (cur_line.rfind(":####: ",   0) == 0) return_buf+="<h4 align=\"center\">"+cur_line.substr(7, line_siz)+"</h4>\n";
      else if (cur_line.rfind(":###: ",    0) == 0) return_buf+="<h3 align=\"center\">"+cur_line.substr(6, line_siz)+"</h3>\n";
      else if (cur_line.rfind(":##: ",     0) == 0) return_buf+="<h2 align=\"center\">"+cur_line.substr(5, line_siz)+"</h2>\n";
      else if (cur_line.rfind(":#: ",      0) == 0) return_buf+="<h1 align=\"center\">"+cur_line.substr(4, line_siz)+"</h1>\n";

      else if (cur_line.rfind("###### ", 0) == 0) return_buf+="<h6>"+cur_line.substr(7, line_siz)+"</h6>\n";
      else if (cur_line.rfind("##### ",  0) == 0) return_buf+="<h5>"+cur_line.substr(6, line_siz)+"</h5>\n";
      else if (cur_line.rfind("#### ",   0) == 0) return_buf+="<h4>"+cur_line.substr(5, line_siz)+"</h4>\n";
      else if (cur_line.rfind("### ",    0) == 0) return_buf+="<h3>"+cur_line.substr(4, line_siz)+"</h3>\n";
      else if (cur_line.rfind("## ",     0) == 0) return_buf+="<h2>"+cur_line.substr(3, line_siz)+"</h2>\n";
      else if (cur_line.rfind("# ",      0) == 0) return_buf+="<h1>"+cur_line.substr(2, line_siz)+"</h1>\n";

      else if (cur_line.rfind("> ",      0) == 0) return_buf+="<blockquote>"+cur_line.substr(2, line_siz)+"</blockquote>";
      else no_exp=true;
    } else no_exp=true;

    if ((cur_line.rfind("```", 0) == 0)){
      if (special_state.CODE_FENCED) return_buf+="</code></pre>\n";
      else                            return_buf+="<pre><code class=\"language-"+cur_line.substr(3, line_siz)+"\">\n";
      special_state.CODE_FENCED=!special_state.CODE_FENCED;
      no_exp=false;
    }



    /* if(no_exp) { */
    /*   for (int i=0;i<line_siz;i++) { */
    /*     char c = cur_line[i]; */
    /*   } */
    /* } */

    if(no_exp){
      if(special_state.CODE_FENCED) return_buf+=cur_line+"\n";
      else if(!cur_line.empty())    return_buf+="\t<p>"+cur_line+"</p>\n";
      else                          return_buf+="\n";
    }
    start = end + 1;
  }
}

  std::string 
main_parse(const char *filename) 
{
  std::string file_c = readfile(filename);
  return reg_converter(fence_converter(file_c));
}
