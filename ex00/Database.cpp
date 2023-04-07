#include "Database.hpp"

#include <cstdlib>
#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "isNDigit.hpp"
#include "isValidDate.hpp"
#include "split.hpp"

Database::Database() {}
Database::~Database() {}
Database::Database(const Database &copy) : data(copy.data) {}
Database &Database::operator=(const Database &copy) {
  this->data = copy.data;
  return *this;
}

void Database::feed(const std::string &path) {
  std::ifstream infile(path);
  std::string line;
  bool isHeader = true;
  while (std::getline(infile, line)) {
    if (isHeader) {
      if (line != "date,exchange_rate")
        throw std::exception();
      isHeader = false;
    } else {
      const std::vector<std::string> date_and_rate = split(line, ',');
      if (date_and_rate.size() != 2)
        throw std::exception();

      const std::vector<std::string> yyyy_mm_dd = split(date_and_rate[0], '-');
      if (yyyy_mm_dd.size() != 3)
        throw std::exception();
      const std::string yyyy = yyyy_mm_dd[0];
      if (!isNDigit(yyyy, 4))
        throw std::exception();
      const int y = std::atoi(yyyy.c_str());
      const std::string mm = yyyy_mm_dd[1];
      if (!isNDigit(mm, 2))
        throw std::exception();
      const int m = std::atoi(mm.c_str());
      const std::string dd = yyyy_mm_dd[2];
      if (!isNDigit(dd, 2))
        throw std::exception();
      const int d = std::atoi(dd.c_str());
      if (!isValidDate(y, m, d))
        throw std::exception();

      std::stringstream ss(date_and_rate[1]);
      double rate;
      ss >> rate;

      const long key = y * 10000L + m * 100L + d;
      this->data.insert(std::make_pair(key, rate));
    }
  }
}

double Database::get(long data) const {
  return this->data.lower_bound(data)->second;
}
