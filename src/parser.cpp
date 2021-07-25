#include <cstdio>
#include <string>
#include "parser.hpp"
#include "simio.hpp"

// Macros

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

// FIXME: Explain what this is :c

void LineConverter(std::string *buf, std::string line, size_t llen, ActiveState *as, uint8_t startIndex, bool *no_exp)
{
  size_t index = line.find_first_of("*_`^~!");
  if (index != std::string::npos) {
    *no_exp = false;
    if (index > startIndex) buf->append(line.substr(startIndex, index));
    else index = startIndex;

    for (size_t i = index; i <= llen; i++) {
      char c = line[i];

      if (c == '*'){
        if ((i == llen)?false:line[i+1] == '*' ) {
          if (as->BOLD) buf -> append("</strong>");
          else            buf->append("<strong>");
          as->BOLD =! as -> BOLD;
        }
        else if ((i == 0)?false:line[i-1] != '*') {
          if (as->ITALIC) buf -> append("</em>");
          else              buf->append("<em>");
          as->ITALIC =! as -> ITALIC; 
        }
      }
      else if (c == '~') {
        if ((i == llen)?false:line[i+1] == '~' ) {
          if (as->STRIKETHROUGH) buf -> append("</s>");
          else                     buf->append("<s>");
          as->STRIKETHROUGH =! as -> STRIKETHROUGH;
        }
        else if ((i==0)?false:line[i-1]!='~' ) {
          if (as->SUBSCRIPT) buf -> append("</sub>");
          else                 buf->append("<sub>");
          as->SUBSCRIPT =! as -> SUBSCRIPT;
        }
      }
      else if (c == '!' && line[i+1]=='!') {
        if (as->SPOILER) buf -> append("</sub>");
        else               buf->append("<span class=\"spoiler\">");
        as->SPOILER =! as -> SPOILER;
        i++;
      }
      else if (c == '^') {
        if (as->SUPERSCRIPT) buf -> append("</sup>");
        else                   buf->append("<sup>");
        as->SUPERSCRIPT =! as -> SUPERSCRIPT;
      }
      else if (c == '`') {
        if(as->CODE_INLINE) buf->append("</code>");
        else                  buf->append("<code>");
        as->CODE_INLINE =! as -> CODE_INLINE;
      }
      else if (c == '_') {
        if(as->UNDERLINE) buf->append("</u>");
        else                buf->append("<u>");
        as->UNDERLINE =! as -> UNDERLINE;
      }
      else buf->push_back(c);
    }
  }
  else buf->append(line.substr(startIndex, llen));
}

// FIXME: Explain what this thing is

