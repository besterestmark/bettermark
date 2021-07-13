#include <regex>
#include <algorithm> //for std::min to find smallest index of starting char, will just manually do in future
#include <string>
#include "parser.hpp"
#include "simio.hpp"

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

#define BEGIN1(str, ch)                ( str[0]==ch )
#define BEGIN2(str, ch)                ( str[0]==ch &&  str[1]==ch )
#define BEGIN3(str, ch)                ( str[0]==ch &&  str[1]==ch && str[2]==ch )

#define STARTS(str, substr)            (str.rfind(substr, 0)==0)



// macros for simplicity of types
using u8 =  uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using i8 =  int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;


//WARNING: Slow probably will be deprecated
std::string RegexConverter(std::string text) 
{
  std::regex IMAGE_SIZE(R"(!\[(.+)\]\((.+) (.+) =(.+)x(.+)\))");
  std::regex ABBREVIATIONS(R"(\*\[(.+)\]:\s(.+))");
  std::regex SPOILER(R"(!!(.+)!!)");
  text = regex_replace(text, SPOILER, "<span class=\"spoiler\">$1</span>");
  text = regex_replace(text, ABBREVIATIONS, "<abbr title=\"$1\">$2</abbr>");
  text = regex_replace(
      text, IMAGE_SIZE,
      "<img src=\"$2\" title=$3 alt=\"$1\" width=\"$4\" height=\"$5\">");
  return text;
}

struct ActiveState{
  bool COLLAPSIBLE=false;
  bool CUSTOM_CLASS=false;
  bool BLOCKQUOTE_FENCED=false;
  bool CODE_FENCED=false;

  bool BOLD=false;
  bool ITALIC=false;
  bool UNDERLINE=false;
  bool  STRIKETHROUGH=false;

  bool SUBSCRIPT=false;
  bool SUPERSCRIPT=false;

  bool CODE_INLINE=false;
};

bool FirstIndexOf(size_t i1, size_t i2){
  return i1 < i2;
}


