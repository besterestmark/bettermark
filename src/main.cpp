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
  )html";
  std::cout << main_parse(argv[1]) << std::endl;
  std::cout << R"html(
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.0.1/highlight.min.js"></script>
    <script>hljs.highlightAll();</script>
  </body>
</html>
  )html" << std::endl;
  return 0;
}
