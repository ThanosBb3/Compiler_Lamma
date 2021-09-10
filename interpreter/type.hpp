#pragma once

#include <iostream>
#include "AST_main.hpp"


class Type : public AST{

};

inline std::ostream& operator<< (std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}

class Unit: public Type {
public:
  Unit(){}
  virtual void printOn(std::ostream &out) const override {
    out << "Unit()";
  }

};

class Integer: public Type {
public:
  Integer(){}
  virtual void printOn(std::ostream &out) const override {
    out << "Integer()";
  }

};

class Char: public Type {
public:
  Char(){}
  virtual void printOn(std::ostream &out) const override {
    out << "Char()";
  }

};

class Boolean: public Type {
public:
  Boolean(){}
  virtual void printOn(std::ostream &out) const override {
    out << "Boolean()";
  }

};

class Real: public Type {
public:
  Real(){}
  virtual void printOn(std::ostream &out) const override {
    out << "Real()";
  }

};


class Typeid: public Type {
public:
  Typeid(char *i):
    iden(i) {}
  ~Typeid() { delete iden; }
  virtual void printOn(std::ostream &out) const override {
    out << "id (" << iden << ")";
  }

private:
  char *iden;

};

class Tfun: public Type {
public:
  Tfun(Type *l, Type *r):
    tleft(l), tright(r) {}
  ~Tfun() { delete tleft; delete tright; }
  virtual void printOn(std::ostream &out) const override {
    out << "Tfun (" << *tleft << " -> " << *tright <<")";
  }

private:
  Type *tleft;
  Type *tright;

};

class Tref: public Type {
public:
  Tref(Type *t):
    tp(t) {}
  ~Tref() { delete tp; }
  virtual void printOn(std::ostream &out) const override {
    out << "Tref (" << *tp << ")";
  }

private:
  Type *tp;

};

class Array: public Type {
public:
  Array(Type *t, int dims = -1):
    tp(t), size(dims) {}
  ~Array() { delete tp; }
  virtual void printOn(std::ostream &out) const override {
    out << "Array (Type: " << *tp;
    if(size>=0) out << " and size " << size;
    out << " )";
  }

private:
  Type *tp;
  int size;

};