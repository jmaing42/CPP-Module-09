#include "RPN.hpp"

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "split.hpp"

int main(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    try {
      RPN rpn;
      const std::vector<std::string> tokens = split(argv[i], ' ');
      for (std::vector<std::string>::const_iterator it = tokens.begin();
           it != tokens.end(); it++) {
        if (it->length() != 1)
          throw std::exception();
        rpn.push((*it)[0]);
      }
      std::cout << rpn.result() << std::endl;
    } catch (const std::exception &e) {
      std::cout << "Error!" << std::endl;
    }
  }
}
