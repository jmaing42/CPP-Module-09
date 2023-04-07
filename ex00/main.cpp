#include "BitcoinExchange.hpp"
#include "Database.hpp"
#include <iostream>
int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0]
              << " <input file> [<input file> [<input file> ...]]" << std::endl;
  } else {
    Database database;
    database.feed("../data.csv");

    for (int i = 1; i < argc; i++)
      BitcoinExchange::processFile(database, argv[i]);
  }
}
