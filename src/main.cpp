#include <iostream>
#include <string>
#include "parser.hpp"
#include "simio.hpp"

#include "argh.h"

#define DEBUG

int main(int argc, const char** argv) {

#ifdef DEBUG
#include <time.h>
  clock_t start_time = clock();
#endif // DEBUG

  argh::parser cmdl(argc, argv);


  std::string file_c = Readfile( cmdl.pos_args()[1].c_str()  ); 
  cmdl.pos_args();
  std::cout << "<!DOCTYPE html>\n"
    "<html>\n"
    "<head>\n"
    "</head>\n"
    "<body>\n"
    << FenceConverter(&file_c)
    << std::endl;

  if (cmdl[{ "-s", "--syntax" }]){
    std::cout << "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.0.1/highlight.min.js\"></script>\n"
      "<script>hljs.highlightAll();</script>\n";
  }
  std::cout << 
    "</body>\n"
    "</html>\n"
    << std::endl;


#ifdef DEBUG
  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  std::cerr << "Took " << elapsed_time << " seconds" << std::endl;
#endif // DEBUG

  return 0;
}
