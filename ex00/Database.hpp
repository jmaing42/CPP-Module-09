#ifndef EX00_DATABASE_HPP_INCLUDED
#define EX00_DATABASE_HPP_INCLUDED

#include <functional>
#include <map>

class Database {
private:
  std::map<long, double, std::greater<long> /* clangd bug */> data;

public:
  Database();
  ~Database();
  Database(const Database &copy);
  Database &operator=(const Database &copy);

  void feed(const std::string &file);
  double get(long date) const;
};

#endif
