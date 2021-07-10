#include <cerrno>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include "parser.hpp"



#define ISIN(ch, ch_min, ch_max)       ((ch_min) <= (unsigned)(ch) && (unsigned)(ch) <= (ch_max))
#define ISANYOF(ch, palette)           ((ch) != _T('\0')  &&  md_strchr((palette), (ch)) != NULL)
#define ISANYOF2(ch, ch1, ch2)         ((ch) == (ch1) || (ch) == (ch2))
#define ISANYOF3(ch, ch1, ch2, ch3)    ((ch) == (ch1) || (ch) == (ch2) || (ch) == (ch3))
#define ISASCII(ch)                    ((unsigned)(ch) <= 127)
#define ISBLANK(ch)                    (ISANYOF2((ch), _T(' '), _T('\t')))
#define ISNEWLINE(ch)                  (ISANYOF2((ch), _T('\r'), _T('\n')))
#define ISWHITESPACE(ch)               (ISBLANK(ch) || ISANYOF2((ch), _T('\v'), _T('\f')))
#define ISCNTRL(ch)                    ((unsigned)(ch) <= 31 || (unsigned)(ch) == 127)
#define ISPUNCT(ch)                    (ISIN(ch, 33, 47) || ISIN(ch, 58, 64) || ISIN(ch, 91, 96) || ISIN(ch, 123, 126))
#define ISUPPER(ch)                    (ISIN(ch, _T('A'), _T('Z')))
#define ISLOWER(ch)                    (ISIN(ch, _T('a'), _T('z')))
#define ISALPHA(ch)                    (ISUPPER_(ch) || ISLOWER_(ch))
#define ISDIGIT(ch)                    (ISIN_(ch, _T('0'), _T('9')))
#define ISXDIGIT(ch)                   (ISDIGIT(ch) || ISIN(ch, _T('A'), _T('F')) || ISIN(ch, _T('a'), _T('f')))
#define ISALNUM(ch)                    (ISALPHA(ch) || ISDIGIT(ch))

#define BEGIN1(str, ch)               (str[0]==ch )
#define BEGIN2(str, ch)               (str[0]==ch &&  str[1]==ch )
#define BEGIN3(str, ch)               (str[0]==ch &&  str[1]==ch && str[2]==ch )

#define STARTS(str, substr)            (str.rfind(substr, 0)==0)

#define ISINLINE inline

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

ISINLINE std::string Readfile(const char *kFilename)
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

ISINLINE std::string RegexConverter(std::string text) 
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

struct ActiveState{
  bool COLLAPSIBLE=false;
  bool CUSTOM_CLASS=false;
  bool BLOCKQUOTE_FENCED=false;
  bool CODE_FENCED=false;

  bool BOLD=false;
  bool ITALIC=false;
};

// getHeading check for how many `#` there are in the line and returns
// `#` + amount of heading levels, with a maximum of 6 (`#` + `##` + `###` + etc)
ISINLINE int getHeading(const std::string &line)
{
  int heading = 0;
  for (auto character : line) {
    if (heading == 7 && character == '#') {
      // FIXME: Error about too many levels.
      return -1;
    }
    if (character == '#') {
      heading++;
    } else {
      break;
    }
  }
  return heading;
}

ISINLINE std::string FenceConverter(const std::string *kText)
{
  /* The string which will be used to add content to, to return */
  std::string rb;
  ActiveState active_state;

  size_t start = 0;
  size_t end;

  std::string line;
  while (true) {
    //line="";
    if ((end = kText->find("\n", start)) == std::string::npos) {
      if (!(line = kText->substr(start)).empty()) rb+=line+"this shouldn't come";
      return rb;
    }

    line = kText->substr(start, end - start);
    int line_length = line.size()-1;
    bool no_exp = false;




    if(!active_state.CODE_FENCED){
      if (BEGIN3(line, '+')){
        if (active_state.COLLAPSIBLE) rb+="</details>\n";
        else                           rb+="<details><summary>"+line.substr(4, line_length)+"</summary>\n";
        active_state.COLLAPSIBLE= !active_state.COLLAPSIBLE ;
      } 
      else if (BEGIN3(line, ':')){
        if (active_state.CUSTOM_CLASS) rb+="</div>\n";
        else                            rb+="<div class=\""+line.substr(4, line_length)+"\">\n";
        active_state.CUSTOM_CLASS=!active_state.CUSTOM_CLASS;
      }

      else if (BEGIN3(line, '<')){
        if (active_state.BLOCKQUOTE_FENCED) rb+="</blockquote>\n";
        else                                 rb+="<blockquote>\n";
        active_state.BLOCKQUOTE_FENCED = !active_state.BLOCKQUOTE_FENCED;
      }

      else if (line[0] == ':' || line[0] == '#'){
        bool isLeft = (line[0] == ':');
        // .substr(1) to remove the `:` from the beginning.
        std::string modifiedLine = isLeft ? line.substr(1, line_length) : line;

        // FIXME: Check for heading == -1 and error.
        int heading = getHeading(modifiedLine);
        bool isCenterOrRight = modifiedLine[heading] == ':';

        // 2x increase headingSpace to take in account for the `:`.
        size_t headingSpace = isCenterOrRight ? heading+2 : heading+1;
        std::string allignment = "";

        // Get correct alignment block.
        if (isCenterOrRight) {
          if (isLeft) {
            allignment = " align=\"center\"";
          } else {
            allignment = " align=\"right\"";
          }
        } else if (isLeft) {
          allignment = " align=\"left\"";
        }

        rb += "<h" + std::to_string(heading) + allignment + ">" +modifiedLine.substr(headingSpace, line_length)+"</h" + std::to_string(heading) + ">\n";
      }

      else if ( BEGIN1(line, '>') ) rb+="<blockquote>"+line.substr(2, line_length)+"</blockquote>\n";
      else if ( BEGIN2(line, '/') ) rb+="<!--"+line.substr(2, line_length)+"-->";
      else no_exp=true;
    } else no_exp=true;


    /*     if(no_exp) { */
    /*  */
    /*       if(line.find('*') != std::string::npos){ */
    /*         for (int i=0;i<line_length;i++) { */
    /*           char c = line[i]; */
    /*  */
    /*           if (c == '*'){ */
    /*             if(active_state.ITALIC) rb+="</em>"; */
    /*             else                     rb+="<em>"; */
    /*             active_state.ITALIC=!active_state.ITALIC; */
    /*           } */
    /*  */
    /*         } */
    /*       } */
    /*     } */

    if ( BEGIN3(line, '`') ){
      if (active_state.CODE_FENCED) rb+="</code></pre>\n";
      else                            rb+="<pre><code class=\"language-"+line.substr(3, line_length)+"\">\n";
      active_state.CODE_FENCED=!active_state.CODE_FENCED;
      no_exp=false;
    }




    if(no_exp){
      if(active_state.CODE_FENCED) rb+=line+"\n";
      else if(!line.empty())    rb+="<p>"+line+"</p>\n";
      else                          rb+="\n";
    }
    start = end + 1;
  }
}


std::string ConverterInitiater(const char *kFilename) 
{
  std::string file_c = Readfile(kFilename);
  return (FenceConverter(&file_c));
}
