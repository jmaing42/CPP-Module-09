#ifndef EX00_DATABASE_HPP_INCLUDED
#define EX00_DATABASE_HPP_INCLUDED

#include <vector>

class Database {
private:
  class Entry {
  public:
    int year;
    int month;
    int day;
    float rate;
  };

  std::vector<Entry> data;

public:
  Database();
  ~Database();
  Database(const Database &copy);
  Database &operator=(const Database &copy);

  void feed(const std::string &file);
};

#endif
