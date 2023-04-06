#include <fstream>
#include <iostream>
#include <sstream>

#include "Database.hpp"
#include "isNDigit.hpp"
#include "isValidDate.hpp"
#include "split.hpp"

static void processFile(const Database &database, const std::string &path) {
  std::ifstream infile(path);
  std::string line;
  bool isHeader = true;
  while (std::getline(infile, line)) {
    if (!isHeader) {
      if (line != "date | value")
        throw std::exception();
      isHeader = false;
    } else {
      const std::vector<std::string> date_and_value = split(line, '|');
      if (date_and_value.size() != 2)
        throw std::exception();

      const std::vector<std::string> yyyy_mm_dd_and_nothing =
          split(date_and_value[0], ' ');
      if (yyyy_mm_dd_and_nothing.size() != 2 || yyyy_mm_dd_and_nothing[1] != "")
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
      float value;
      ss >> value;
      // TODO:
      (void)database;
    }
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << " <input file> [<input file> [<input file> ...]]" << std::endl;
  } else {
    Database database;
    database.feed("data.csv");

    for (int i = 1; i < argc; i++) {
      processFile(database, argv[i]);
    }
  }
}
