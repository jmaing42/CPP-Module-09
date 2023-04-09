#include <list>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  PmergeMe<std::vector> vec;
  PmergeMe<std::list> list;
  for (int i = 1; i < argc; i++) {
    vec.add(argv[i]);
    list.add(argv[i]);
  }
}
