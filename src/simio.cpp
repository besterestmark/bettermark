#include <fstream>
#include <string>
#include <iostream>

#include "parser.hpp"
#include "simio.hpp"

std::string Readfile(const char *kFilename)
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
  std::cerr << "betttermark: "<< kFilename <<": No such file or directory";
  exit(2);
}


std::string noext(std::string kFilename){
  size_t pos = kFilename.rfind('.');
  if (pos==std::string::npos)
    return kFilename;
  return kFilename.substr(0, pos);
}


void Writer(const std::string kFilename, const bool kSyntax){
  std::string f;
  f+= noext(kFilename);
  f+=".html";
  std::ofstream out( f );

  std::string file_c = Readfile( kFilename.c_str() );

#ifndef MINIMALIST
  out <<  "<!DOCTYPE html>\n"
      "<html>\n"
      "<head>\n"
      "</head>\n"
      "<body>\n";
#endif //MINIMALIST
  out << FenceConverter(&file_c) << "\n";
  if(kSyntax){
    out << "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.0.1/highlight.min.js\"></script>\n"
      "<script>hljs.highlightAll();</script>\n";
  }

#ifndef MINIMALIST
    out << 
      "</body>\n"
      "</html>\n"
      << std::endl;
#endif // MINIMALIST

}
