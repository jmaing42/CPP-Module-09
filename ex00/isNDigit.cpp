#include "isNDigit.hpp"

#include <cctype>

bool isNDigit(const std::string str, size_t n) {
  if (str.length() != n)
    return false;
  for (size_t i = 0; i < n; i++)
    if (!std::isdigit(str[i]))
      return false;
  return true;
}
