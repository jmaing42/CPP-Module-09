#ifndef EX00_BITCOIN_EXCHANGE_HPP_INCLUDED
#define EX00_BITCOIN_EXCHANGE_HPP_INCLUDED

#include <string>

#include "Database.hpp"

class BitcoinExchange {
public:
  static void processFile(const Database &database, const std::string &path);

private:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &copy);
  BitcoinExchange &operator=(const BitcoinExchange &copy);
};

#endif
