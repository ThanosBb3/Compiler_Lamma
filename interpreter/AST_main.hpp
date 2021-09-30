#pragma once

#include <iostream>

class Type;

class AST {
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;
  virtual void sem() {}
  virtual void sem(Type*) {}
  virtual void sem(bool b) {}
};

inline std::ostream& operator<< (std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}