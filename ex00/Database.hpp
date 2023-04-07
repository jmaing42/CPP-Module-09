#ifndef EX00_DATABASE_HPP_INCLUDED
#define EX00_DATABASE_HPP_INCLUDED

#include <map>

class Database {
private:
  std::map<long, float> data;

public:
  Database();
  ~Database();
  Database(const Database &copy);
  Database &operator=(const Database &copy);

  void feed(const std::string &file);
};

#endif
