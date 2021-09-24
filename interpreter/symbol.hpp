#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include "type.hpp"

enum Entry_Type { 
       ENTRY_CONSTANT,
       ENTRY_FUNCTION,
       ENTRY_PARAMETER,
       ENTRY_VARIABLE,
       ENTRY_TYPE,
       ENTRY_CONSTRUCTOR,
       ENTRY_IDENTIFIER
   };

class SymbolEntry {
  public:
    virtual ~SymbolEntry() {}

    SymbolEntry *getNext() {
      return next;
    }

  protected:
    Entry_Type entry_type;
    SymbolEntry *next;

};

extern std::unordered_map<char*, SymbolEntry*> globals;

class SymVariable: public SymbolEntry {
  public:
    SymVariable(SymbolEntry *n, Type* t) {
      entry_type = ENTRY_VARIABLE;
      next = n; 
      type = t;
    }

  private:
    Type* type;
};

class SymConstant: public SymbolEntry {
  public:
    SymConstant(SymbolEntry *n, Type* t) {
      entry_type = ENTRY_CONSTANT;
      next = n; 
      type = t;
    }

  private:
    Type* type;
};

class SymType: public SymbolEntry {
  public:
    SymType(SymbolEntry *n, Type* t) {
      entry_type = ENTRY_TYPE;
      next = n; 
      type = t;
    }

  private:
    Type* type;
  
};

class SymFunction: public SymbolEntry {
  public:
    SymFunction(SymbolEntry *n, std::vector<Type*> vt, Type* t) {
      entry_type = ENTRY_FUNCTION;
      next = n;
      par_type = vt;
      res_type = t;
    }

  private:
    std::vector<Type*> par_type;
    Type* res_type;
};

class SymIdentifier: public SymbolEntry {
  public:
    SymIdentifier(SymbolEntry *n, Type* t) {
      entry_type = ENTRY_IDENTIFIER;
      next = n; 
      type = t;
    }

  private:
    Type* type;
};

class SymConstructor: public SymbolEntry {
  public:
    SymConstructor(SymbolEntry *n, std::vector<Type*> vt, Type* t) {
      entry_type = ENTRY_CONSTRUCTOR;
      next = n;
      par_type = vt;
      res_type = t;
    }

  private:
    std::vector<Type*> par_type;
    Type* res_type;
};

class SymParameter: public SymbolEntry {
  public:
    SymParameter(SymbolEntry *n, Type* t) {
      entry_type = ENTRY_PARAMETER;
      next = n; 
      type = t;
    }

  private:
    Type* type;
};

class Scope {
public:
  std::unordered_map<char*, SymbolEntry*> locals;  // Hash-map matching variable names to SymbolEntries

  Scope() {}  // Initializer: hash map locals is empty
  SymbolEntry *insert(char* c, Type* t, SymbolEntry *n, Entry_Type etype) {
    if (locals.find(c) != locals.end()) {  
      std::cerr << ("Duplicate entry " + std::string(c) + " in this scope!!!") << std::endl;  // Print error message
      exit(1);
    }
    switch(etype) {
      case(ENTRY_VARIABLE):
        locals[c] = new SymVariable(n, t);  // Create new variable
        break;
      case(ENTRY_CONSTANT):
        locals[c] = new SymConstant(n, t);  // Create new constant  
        break;
      case(ENTRY_TYPE):
        locals[c] = new SymType(n, t);  // Create new type  
        break;
      case(ENTRY_IDENTIFIER):
        locals[c] = new SymIdentifier(n, t);  // Create new identifier
        break;
      case(ENTRY_PARAMETER):
        locals[c] = new SymParameter(n, t);  // Create new parameter 
        break;
      default:
        std::cerr << "No valid entry type for the symbol table!!!" << std::endl;  // Print error message
        exit(1);    
    }
    return (locals[c]);  // Return pointer to the new entry
  }
  SymbolEntry *insert(char* c, Type* rt, SymbolEntry *n, Entry_Type etype, std::vector<Type*> vt) {
    if (locals.find(c) != locals.end()) {  
      std::cerr << ("Duplicate entry " + std::string(c) + " in this scope!!!") << std::endl;  // Print error message
      exit(1);
    }
    switch(etype) {
      case(ENTRY_FUNCTION):
        locals[c] = new SymFunction(n, vt, rt);  // Create new function
        break;
      case(ENTRY_CONSTRUCTOR):
        locals[c] = new SymConstructor(n, vt, rt);  // Create new constructor  
        break;
      default:
        std::cerr << "No valid entry type for the symbol table!!!" << std::endl;  // Print error message
        exit(1);    
    }

    return (locals[c]);  // Return pointer to the new entry
  }
};

class SymbolTable {
public:
  void openScope() {
   scopes.push_back(new Scope());  // Push new scope on the top of data stack
  }
  void closeScope() {  // Removes top scope
    for (std::unordered_map<char*, SymbolEntry*>::iterator it = scopes.back()->locals.begin(); it != scopes.back()->locals.end(); it++) {
      if (it->second->getNext() == nullptr){
        globals.erase(it->first);
      }
      else{
        globals[it->first] = it->second->getNext();  // Make the global hash table point the next occurance of this variable name
      }
    }
    scopes.pop_back();  // Remove top scope
  };
  SymbolEntry *lookup(char* c) {
    if (globals.find(c) == globals.end()) {
      return nullptr;
    }
    return globals[c];  // If entry exists return pointer to its SymbolEntry
  }
  void insert(char* c, Type* t, Entry_Type etype) {
    SymbolEntry *n;  // Pointer to next variable with the same name
    if (globals.find(c) == globals.end()) n = nullptr;  // If it doesn't exist point to nullptr
    else n = globals[c];  // else point to it
    globals[c] = scopes.back()->insert(c, t, n, etype); // Insert SymbolEntry to top Scope
  }
  void insert(char* c, Type* t, Entry_Type etype ,std::vector<Type*> vt) {
    SymbolEntry *n;  // Pointer to next variable with the same name
    if (globals.find(c) == globals.end()) n = nullptr;  // If it doesn't exist point to nullptr
    else n = globals[c];  // else point to it
    globals[c] = scopes.back()->insert(c, t, n, etype, vt); // Insert SymbolEntry to top Scope
  }
  int getSizeOfCurrentScope() {
    if (scopes.empty()) {
      std::cerr << "Scopes empty (symbol.hpp).";
      exit(1);
    }
    return scopes.back()->locals.size();
  }
private:
  std::vector<Scope*> scopes;  // The data stack
};

extern SymbolTable st; // The symbol table