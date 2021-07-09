#include <iostream>
#include <string>
#include "parser.hpp"

#define DEBUG

int main(int argc, const char** argv) {

#ifdef DEBUG
  #include <time.h>
  clock_t start_time = clock();
#endif // DEBUG

    std::cout << R"html(
<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
  )html"
    << ConverterInitiater(argv[1]) << std::endl 
    << R"html(
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.0.1/highlight.min.js"></script>
    <script>hljs.highlightAll();</script>
  </body>
</html>
  )html" << std::endl;


#ifdef DEBUG
  double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    std::cerr << "Took " << elapsed_time << " seconds" << std::endl;
#endif // DEBUG

  return 0;
}
