#include "BitcoinExchange.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

#include "Database.hpp"
#include "isNDigit.hpp"
#include "isValidDate.hpp"
#include "split.hpp"

void BitcoinExchange::processFile(const Database &database,
                                  const std::string &path) {
  std::ifstream infile(path);
  std::string line;
  bool isHeader = true;
  while (std::getline(infile, line)) {
    if (isHeader) {
      if (line != "date | value")
        throw std::exception();
      isHeader = false;
    } else {
      try {
        const std::vector<std::string> date_and_value = split(line, '|');
        if (date_and_value.size() != 2)
          throw std::exception();

        const std::vector<std::string> yyyy_mm_dd_and_nothing =
            split(date_and_value[0], ' ');
        if (yyyy_mm_dd_and_nothing.size() != 1)
          throw std::exception();
        const std::vector<std::string> yyyy_mm_dd =
            split(yyyy_mm_dd_and_nothing[0], '-');
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

        const std::vector<std::string> nothing_and_value =
            split(date_and_value[1], ' ');
        if (nothing_and_value.size() != 2 || nothing_and_value[0] != "")
          throw std::exception();
        std::stringstream ss(nothing_and_value[1]);
        double value;
        ss >> value;
        if (0 > value || value > 1000)
          throw std::exception();

        const double rate = database.get(y * 10000L + m * 100L + d);
        std::cout << yyyy_mm_dd_and_nothing[0] << " => " << value << " = "
                  << (value * rate) << std::endl;
      } catch (const std::exception &e) {
        std::cout << "Failed!" << std::endl;
      }
    }
  }
}
