#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>

struct ActiveState{
  bool COLLAPSIBLE=false;
  bool CUSTOM_CLASS=false;
  bool BLOCKQUOTE_FENCED=false;
  bool CODE_FENCED=false;
  bool UNORDERED_LIST=false;

  bool BOLD=false;
  bool ITALIC=false;
  bool UNDERLINE=false;
  bool STRIKETHROUGH=false;
  bool SPOILER=false;

  bool SUBSCRIPT=false;
  bool SUPERSCRIPT=false;

  bool CODE_INLINE=false;
};



auto LineConverter(std::string *buf, std::string line, ActiveState *as, uint8_t startIndex, bool *no_exp) noexcept -> void;
auto FenceConverter(const std::string *text) noexcept -> std::string;
#endif

