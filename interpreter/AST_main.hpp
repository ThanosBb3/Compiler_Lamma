#pragma once

#include <iostream>
#include "type.hpp"

class AST {
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;
  virtual void sem() {}
  virtual void sem(Type*) {}
};