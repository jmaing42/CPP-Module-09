#include <cstddef>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

#include <sys/time.h>

#include "PmergeMe.hpp"

static struct timeval getTime() {
  struct timeval result;
  if (gettimeofday(&result, NULL))
    throw std::exception();
  return result;
}

static size_t sub(struct timeval lhs, struct timeval rhs) {
  return (lhs.tv_sec - rhs.tv_sec - 1) * (size_t)1000000 +
         (lhs.tv_usec + 1000000 - rhs.tv_usec);
}

int main(int argc, char **argv) {
  try {
    PmergeMe<std::vector> vec;
    PmergeMe<std::list> list;
    for (int i = 1; i < argc; i++) {
      vec.add(argv[i]);
      list.add(argv[i]);
    }
    std::cout << "Before: " << vec << std::endl;
    struct timeval vecStart = getTime();
    vec.sort();
    struct timeval vecEnd = getTime();
    struct timeval listStart = getTime();
    list.sort();
    struct timeval listEnd = getTime();
    std::cout << "After: " << vec << std::endl;
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << sub(vecEnd, vecStart)
              << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::list : " << sub(listEnd, listStart)
              << " us" << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error" << std::endl;
  }
}
