#ifndef EX02_PMERGE_ME_HPP_INCLUDED
#define EX02_PMERGE_ME_HPP_INCLUDED

#include <cstddef>
#include <cstdlib>
#include <exception>
#include <memory>
#include <sstream>
#include <string>

void swap(int &a, int &b);

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
      if (!isFirst)
        ss << " ";
      isFirst = false;
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

  typename T<int>::const_iterator begin() const { return container.begin(); }
  typename T<int>::const_iterator end() const { return container.end(); }

  void sort() {
    const size_t size = this->container.size();
    if (size < 5) {
      T<int> result;
      for (size_t i = 0; i < size; i++) {
        int min = this->container.front();
        for (typename T<int>::iterator j = this->container.begin();
             j != this->container.end(); j++) {
          if (min > *j)
            min = *j;
        }
        for (typename T<int>::iterator j = this->container.begin();
             j != this->container.end(); j++) {
          if (min == *j) {
            result.push_back(*j);
            this->container.erase(j);
            break;
          }
        }
      }
      this->container.swap(result);
    } else {
      const size_t half = size / 2;
      PmergeMe<T> a;
      PmergeMe<T> b;
      size_t remain = half;
      for (typename T<int>::iterator it = this->container.begin();
           it != this->container.end(); it++) {
        if (remain) {
          remain--;
          a.add(*it);
        } else {
          b.add(*it);
        }
      }
      a.sort();
      b.sort();
      typename T<int>::const_iterator aIt = a.begin();
      typename T<int>::const_iterator bIt = b.begin();
      T<int> result;
      while (aIt != a.end() || bIt != b.end()) {
        if (aIt == a.end()) {
          result.push_back(*bIt);
          bIt++;
        } else if (bIt == b.end()) {
          result.push_back(*aIt);
          aIt++;
        } else if (*aIt > *bIt) {
          result.push_back(*bIt);
          bIt++;
        } else {
          result.push_back(*aIt);
          aIt++;
        }
      }
      this->container.swap(result);
    }
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
