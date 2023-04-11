#include <cstddef>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  try {
    PmergeMe<std::vector> vec;
    PmergeMe<std::list> list;
    for (int i = 1; i < argc; i++) {
      vec.add(argv[i]);
      list.add(argv[i]);
    }
    std::cout << "Before: " << vec << std::endl;
    time_t vecStart = time(NULL);
    vec.sort();
    time_t vecEnd = time(NULL);
    if (vecStart == time_t(-1) || vecEnd == time_t(-1))
      throw std::exception();
    time_t listStart = time(NULL);
    list.sort();
    time_t listEnd = time(NULL);
    if (listStart == time_t(-1) || listEnd == time_t(-1))
      throw std::exception();
    std::cout << "After: " << vec << std::endl;
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::vector : " << vecEnd - vecStart << " s"
              << std::endl;
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::list : " << listEnd - listStart << " s"
              << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error" << std::endl;
  }
}
