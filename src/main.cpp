#include <iostream>
#include <string>
#include "parser.hpp"


int main(int argc, const char** argv) {
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



  return 0;
}