std::string FenceConverter(const std::string *kText)
{
  std::string rb; 					// The string to which content is added to return
  ActiveState active_state; // Stores all the currently active fencestates

  size_t start = 0;
  size_t end;

  std::string line;
  while (true) {
    if ((end = kText->find("\n", start)) == std::string::npos) { 
      if (!(line = kText->substr(start)).empty()) rb += line;
      return rb;
    }

    line = kText->substr(start, end - start); // Go to the next line
    const size_t llen = line.size()-1;        // Indexable length of string

    // If the line is empty, skip it              
    if (llen==std::string::npos) {
      rb += "\n";
      start = end + 1;
      continue;
    }

    bool no_exp = false;                      // Stores if there special state that happened in current line

    if (active_state.UNORDERED_LIST) {
      if (!((BEGIN1(line, '-') || BEGIN1(line, '+')  || BEGIN1(line, '*')) && line[1]==' ')) {
        rb += "</ul>\n";
        active_state.UNORDERED_LIST = false;
      }
    }

    // Don't check for other states if code blocks is active
    if (!active_state.CODE_FENCED) {
      
      /* 
      *+++ summary
      * collapsible content
      *+++
      */
      
      if (BEGIN3(line, '+')) {
        if (active_state.COLLAPSIBLE) rb += "</details>\n";
        else {
          // FIXME: add error handling.
          // Because this means that `+++` is not followed by summary.
          if (llen > 3) {
            rb += "<details><summary>"+line.substr(4, llen)+"</summary>\n";
            active_state.COLLAPSIBLE = !active_state.COLLAPSIBLE ;
          }
        }
      } 
      
      /*
      *::: classname
      * content in div
      *:::
      */
      
      else if (BEGIN3(line, ':')) {
        if (active_state.CUSTOM_CLASS) rb += "</div>\n";
        else {
          // FIXME: add error handling.
          // Because this mean `:::` is not followed by a valid classname.
          if (llen > 3) {
            rb += "<div class=\"" + line.substr(4, llen)+"\">\n";
            active_state.CUSTOM_CLASS =! active_state.CUSTOM_CLASS;
          }
        }
      }

      /*
       *>>>
       * long quote
       * many lines
       *>>>
       */

      else if (BEGIN3(line, '<')) {
        if (active_state.BLOCKQUOTE_FENCED) rb += "</blockquote>\n";
        else                                rb += "<blockquote>\n";
        active_state.BLOCKQUOTE_FENCED = !active_state.BLOCKQUOTE_FENCED;
      }

      else if (BEGIN1(line, '*') && line[1]=='[' ) {
        size_t endB;
        if ((endB = line.find(']')) != std::string::npos) {
          // Check if the line has a heading
          // FIXME: add error handling!!!
          if (llen > endB+1) rb += "<abbr title=\"" + line.substr(endB+2, llen)+"\">" + line.substr(2, endB-2) + "</abbr>\n";
        }
        else no_exp = true;
      }
      else if (((BEGIN1(line, '-') || BEGIN1(line, '+')) || BEGIN1(line, '*')) && line[1]==' ') {
        if (!active_state.UNORDERED_LIST)               rb += "<ul>\n";
        rb += "<li>";
        LineConverter(&rb, line, llen, &active_state, 2, &no_exp);
        
        rb += "</li>\n";
        active_state.UNORDERED_LIST = true;
      }

      // Following comments represent what the state of 
      // @line might be based on the condition 

      else if (line[0] == ':') {                                                                       // :
        if (line[1]=='#') {                                                                            // :#
          if (line[2]=='#') {                                                                          // :##
            if (line[3]=='#') {                                                                        // :###
              if (line[4]=='#') {                                                                      // :####
                if (line[5]=='#') {                                                                    // :#####
                  if (line[6]=='#') {                                                                  // :######
                    if (line[7]==':') {
                      if (llen > 8)  rb += "<h6 align=\"center\">" + line.substr(9, llen)+"</h6>\n";   // :######:
                    }
                    else {
                      if (llen > 7)  rb += "<h6 align=\"left\">" + line.substr(8, llen)+"</h6>\n";     // :######
                    }
                  } else {
                      if (line[6]==':') {
                        if (llen > 7)  rb += "<h5 align=\"center\">" + line.substr(8, llen)+"</h5>\n";  // :#####:
                    }
                    else {
                      if (llen > 6)  rb += "<h5 align=\"left\">" + line.substr(7, llen)+"</h5>\n";      // :#####
                    }
                  }
                } else {
                  if (line[5]==':') {
                    if (llen > 6)    rb += "<h4 align=\"center\">" + line.substr(7, llen) + "</h4>\n";    // :####:
                  } 
                  else { 
                    if (llen > 5)    rb += "<h4 align=\"left\">" + line.substr(6, llen) + "</h4>\n";      // :####
                  } 
                }                       
              } else {
                if (line[4]==':') {
                  if (llen > 5)      rb += "<h3 align=\"center\">" + line.substr(6, llen) + "</h3>\n";    // :###:
                } 
                else {
                  if (llen > 4)      rb += "<h3 align=\"left\">" + line.substr(5, llen) + "</h3>\n";      // :###
                }
              }
            } else {
                if (line[3]==':') {
                  if (llen > 4)        rb += "<h2 align=\"center\">"+line.substr(5, llen)+"</h2>\n";  // :##:
              }                                                                                       // 
              else {                                                                                  // 
                if (llen > 3)        rb += "<h2 align=\"left\">"+line.substr(4, llen)+"</h2>\n";        // :##
              }                                                                                       // 
            }                                                                                         //
          }else {                                                                                     //
            if(line[2]==':') {                                                                        // 
              if (llen > 3)          rb += "<h1 align=\"center\">"+line.substr(4, llen)+"</h1>\n";      // :#:
            }                                                                                         // 
            else {                                                                                    //
              if (llen > 2)           rb += "<h1 align=\"left\">"+line.substr(3, llen)+"</h1>\n";       // :#
            }                                                                                         //
          }                                                                                           //
        }                                                                                             //
      }                                                                                               //

      else if (line[0]=='#') {                                                                          // # 
        if (line[1]=='#') {                                                                             // ##
          if (line[2]=='#') {                                                                           // ###
            if (line[3]=='#') {                                                                         // ####
              if (line[4]=='#') {                                                                       // #####
                if (line[5]=='#') {                                                                     // ######
                  if (line[6]==':') {                                                                 //
                    if (llen > 7) rb += "<h6 align=\"right\">"+line.substr(8, llen)+"</h6>\n";          // ######:
                  }                                                                                   //
                  else {                                                                              //
                    if (llen > 6) rb += "<h6>"+line.substr(7, llen)+"</h6>\n";                          // ######
                  }                                                                                   //
                }else{                                                                                //
                  if(line[5]==':')  {                                                                 //
                    if (llen > 6) rb += "<h5 align=\"right\">"+line.substr(7, llen)+"</h5>\n";          // #####:
                  }                                                                                   //
                  else {                                                                              //
                    if (llen > 5) rb += "<h5>"+line.substr(6, llen)+"</h5>\n";                          // #####
                  }                                                                                   //
                }                                                                                     //
              } else {                                                                                 //
                if (line[4]==':')  {                                                                   //
                  if (llen > 5) rb += "<h4 align=\"right\">"+line.substr(6, llen)+"</h4>\n";            // ####:
                }                                                                                     //
                else {                                                                                //
                  if (llen > 4) rb += "<h4>"+line.substr(5, llen)+"</h4>\n";                            // ####
                }                                                                                     //
              }                                                                                       //
            } else{                                                                                   //
              if (line[3]==':')  {                                                                     //
                if (llen > 4) rb += "<h3 align=\"right\">"+line.substr(5, llen)+"</h3>\n";              // ###:
              }                                                                                       //
              else {                                                                                  //    
                if (llen > 3) rb += "<h3>"+line.substr(4, llen)+"</h3>\n";                              // ### 
              }                                                                                       //  
            }                                                                                         //
          } else{                                                                                     //
            if(line[2]==':')  {                                                                       //
              if (llen > 3) rb += "<h2 align=\"right\">"+line.substr(4, llen)+"</h2>\n";                // ##:
            }                                                                                         //
            else {                                                                                    //
              if (llen > 2) rb += "<h2 >"+line.substr(3, llen)+"</h2>\n";                               // ##
            }                                                                                         //
          }                                                                                           //
        } else{                                                                                       //
          if(line[1]==':') {                                                                          //
            if (llen > 2) rb += "<h1 align=\"right\">"+line.substr(3, llen)+"</h1>\n";                  // #:
          }                                                                                           //
          else {                                                                                      //
            if (llen > 1) rb += "<h1>"+line.substr(2, llen)+"</h1>\n";                                  // #
          }                                                                                           //
        }                                                                                             //
      }                                                                                               //

      else if ( BEGIN1(line, '>') ) {
        // FIXME: add error handling.
        // Because this mean `>` is not followed by content.
        if (llen > 2)               rb += "<blockquote>"+line.substr(2, llen)+"</blockquote>\n";        // > normal quote
      }
      else if ( BEGIN2(line, '/') ) {
        // FIXME: add error handling.
        // Because this mean `//` is not followed by content.
        if (llen > 2)               rb += "<!--"+line.substr(2, llen)+"-->";                            // ignored comments
      }
      else no_exp=true;

      if(no_exp && !(BEGIN3(line, '`') ) ) {


        rb += "<p>";
        LineConverter(&rb, line, llen, &active_state, 0, &no_exp);
        rb += "</p>\n";
      }

    } else no_exp=true;
    
    /*
     * Code blocks
     *```python
     *for i in range(1):
     *    print(i)
     *```
     */

    if ( BEGIN3(line, '`') ){
      if (active_state.CODE_FENCED) rb += "</code></pre>\n";
      else{
        std::string type = line.substr(3, llen);
        if(type.empty()) rb += "<pre><code class=\"language-plaintext\">\n"; 
        else rb += "<pre><code class=\"language-"+line.substr(3, llen)+"\">\n";
      }
      active_state.CODE_FENCED =! active_state.CODE_FENCED;
      no_exp=false;
    }




    if(no_exp){
      if(active_state.CODE_FENCED) rb += line+"\n";           // If code blocks are found, just add the line without any checks
      else                         rb += "<p>"+line+"</p>\n"; // If there's content on the line, turn it into a <p>aragraph
    }
    start = end + 1;
  }
}
