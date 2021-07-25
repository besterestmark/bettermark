#define DEBUG
//#define MINIMALIST

#include <iostream>
#include <string>
#include <thread>
#include "parser.hpp"
#include "simio.hpp"

#include "argh.h"

#define echo std::cout <<

int main(int argc, const char** argv) {

#ifdef DEBUG
#include <time.h>
  clock_t start_time = clock();
#endif // DEBUG

  argh::parser cmdl(argc, argv);


  const size_t iVecsize = cmdl.pos_args().size()-1;
  std::thread *tr[iVecsize];


  if ( iVecsize > 1 ){
    for( size_t i =1; i<=iVecsize;i++ ){
      tr[i-1] = new std::thread(Writer,  cmdl.pos_args()[i], cmdl[{ "-s", "--syntax" }]  ); 
     }

    for( std::thread *write:tr ){
      write->join();
     }

  }
  else{
    std::string file_c = Readfile( cmdl.pos_args()[1].c_str()  );
#ifndef MINIMALIST
    std::cout << "<!DOCTYPE html>\n"
      "<html>\n"
      "<head>\n"
      "</head>\n"
      "<body>\n";
#endif // MINIMALIST
    std::cout
      << FenceConverter(&file_c)
      << std::endl;

    if (cmdl[{ "-s", "--syntax" }]){
      std::cout << "<script src=\"https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.0.1/highlight.min.js\"></script>\n"
        "<script>hljs.highlightAll();</script>\n";
    }

#ifndef MINIMALIST
    std::cout << 
      "</body>\n"
      "</html>\n"
      << std::endl;
#endif // MINIMALIST



  }

#ifdef DEBUG
  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  std::cerr << "Took " << elapsed_time << " seconds" << std::endl;
#endif // DEBUG


  return 0;
}
