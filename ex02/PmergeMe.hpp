#ifndef EX02_PMERGE_ME_HPP_INCLUDED
#define EX02_PMERGE_ME_HPP_INCLUDED

#include <cstdlib>
#include <exception>
#include <memory>
#include <sstream>
#include <string>

bool isPositiveInt(const std::string &stringRepresentation);

template <template <typename TData, typename TAllocator =
                                        std::allocator<TData> /* clangd bug */>
          class T>
class PmergeMe {
private:
  T<int> container;

public:
  std::string toString() const {
    std::stringstream ss;
    bool isFirst = true;
    for (typename T<int>::const_iterator it = this->container.begin();
         it != this->container.end(); it++) {
      if (isFirst) {
        ss << " ";
        isFirst = false;
      }
      ss << *it;
    }
    return ss.str();
  }
  void add(const std::string &stringRepresentation) {
    if (!isPositiveInt(stringRepresentation))
      throw std::exception();
    this->add(std::atoi(stringRepresentation.c_str()));
  }
  void add(int n) { this->container.push_back(n); }

  void sort() {
    //
  }
};

template <template <typename TData, typename TAllocator =
                                        std::allocator<TData> /* clangd bug */>
          class T>
std::ostream &operator<<(std::ostream &os, const PmergeMe<T> &pmergeme) {
  os << pmergeme.toString();
  return os;
}

#endif
