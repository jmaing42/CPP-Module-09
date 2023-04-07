#ifndef EX01_RPN_HPP_INCLUDED
#define EX01_RPN_HPP_INCLUDED

#include <stack>

class RPN {
private:
  std::stack<double> data;

public:
  RPN();
  ~RPN();
  RPN(const RPN &copy);
  RPN &operator=(const RPN &copy);

  void push(char data);
  double result() const;
};

#endif
