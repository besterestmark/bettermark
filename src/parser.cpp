#include <cerrno>
#include <fstream>
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


//uncomment this for using inline functions
#define ISINLINE inline


// macros for simplicity of types
using u8 =  uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 =  int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

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

//WARNING: Slow probably will be deprecated
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

ISINLINE std::string FenceConverter(const std::string *kText)
{
  
  std::string rb; // the string to which content is added to return

  ActiveState active_state; // stores all the currently active fencestates

  size_t start = 0;
  size_t end;

  std::string line;
  while (true) {
    if ((end = kText->find("\n", start)) == std::string::npos) {
      if (!(line = kText->substr(start)).empty()) rb+=line+"this shouldn't come";
      return rb;
    }

    line = kText->substr(start, end - start); // go to next line
    // Store the length of the line as int
    int llen = line.size()-1;

    // If the line is empty, skip it
    if (llen <= 0) {
      start = end + 1;
      continue;
    }
    bool no_exp = false;                      // stores if there are any @ActiveState active


    // don't check for other states if code blocks is active
    if(!active_state.CODE_FENCED){
      /* 
       *+++ summary
       * collapsible content
       *+++
       */
      if (BEGIN3(line, '+')){
        if (active_state.COLLAPSIBLE) rb+="</details>\n";
        else                          rb+="<details><summary>"+line.substr(4, llen)+"</summary>\n";
        active_state.COLLAPSIBLE= !active_state.COLLAPSIBLE ;
      } 
      /*
       *::: classname
       * content in div
       *:::
       */
      else if (BEGIN3(line, ':')){
        if (active_state.CUSTOM_CLASS) rb+="</div>\n";
        else                           rb+="<div class=\""+line.substr(4, llen)+"\">\n";
        active_state.CUSTOM_CLASS=!active_state.CUSTOM_CLASS;
      }


      /*
       *>>>
       * long quote
       * many lines
       *>>>
       */

      else if (BEGIN3(line, '<')){
        if (active_state.BLOCKQUOTE_FENCED) rb+="</blockquote>\n";
        else                                rb+="<blockquote>\n";
        active_state.BLOCKQUOTE_FENCED = !active_state.BLOCKQUOTE_FENCED;
      }


                                                                                                      // Following comments represent what the state of                                                                                 
                                                                                                      // @line might be based on the condition 
                                                                                                      //
      else if (line[0] == ':'){                                                                       //:
        if(line[1]=='#'){                                                                             //:#
          if(line[2]=='#'){                                                                           //:##
            if(line[3]=='#'){                                                                         //:###
              if(line[4]=='#'){                                                                       //:####
                if(line[5]=='#'){                                                                     //:#####
                  if(line[6]=='#'){                                                                   //:######
                    if(line[7]==':') rb+="<h6 align=\"center\">"+line.substr(9, llen)+"</h6>\n";      //:######:
                    else             rb+="<h6 align=\"left\">"+line.substr(8, llen)+"</h6>\n";        //:######
                  }else{                                                                              //
                    if(line[6]==':') rb+="<h5 align=\"center\">"+line.substr(8, llen)+"</h5>\n";      //:#####:
                    else             rb+="<h5 align=\"left\">"+line.substr(7, llen)+"</h5>\n";        //:#####
                  }                                                                                   //
                }else {                                                                               //
                  if(line[5]==':') rb+="<h4 align=\"center\">"+line.substr(7, llen)+"</h4>\n";        //:####:
                  else             rb+="<h4 align=\"left\">"+line.substr(6, llen)+"</h4>\n";          //:####
                }                                                                                     //                         
              }else {                                                                                 //
                if(line[4]==':') rb+="<h3 align=\"center\">"+line.substr(6, llen)+"</h3>\n";          //:###:
                else             rb+="<h3 align=\"left\">"+line.substr(5, llen)+"</h3>\n";            //:###
              }                                                                                       //
            }else {                                                                                   //
              if(line[3]==':') rb+="<h2 align=\"center\">"+line.substr(5, llen)+"</h2>\n";            //:##;
              else             rb+="<h2 align=\"left\">"+line.substr(4, llen)+"</h2>\n";              //:##
            }                                                                                         //
          }else {                                                                                     //
            if(line[2]==':') rb+="<h1 align=\"left\">"+line.substr(4, llen)+"</h1>\n";                //:#:
            else             rb+="<h1 align=\"left\">"+line.substr(3, llen)+"</h1>\n";                //:#
          }                                                                                           //
        }                                                                                             //
      }                                                                                               //
                                                                                                      //
      else if(line[0]=='#'){                                                                          //# 
        if(line[1]=='#'){                                                                             //##
          if(line[2]=='#'){                                                                           //###
            if(line[3]=='#'){                                                                         //####
              if(line[4]=='#'){                                                                       //#####
                if(line[5]=='#'){                                                                     //######
                  if(line[6]==':')  rb+="<h6 align=\"right\">"+line.substr(8, llen)+"</h6>\n";        //######:
                  else              rb+="<h6>"+line.substr(7, llen)+"</h6>\n";                        //######
                }else{                                                                                //
                  if(line[5]==':')  rb+="<h5 align=\"right\">"+line.substr(7, llen)+"</h5>\n";        //#####:
                  else              rb+="<h5>"+line.substr(6, llen)+"</h5>\n";                        //#####
                }                                                                                     //
              } else{                                                                                 //
                if(line[4]==':')  rb+="<h4 align=\"right\">"+line.substr(6, llen)+"</h4>\n";          //####:
                else              rb+="<h4>"+line.substr(5, llen)+"</h5>\n";                          //####
              }                                                                                       //
            } else{                                                                                   //
              if(line[3]==':')  rb+="<h3 align=\"right\">"+line.substr(5, llen)+"</h3>\n";            //###:
              else              rb+="<h3>"+line.substr(4, llen)+"</h5>\n";                            //### 
            }                                                                                         //
          } else{                                                                                     //
              if(line[2]==':')  rb+="<h2 align=\"right\">"+line.substr(4, llen)+"</h2>\n";            //##:
              else              rb+="<h2 >"+line.substr(3, llen)+"</h2>\n";                           //##
          }                                                                                           //
        } else{                                                                                       //
              if(line[1]==':')  rb+="<h1 align=\"right\">"+line.substr(3, llen)+"</h1>\n";            //#:
              else              rb+="<h1>"+line.substr(2, llen)+"</h1>\n";                            //# 
        }                                                                                             //
      }                                                                                               //

      else if ( BEGIN1(line, '>') ) rb+="<blockquote>"+line.substr(2, llen)+"</blockquote>\n";        //> normal quote
      else if ( BEGIN2(line, '/') ) rb+="<!--"+line.substr(2, llen)+"-->";                            //ignored comments
      else no_exp=true;
    } else no_exp=true;


/*     if(no_exp) { */
/*  */
/*       int index; */
/*       if((index = line.find('*')) != std::string::npos){ */
/*         for (int i=0;i<llen;i++) { */
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




    /*
     * code blocks
     *```python
     *for i in range(1):
     *    print(i)
     *```
     */

    if ( BEGIN3(line, '`') ){
      if (active_state.CODE_FENCED) rb+="</code></pre>\n";
      else{
        std::string type = line.substr(3, llen);
        if(line.empty()) rb+="<pre><code class=\"language-plaintext\">\n"; 
        else rb+="<pre><code class=\"language-"+line.substr(3, llen)+"\">\n";
      }
      active_state.CODE_FENCED=!active_state.CODE_FENCED;
      no_exp=false;
    }




    if(no_exp){
      if(active_state.CODE_FENCED) rb+=line+"\n";           // if code blocks is found, just add the line without any checks
      else if(!line.empty())       rb+="<p>"+line+"</p>\n"; // if line isn't empty, use html paragraphs
      else                         rb+="\n";                // if empty, then add newline
    }
    start = end + 1;
  }
}


std::string ConverterInitiater(const char *kFilename) 
{
  std::string file_c = Readfile(kFilename); 
  return (FenceConverter(&file_c));
}