std::string FenceConverter(const std::string *kText)
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

    const size_t llen = line.size()-1;               // indexable length of string
    // If the line is empty, skip it
    /* if ( kLen==0 ) { */
    if(llen==std::string::npos){ // comparing with npos because its has value of unsigned type - 1, I am clever, right?
      rb += "\n";
      start = end + 1;
      continue;
    }

    bool no_exp = false;                     // stores if there special state happened in current line


    // don't check for other states if code blocks is active
    if(!active_state.CODE_FENCED){
      /* 
       *+++ summary
       * collapsible content
       *+++
       */
      if (BEGIN3(line, '+')){
        if (active_state.COLLAPSIBLE) rb+="</details>\n";
        else {
          // FIXME: add error handling.
          // Because this mean `+++` is not followed by summary.
          if (llen > 3) {
            rb+="<details><summary>"+line.substr(4, llen)+"</summary>\n";
            active_state.COLLAPSIBLE= !active_state.COLLAPSIBLE ;
          }
        }
      } 
      /*
       *::: classname
       * content in div
       *:::
       */
      else if (BEGIN3(line, ':')){
        if (active_state.CUSTOM_CLASS) rb+="</div>\n";
        else {
          // FIXME: add error handling.
          // Because this mean `:::` is not followed by a valid classname.
          if (llen > 3) {
            rb+="<div class=\""+line.substr(4, llen)+"\">\n";
            active_state.CUSTOM_CLASS=!active_state.CUSTOM_CLASS;
          }
        }
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
                    if(line[7]==':') {                                                                //
                      if (llen > 8)  rb+="<h6 align=\"center\">"+line.substr(9, llen)+"</h6>\n";      //:######:
                    }                                                                                 //
                    else {                                                                            //
                      if (llen > 7)  rb+="<h6 align=\"left\">"+line.substr(8, llen)+"</h6>\n";        //:######
                    }                                                                                 //
                  }else{                                                                              //
                    if(line[6]==':') {                                                                //
                      if (llen > 7)  rb+="<h5 align=\"center\">"+line.substr(8, llen)+"</h5>\n";      //:#####:
                    }                                                                                 //
                    else {                                                                            //
                      if (llen > 6)  rb+="<h5 align=\"left\">"+line.substr(7, llen)+"</h5>\n";        //:#####
                    }                                                                                 //
                  }                                                                                   //
                }else {                                                                               //
                  if(line[5]==':') {                                                                  //
                    if (llen > 6)    rb+="<h4 align=\"center\">"+line.substr(7, llen)+"</h4>\n";      //:####:
                  }                                                                                   // 
                  else {                                                                              // 
                    if (llen > 5)    rb+="<h4 align=\"left\">"+line.substr(6, llen)+"</h4>\n";        //:####
                  }                                                                                   // 
                }                                                                                     //                         
              }else {                                                                                 //
                if(line[4]==':') {                                                                    //
                  if (llen > 5)      rb+="<h3 align=\"center\">"+line.substr(6, llen)+"</h3>\n";      //:###:
                }                                                                                     // 
                else {                                                                                // 
                  if (llen > 4)      rb+="<h3 align=\"left\">"+line.substr(5, llen)+"</h3>\n";        //:###
                }                                                                                     // 
              }                                                                                       //
            }else {                                                                                   //
              if(line[3]==':') {                                                                      //
                if (llen > 4)        rb+="<h2 align=\"center\">"+line.substr(5, llen)+"</h2>\n";      //:##;
              }                                                                                       // 
              else {                                                                                  // 
                if (llen > 3)        rb+="<h2 align=\"left\">"+line.substr(4, llen)+"</h2>\n";        //:##
              }                                                                                       // 
            }                                                                                         //
          }else {                                                                                     //
            if(line[2]==':') {                                                                        // 
              if (llen > 3)          rb+="<h1 align=\"center\">"+line.substr(4, llen)+"</h1>\n";      //:#:
            }                                                                                         // 
            else {                                                                                    //
              if (llen > 2)           rb+="<h1 align=\"left\">"+line.substr(3, llen)+"</h1>\n";       //:#
            }                                                                                         //
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
                  if(line[6]==':')  {                                                                 //
                    if (llen > 7) rb+="<h6 align=\"right\">"+line.substr(8, llen)+"</h6>\n";          //######:
                  }                                                                                   //
                  else {                                                                              //
                    if (llen > 6) rb+="<h6>"+line.substr(7, llen)+"</h6>\n";                          //######
                  }                                                                                   //
                }else{                                                                                //
                  if(line[5]==':')  {                                                                 //
                    if (llen > 6) rb+="<h5 align=\"right\">"+line.substr(7, llen)+"</h5>\n";          //#####:
                  }                                                                                   //
                  else {                                                                              //
                    if (llen > 5) rb+="<h5>"+line.substr(6, llen)+"</h5>\n";                          //#####
                  }                                                                                   //
                }                                                                                     //
              } else{                                                                                 //
                if(line[4]==':')  {                                                                   //
                  if (llen > 5) rb+="<h4 align=\"right\">"+line.substr(6, llen)+"</h4>\n";            //####:
                }                                                                                     //
                else {                                                                                //
                  if (llen > 4) rb+="<h4>"+line.substr(5, llen)+"</h4>\n";                            //####
                }                                                                                     //
              }                                                                                       //
            } else{                                                                                   //
              if(line[3]==':')  {                                                                     //
                if (llen > 4) rb+="<h3 align=\"right\">"+line.substr(5, llen)+"</h3>\n";             //###:
              }                                                                                       //
              else {                                                                                  //    
                if (llen > 3) rb+="<h3>"+line.substr(4, llen)+"</h3>\n";                              //### 
              }                                                                                       //  
            }                                                                                         //
          } else{                                                                                     //
            if(line[2]==':')  {                                                                       //
              if (llen > 3) rb+="<h2 align=\"right\">"+line.substr(4, llen)+"</h2>\n";              //##:
            }                                                                                       //
            else {                                                                                    //
              if (llen > 2) rb+="<h2 >"+line.substr(3, llen)+"</h2>\n";                               //##
            }                                                                                         //
          }                                                                                           //
        } else{                                                                                       //
          if(line[1]==':') {                                                                          //
            if (llen > 2) rb+="<h1 align=\"right\">"+line.substr(3, llen)+"</h1>\n";                  //#:
          }                                                                                           //
          else {                                                                                      //
            if (llen > 1) rb+="<h1>"+line.substr(2, llen)+"</h1>\n";                                  //#
          }                                                                                           //
        }                                                                                             //
      }                                                                                               //

      else if ( BEGIN1(line, '>') ) {
        // FIXME: add error handling.
        // Because this mean `>` is not followed by content.
        if (llen > 2)               rb+="<blockquote>"+line.substr(2, llen)+"</blockquote>\n";        //> normal quote
      }
      else if ( BEGIN2(line, '/') ) {
        // FIXME: add error handling.
        // Because this mean `//` is not followed by content.
        if (llen > 2)               rb+="<!--"+line.substr(2, llen)+"-->";                            //ignored comments
      }
      else no_exp=true;
    } else no_exp=true;


    if(no_exp && !(active_state.CODE_FENCED)) {
      size_t index = std::min({ line.find('*'),
          line.find('_'),
          line.find('`'),
          line.find('^'),
          line.find('~'),
          line.find('*')},
          FirstIndexOf) ;

      if (  index!=std::string::npos ) {
        no_exp=false;

        if(index!=0) rb+="<p>"+line.substr(0, index);

        for (size_t i=index;i<=llen;i++) {
          char c = line[i];

          if (c == '*'){
            if( (i==llen)?false:line[i+1]=='*' ){
              if(active_state.BOLD) rb+="</strong>";
              else                  rb+="<strong>";
              active_state.BOLD=!active_state.BOLD;
            }
            else if( (i==0)?false:line[i-1]!='*' ){
              if(active_state.ITALIC) rb+="</em>";
              else                    rb+="<em>";
              active_state.ITALIC=!active_state.ITALIC;
            }
          }
          else if (c == '~'){
            if( (i==llen)?false:line[i+1]=='~' ){
              if(active_state.STRIKETHROUGH) rb+="</s>";
              else                  rb+="<s>";
              active_state.STRIKETHROUGH=!active_state.STRIKETHROUGH;
            }
            else if( (i==0)?false:line[i-1]!='~' ){
              if(active_state.SUBSCRIPT) rb+="</sub>";
              else                    rb+="<sub>";
              active_state.SUBSCRIPT=!active_state.SUBSCRIPT;
            }
          }
          else if (c == '^'){
            if(active_state.SUPERSCRIPT) rb+="</sup>";
            else                       rb+="<sup>";
            active_state.SUPERSCRIPT=!active_state.SUPERSCRIPT;
          }
          else if (c == '`'){
            if(active_state.CODE_INLINE) rb+="</code>";
            else                       rb+="<code>";
            active_state.CODE_INLINE=!active_state.CODE_INLINE;
          }
          else if (c == '_'){
            if(active_state.UNDERLINE) rb+="</u>";
            else                       rb+="<u>";
            active_state.UNDERLINE=!active_state.UNDERLINE;
          }
          else rb+=c;
        }rb+="<p>\n";
      }
    }




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
        if(type.empty()) rb+="<pre><code class=\"language-plaintext\">\n"; 
        else rb+="<pre><code class=\"language-"+line.substr(3, llen)+"\">\n";
      }
      active_state.CODE_FENCED=!active_state.CODE_FENCED;
      no_exp=false;
    }




    if(no_exp){
      if(active_state.CODE_FENCED) rb+=line+"\n";           // if code blocks is found, just add the line without any checks
      else                         rb+="<p>"+line+"</p>\n"; // if line isn't empty, use html paragraphs
    }
    start = end + 1;
  }
}

