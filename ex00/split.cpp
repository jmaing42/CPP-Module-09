#include "split.hpp"

#include <sstream>

std::vector<std::string> split(const std::string input, char delimiter) {
  std::vector<std::string> answer;
  std::stringstream ss(input);
  std::string temp;

  while (getline(ss, temp, delimiter)) {
    answer.push_back(temp);
  }

  return answer;
}
