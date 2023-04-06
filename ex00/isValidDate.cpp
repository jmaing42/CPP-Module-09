#include "isValidDate.hpp"

static bool isLeap(int year) {
  return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool isValidDate(int y, int m, int d) {
  if (y < 1800)
    return false;
  if (m < 1 || m > 12)
    return false;
  if (d < 1 || d > 31)
    return false;
  if (m == 2) {
    if (isLeap(y))
      return (d <= 29);
    else
      return (d <= 28);
  } else if (m == 4 || m == 6 || m == 9 || m == 11)
    return (d <= 30);
  return true;
}
