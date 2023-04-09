#include "PmergeMe.hpp"

bool isPositiveInt(const std::string &stringRepresentation) {
  int result = 0;

  if (!stringRepresentation[0] ||
      (stringRepresentation[0] == '-' && !stringRepresentation[1]) ||
      (stringRepresentation[0] == '-' && stringRepresentation[1] == '0') ||
      (stringRepresentation[0] == '0' && stringRepresentation[1]))
    return false;
  for (size_t i = 0; stringRepresentation[i]; i++) {
    if (!std::isdigit(stringRepresentation[i]) ||
        result > std::numeric_limits<int>::max() / 10 ||
        result < std::numeric_limits<int>::min() / 10 ||
        (result == std::numeric_limits<int>::max() / 10 &&
         (stringRepresentation[i] - '0') >
             (std::numeric_limits<int>::max() % 10)) ||
        (result == std::numeric_limits<int>::min() / 10 &&
         (stringRepresentation[i] - '0') >
             -(std::numeric_limits<int>::min() % 10)))
      return false;
    result = result * 10 + (stringRepresentation[i] - '0');
  }
  return true;
}
