#pragma once

#include <iostream>
#include "AST_main.hpp"

enum Types { TYPE_Unit, TYPE_Integer, TYPE_Boolean, TYPE_Real, TYPE_Array, TYPE_Char, TYPE_Tref, TYPE_Tfun, TYPE_Tid , TYPE_Unknown};

class Type : public AST {
  public:
    Type() {}
    virtual ~Type() {}
    virtual void printOn(std::ostream &out) const override {
    out << "Type()";
  }
    virtual bool operator==(const Type &that) const { return false; }

    virtual char* getID() {
      return nullptr;
    }

    bool type_check(Types t) {
    if(val==TYPE_Unknown || t==TYPE_Unknown) {
      return true;
    }
    else if (val == t) return true;
    else return false;
  }


    Types val;
    Type *oftype;
    int size;
};

class Unit: public Type {
public:
  Unit(){    
    val = TYPE_Unit;
    oftype = nullptr;
    size = -1;}
  virtual void printOn(std::ostream &out) const override {
    out << "Unit()";
  }

};

class Integer: public Type {
public:
  Integer(){    
    val = TYPE_Integer;
    oftype = nullptr;
    size = -1;}
  virtual void printOn(std::ostream &out) const override {
    out << "Integer()";
  }

};

class Char: public Type {
public:
  Char(){    
    val = TYPE_Char;
    oftype = nullptr;
    size = -1;}
  virtual void printOn(std::ostream &out) const override {
    out << "Char()";
  }

};

class Boolean: public Type {
public:
  Boolean(){    
    val = TYPE_Boolean;
    oftype = nullptr;
    size = -1;}
  virtual void printOn(std::ostream &out) const override {
    out << "Boolean()";
  }


};

class Real: public Type {
public:
  Real(){    
    val = TYPE_Real;
    oftype = nullptr;
    size = -1;}
  virtual void printOn(std::ostream &out) const override {
    out << "Real()";
  }

};


class Typeid: public Type {
public:
  Typeid(char *i) { val = TYPE_Tid; oftype = nullptr; size = -1; id = i;}
  ~Typeid() { delete id; }
  virtual void printOn(std::ostream &out) const override {
    out << "Typeid (" << id << ")";
  }

  char* getID() override {
    return id;
  }

private:
  char *id;
};

class Tfun: public Type {
public:
  Tfun(Type *l, Type *r) { val = TYPE_Tfun; tleft = l; tright = r; oftype = nullptr; size = -1;}
  ~Tfun() { delete tleft; delete tright; }
  virtual void printOn(std::ostream &out) const override {
    out << "Tfun ("; tleft->printOn(out); out << " -> "; tright->printOn(out); out <<")";
  }
private:
  Type *tleft;
  Type *tright;
};

class Tref: public Type {
public:
  Tref(Type *t) {
    val = TYPE_Tref;
    oftype = t;
    size = -1;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Tref (";
    oftype->printOn(out); 
    out << ")";
  }

};

class Array: public Type {
public:
  Array(Type *t, int dims = -1) {
    val = TYPE_Array;
    if(dims>0) size = dims;
    else size = -1;
    oftype = t;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Array (Type: "; oftype->printOn(out);
    if(size>=0) out << " and size " << size;
    out << " )";
  }


};

class Tunknown: public Type {
public:
  Tunknown() {
    val = TYPE_Unknown;
    oftype = this;
    size = INT8_MAX;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "T_unknown";
  }

};