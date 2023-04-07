#include "RPN.hpp"

#include <exception>

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &copy) : data(copy.data) {}
RPN &RPN::operator=(const RPN &copy) {
  this->data = copy.data;
  return *this;
}

void RPN::push(char data) {
  switch (data) {
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    this->data.push(data - '0');
    break;
  case '+': {
    if (this->data.size() < 2)
      throw std::exception();
    const double a = this->data.top();
    this->data.pop();
    const double b = this->data.top();
    this->data.top() = b + a;
    break;
  }
  case '-': {
    if (this->data.size() < 2)
      throw std::exception();
    const double a = this->data.top();
    this->data.pop();
    const double b = this->data.top();
    this->data.top() = b - a;
    break;
  }
  case '*': {
    if (this->data.size() < 2)
      throw std::exception();
    const double a = this->data.top();
    this->data.pop();
    const double b = this->data.top();
    this->data.top() = b * a;
    break;
  }
  case '/': {
    if (this->data.size() < 2)
      throw std::exception();
    const double a = this->data.top();
    this->data.pop();
    const double b = this->data.top();
    this->data.top() = b / a;
    break;
  }
  default:
    throw std::exception();
  }
}

double RPN::result() const {
  if (this->data.size() != 1)
    throw std::exception();
  return this->data.top();
}
