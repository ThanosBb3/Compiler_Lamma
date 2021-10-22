#pragma once

#include <iostream>
#include "AST_main.hpp"

enum Types { TYPE_Unit, TYPE_Integer, TYPE_Char, TYPE_Boolean, TYPE_Real, TYPE_Tref, TYPE_Array, TYPE_Tfun, TYPE_Tid , TYPE_Unknown };

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
    char* id;
};

class Unit: public Type {
public:
  Unit(){    
    val = TYPE_Unit;
    oftype = nullptr;
    size = -1;}

  virtual void printOn(std::ostream &out) const override {
    out << "unit";
  }

};

class Integer: public Type {
public:
  Integer(){    
    val = TYPE_Integer;
    oftype = nullptr;
    size = -1;}

  virtual void printOn(std::ostream &out) const override {
    out << "int";
  }

};

class Char: public Type {
public:
  Char(){    
    val = TYPE_Char;
    oftype = nullptr;
    size = -1;}

  virtual void printOn(std::ostream &out) const override {
    out << "char";
  }

};

class Boolean: public Type {
public:
  Boolean(){    
    val = TYPE_Boolean;
    oftype = nullptr;
    size = -1;}

  virtual void printOn(std::ostream &out) const override {
    out << "bool";
  }

};

class Real: public Type {
public:
  Real(){    
    val = TYPE_Real;
    oftype = nullptr;
    size = -1;}

  virtual void printOn(std::ostream &out) const override {
    out << "real";
  }

};

class Tref: public Type {
public:
  Tref(Type *t) {
    val = TYPE_Tref;
    if(t->val==TYPE_Array){
      fprintf(stderr, "Error: Cannot implement reference to array.");
      exit(1);
    }
    oftype = t;
    size = -1;
  }

  virtual void printOn(std::ostream &out) const override {
    oftype->printOn(out); 
    out << " ref";
  }

};

class Array: public Type {
public:
  Array(Type *t, int dims = -1) {
    val = TYPE_Array;
    if(t->val==TYPE_Array){
      fprintf(stderr, "Error: Cannot implement array of arrays.");
      exit(1);
    }
    oftype = t;
    if(dims>0) size = dims;
    else size = -1;
  }

  virtual void printOn(std::ostream &out) const override {
    out << "array"; 
    if(size>1) {
      out << " [*";
      for (int i=1; i<size; i++) {
        out << ",*";
      }
      out << "]";
    }
    out << " of ";
    oftype->printOn(out);
  }

};

class Tfun: public Type {
public:
  Tfun(Type *l, Type *r) { 
    val = TYPE_Tfun; 
    left = l;
    if(r->val==TYPE_Array){
      fprintf(stderr, "Error: Cannot implement function that returns array.");
      exit(1);
    }
    /*
    else if(r->val==TYPE_Tfun){
      fprintf(stderr, "Error: Cannot implement function that returns function.");
      exit(1);
    }
    */
    right = r;
    oftype = nullptr; 
    size = -1;
  }

  virtual void printOn(std::ostream &out) const override {
    left->printOn(out);
    out << " -> ";
    right->printOn(out);
  }

private:
  Type* left;
  Type* right;
};

class Typeid: public Type {
public:
  Typeid(char *i) {
    val = TYPE_Tid; 
    oftype = nullptr; 
    size = -1; 
    id = i;
  }

  virtual void printOn(std::ostream &out) const override {
    out << "type " << id;
  }

  char* getID() override {
    return id;
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
    out << "unknown";
  }

};