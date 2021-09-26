#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include "AST_main.hpp"
#include "type.hpp"
#include "symbol.hpp"

class Expr: public AST {
public:
  bool type_check(Types t) {
    if (type->val == t) return true;
    else return false;
  }

  Type *getType() {
    return type;
  }

  Types getVal() {
    return type->val;
  }

  Types getOfval() {
    return type->oftype->val;
  }

protected:
  Type *type;  
};

class Exprlist: public AST {
public:
  Exprlist(): elist(), size(0) {}
  ~Exprlist() {
    for (Expr *e : elist) delete e;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Exprlist(";
    bool first = true;
    for (Expr *e : elist) {
      if (!first) out << ", ";
      first = false;
      out << *e;
    }
    out << ")";
  }
  void append(Expr *ee) { elist.push_back(ee); size++;}
  
  virtual void sem() override{
    for (Expr *e : elist) e->sem();
  }

  int getSize() {
    return size;
  }

  std::vector<Expr *> getExps() {
    return elist;
  }
  
private:
  std::vector<Expr *> elist;
  int size;
};

class Binop: public Expr {
public:
  Binop(Expr *l, const char *o, Expr *r): left(l), op(o), right(r) {}
  ~Binop() { delete left; delete op; delete right; }
  virtual void printOn(std::ostream &out) const override {
    out << op << "(" << *left << ", " << *right << ")";
  }

  virtual void sem() override {
    left->sem();
    right->sem();

    if(! strcmp(op, "+") || ! strcmp(op, "-") || ! strcmp(op, "*") || ! strcmp(op, "/") || ! strcmp(op, "mod")) {
      if(left->type_check(TYPE_Integer) && right->type_check(TYPE_Integer)) {
        type = new Integer();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, "+.") || ! strcmp(op, "-.") || ! strcmp(op, "*.") || ! strcmp(op, "/.") || ! strcmp(op, "**")) {
      if(left->type_check(TYPE_Real) && right->type_check(TYPE_Real)) {
        type = new Real();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, "=") || ! strcmp(op, "<>") || ! strcmp(op, "==") || ! strcmp(op, "!=")) {
      if(!(left->type_check(TYPE_Array)) && !(left->type_check(TYPE_Tfun)) && (left->getVal() == right->getVal())) {
        type = new Boolean();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, "<") || ! strcmp(op, ">") || ! strcmp(op, "<=") || ! strcmp(op, ">=")) {
      if((left->type_check(TYPE_Integer) || left->type_check(TYPE_Real) || left->type_check(TYPE_Char)) && (left->getVal() == right->getVal())) {
        type = new Boolean();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, "&&") || ! strcmp(op, "||")) {
      if(left->type_check(TYPE_Boolean) && right->type_check(TYPE_Boolean)) {
        type = new Boolean();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, ":=")) {
      if(left->type_check(TYPE_Tref) && (right->getVal() == left->getOfval())) {
        type = new Unit();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    // na testarw oti oi typoi sto ; einai egkyroi
    else if(! strcmp(op, ";")) {
      type = right->getType();
    }
  }


private:
  Expr *left;
  const char *op;
  Expr *right;
};


class Unop: public Expr {
public:
  Unop(const char *o, Expr *r): op(o), right(r) {}
  ~Unop() { delete right; }
  virtual void printOn(std::ostream &out) const override {
    out << op << "(" << *right << ")";
  }

  virtual void sem() override {
    right->sem();

    if(! strcmp(op, "+") || ! strcmp(op, "-")) {
      if(right->type_check(TYPE_Integer)) {
        type = new Integer();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, "+.") || ! strcmp(op, "-.")) {
      if(right->type_check(TYPE_Real)) {
        type = new Real();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }

    else if(! strcmp(op, "not")) {
      if(right->type_check(TYPE_Boolean)) {
        type = new Boolean();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }
  }

private:
  const char *op;
  Expr *right;
};


class Delete: public Expr {
public:
  Delete(Expr *e): exp(e) {}
  ~Delete() { delete exp; }
  virtual void printOn(std::ostream &out) const override {
    out << "Delete" << "(" << *exp << ")"; 
  }

  virtual void sem() override {
    exp->sem();

    if (exp->type_check(TYPE_Tref)) {
      type = new Unit();
    }
    else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
    }
  }

private:
  Expr *exp;
};


class If: public Expr {
public:
  If(Expr *c, Expr *s1, Expr *s2 = nullptr):
    cond(c), stmt1(s1), stmt2(s2) {}
  ~If() { delete cond; delete stmt1; delete stmt2; }
  virtual void printOn(std::ostream &out) const override {
    out << "If(" << *cond << ", " << *stmt1;
    if (stmt2 != nullptr) out << ", " << *stmt2;
    out << ")";
  }

  virtual void sem() override {
    cond->sem();

    if (cond->type_check(TYPE_Boolean)) {
      
      stmt1->sem();
      if (stmt2 != nullptr) {
        stmt2->sem();
        if (stmt1->getVal() != stmt2->getVal()) {
          fprintf(stderr, "Error: %s\n", "Type Mismatch between then and else statements!!!");
          exit(1);
        }
        else {
          type = stmt1->getType();
        }
      }
      else {
        type = stmt1->getType();
      }
    }
    else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
    }
  }

private:
  Expr *cond;
  Expr *stmt1;
  Expr *stmt2;
};


class While: public Expr {
public:
  While(Expr *c, Expr *s1):
    cond(c), stmt1(s1) {}
  ~While() { delete cond; delete stmt1; }
  virtual void printOn(std::ostream &out) const override {
    out << "While(" << *cond << ", " << *stmt1 << ")";
  }

  virtual void sem() override {
    cond->sem();

    if (cond->type_check(TYPE_Boolean)) {
      stmt1->sem();
      if (stmt1->type_check(TYPE_Unit)) {
        type = new Unit();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }
    else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
    }
  }

private:
  Expr *cond;
  Expr *stmt1;
};


class For: public Expr {
public:
  For( bool b, char *id, Expr *c, Expr *s1, Expr *s2 ):
    check(b), iden(id), cond(c), stmt1(s1), stmt2(s2) {}
  ~For() { delete iden; delete cond; delete stmt1; delete stmt2; }
  virtual void printOn(std::ostream &out) const override {
    if (check) out << "ForDown(" << iden << ", " << *cond << ", " << *stmt1 << ", " << *stmt2 << ")";
    out << "For(" << iden << ", " << *cond << ", " << *stmt1 << ", " << *stmt2 << ")";
  }

  virtual void sem() override {
    st.openScope();
    st.insert(iden, new Integer(), ENTRY_IDENTIFIER);

    cond->sem();
    stmt1->sem();
    if (cond->type_check(TYPE_Integer) && stmt1->type_check(TYPE_Integer)) {
      stmt2->sem();
      if (stmt2->type_check(TYPE_Unit)) {
        type = new Unit();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
      }
    }
    else {
        fprintf(stderr, "Error: %s\n", "Type Mismatch!!!");
        exit(1);
    }

    st.closeScope();
  }

private:
  bool check;
  char *iden;
  Expr *cond;
  Expr *stmt1;
  Expr *stmt2;
};


class BlockComponent : public AST{
  public:

};


class Block: public AST {
public:
  Block(): blist(), size(0) {}
  ~Block() {
    for (BlockComponent *b : blist) delete b;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Block(";
    bool first = true;
    for (BlockComponent *b : blist) {
      if (!first) out << ", ";
      first = false;
      out << *b;
    }
    out << ")";
  }
  void append(BlockComponent *bb) { blist.push_back(bb); }
  
  virtual void sem() override{
    st.openScope();
    for (BlockComponent *b : blist) b->sem();
    st.closeScope();
  }

private:
  std::vector<BlockComponent *> blist;
  int size;
};


class Typelist: public AST {
public:
  Typelist(): tlist(), size(0) {}
  ~Typelist() {
    for (Type *t : tlist) delete t;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Typelist(";
    bool first = true;
    for (Type *t : tlist) {
      if (!first) out << ", ";
      first = false;
      out << *t;
    }
    out << ")";
  }
  void append(Type *tt) { tlist.push_back(tt); }
  
  virtual void sem() override{
    for (Type *t : tlist) {
      if(t->val==TYPE_Tid) {
        if(st.lookup(t->getID())==nullptr){
          fprintf(stderr, "Error: %s\n", "Invalid Type!!!");
          exit(1);
        }
      }
    }
  }

  std::vector<Type*> getVector() {
    return tlist;
  }

private:
  std::vector<Type *> tlist;
  int size;
};

class Constr: public AST {
public:
  Constr(char *id, Typelist *l = nullptr):
    iden(id), tlist(l) {}
  ~Constr() { delete iden; delete tlist; }
  virtual void printOn(std::ostream &out) const override {

    out << "Constr(" << iden;
    if(tlist) out << ", " << *tlist;
    out << ")"; 
  }

  virtual void sem(Type* t) override {
      tlist->sem();
      st.insert(iden, t, ENTRY_CONSTRUCTOR, tlist->getVector());

  }

private:
  char *iden;
  Typelist *tlist;
};


class Constrlist: public AST {
public:
  Constrlist(): clist(), size(0) {}
  ~Constrlist() {
    for (Constr *c : clist) delete c;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Constrlist(";
    bool first = true;
    for (Constr *c : clist) {
      if (!first) out << ", ";
      first = false;
      out << *c;
    }
    out << ")";
  }
  void append(Constr *cc) { clist.push_back(cc); }
  
  virtual void sem(Type* t) override{
    for (Constr *c : clist) c->sem(t);
  }

private:
  std::vector<Constr *> clist;
  int size;
};


class Tdef: public AST {
public:
  Tdef(char *id, Constrlist *l):
    iden(id), clist(l) {}
  ~Tdef() { delete iden; delete clist; }
  virtual void printOn(std::ostream &out) const override {
    out << "Tdef(" << iden << ", " << *clist << ")"; 
  }

  virtual void sem() override {
    Type* t = new Typeid(iden);
    st.insert(iden, t, ENTRY_TYPE);
    clist->sem(t);
  }

private:
  char *iden;
  Constrlist *clist;
};

class Tdeflist: public AST {
public:
  Tdeflist(): dlist(), size(0) {}
  ~Tdeflist() {
    for (Tdef *d : dlist) delete d;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Tdeflist(";
    bool first = true;
    for (Tdef *d : dlist) {
      if (!first) out << ", ";
      first = false;
      out << *d;
    }
    out << ")";
  }
  void append(Tdef *tt) { dlist.push_back(tt); }
  
  virtual void sem() override{
    for (Tdef *d : dlist) d->sem();
  }

private:
  std::vector<Tdef *> dlist;
  int size;
};


class Mytype: public BlockComponent {
public:
  Mytype(Tdeflist *l): tdlist(l) {}
  ~Mytype() { delete tdlist; }
  virtual void printOn(std::ostream &out) const override {
    out << "Mytype(" << *tdlist << ")";
  }

  virtual void sem() override {
    tdlist->sem();
  }

private:
  Tdeflist *tdlist;
};

class Par: public AST {
public:
  Par(char *id, Type *t = nullptr):
    iden(id), tp(t) {}
  ~Par() { delete iden; delete tp; }
  virtual void printOn(std::ostream &out) const override {
    out << "Parameter(" << iden;
    if(tp != nullptr) out << " of type " << *tp;
    out << " )"; 
  }

  virtual void sem() override {
    st.insert(iden, tp, ENTRY_PARAMETER);
  }

  Type* getType() {
    return tp;
  } 

private:
  char *iden;
  Type *tp;
};


class Parlist: public AST {
public:
  Parlist(): plist(), size(0) {}
  ~Parlist() {
    for (Par *p : plist) delete p;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Parlist(";
    bool first = true;
    for (Par *p : plist) {
      if (!first) out << ", ";
      first = false;
      out << *p;
    }
    out << ")";
  }
  void append(Par *pp) { plist.push_back(pp); }
  
  virtual void sem() override{
    for (Par *p : plist) p->sem();
  }

  std::vector<Type*> getPartypes() {
    std::vector<Type*> tps;
    for (Par *p : plist) tps.push_back(p->getType());
    return tps;
  }

  int getSize() {
    return size;
  }

private:
  std::vector<Par *> plist;
  int size;
};

class Def: public AST {
public:
  Def(char *id, Parlist *l = nullptr, Expr *e = nullptr, Type *t = nullptr, Exprlist *el = nullptr):
    iden(id), plist(l), exp(e), tp(t), elist(el) {}
  ~Def() { delete iden; delete plist; delete exp; delete tp; delete elist; }
  virtual void printOn(std::ostream &out) const override {
    if (plist != nullptr) {
      out << "Def(" << iden << ", " << *plist << ", " << *exp; 
      if (tp != nullptr) out << ", " << *tp;
      out << ")"; 
    }
    else {
      out << "Def mutable(" << iden;
      if (elist != nullptr && tp != nullptr) out << ", " << *tp << ", " << *elist << ")";
      if (elist == nullptr && tp != nullptr) out << ", " << *tp << ")";
      if (elist != nullptr && tp == nullptr) out << ", " << *elist << ")" ;
      else out << ")";
    }
  }

  virtual void sem() {

    if(plist->getSize()==0 && exp!=nullptr) {
      if(tp==nullptr) {
        st.insert(iden, exp->getType(), ENTRY_CONSTANT);
        exp->sem();
      }
      else {
        if (exp->type_check(tp->val)) {
          st.insert(iden, tp, ENTRY_CONSTANT);
          plist->sem();
          exp->sem();
        }
        else {
          fprintf(stderr, "Error: %s\n", "Type and value of constant do not match!!!");
          exit(1);
        }
      }
    }

    if(plist->getSize()>0) {
      if(tp==nullptr) {
        st.insert(iden, exp->getType(), ENTRY_FUNCTION, plist->getPartypes());
        st.openScope();
        plist->sem();
        exp->sem();
        st.closeScope();
      }
      else {
        if (exp->type_check(tp->val)) {
          st.insert(iden, tp, ENTRY_FUNCTION, plist->getPartypes());
          st.openScope();
          plist->sem();
          tp->sem();
          exp->sem();
          st.closeScope();
        }
        else {
          fprintf(stderr, "Error: %s\n", "Result type and value type of function do not match!!!");
          exit(1);
        }
      }
    }

    if(exp==nullptr && elist==nullptr) {
      if(tp==nullptr) {
        st.insert(iden, new Tunknown(), ENTRY_VARIABLE);
      }
      else{
        st.insert(iden, new Tref(tp), ENTRY_VARIABLE);
        tp->sem();
      }
    }

    if(elist!=nullptr) {
      if(tp==nullptr) {
        st.insert(iden, new Array(new Tunknown(), elist->getSize()), ENTRY_VARIABLE);
        elist->sem();
      }
      else {
        st.insert(iden, new Array(tp, elist->getSize()), ENTRY_VARIABLE);
        elist->sem();
        tp->sem();
      }
    }

  }

private:
  char *iden;
  Parlist *plist;
  Expr *exp;
  Type *tp;
  Exprlist *elist;
};

class Deflist: public AST {
public:
  Deflist(): dlist(), size(0) {}
  ~Deflist() {
    for (Def *d : dlist) delete d;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Deflist(";
    bool first = true;
    for (Def *d : dlist) {
      if (!first) out << ", ";
      first = false;
      out << *d;
    }
    out << ")";
  }
  void append(Def *dd) { dlist.push_back(dd); }

  virtual void sem() override{
    for (Def *d : dlist) d->sem();
  }
  
private:
  std::vector<Def *> dlist;
  int size;
};

class Let: public BlockComponent {
public:
  Let(bool b, Deflist *l):
    check(b), dlist(l) {}
  ~Let() { delete dlist; }
  virtual void printOn(std::ostream &out) const override {
    if (check) out << "LetRec(" << *dlist << ")";
    out << "Let(" << *dlist << ")";
  }

  virtual void sem() override{
    st.openScope();
    dlist->sem();
  }

private:
  bool check;
  Deflist *dlist;
};

class Letin: public Expr {
public:
  Letin(Let *l, Expr *e): let(l), expr(e) {}
  ~Letin() { delete let; delete expr; }
  virtual void printOn(std::ostream &out) const override {
    out << "Letin(" << *let << ", " << *expr << ")";
  }

  virtual void sem() {
    let->sem();
    expr->sem();
    type = expr->getType();
    st.closeScope();
  }


private:
  Let *let;
  Expr *expr;
};

class New: public Expr {
public:
  New(Type *t): tp1(t) {}
  ~New() { delete tp1; }
  virtual void printOn(std::ostream &out) const override {
    out << "New" << "(" << *tp1 << ")"; 
  }

  virtual void sem() {
    if(tp1->val!=TYPE_Array){
      tp1->sem();
      type = new Tref(tp1);
    }
    else{
      fprintf(stderr, "Error: %s\n", "Invalid Type!!!");
      exit(1);
    }
  }

private:
  Type *tp1;
};


class Valexpr: public Expr {

};


class Constint: public Valexpr {
public:
  Constint(int i, bool b): ien(i), check(b) {}
  ~Constint() {}
  virtual void printOn(std::ostream &out) const override {
    if (check) out << "NegConstint" << "(" << ien << ")"; 
    out << "Constint" << "(" << ien << ")";
  }

  virtual void sem() override {
    type = new Integer();
  }

  virtual void sem(Type* t) override {
    type = new Integer();
  }

private:
  int ien;
  bool check;
};

class Dim: public Expr {
public:
  Dim(char *id, int i = -1): iden(id), ien(i) {}
  ~Dim() { delete iden; }
  virtual void printOn(std::ostream &out) const override {
    out << "Dim" << "(" << iden;
    if (ien >= 0 ) out << ", " << ien;
    out << ")"; 
  }

  virtual void sem() override{
    SymbolEntry* arr;
    arr = st.lookup(iden);
    if(arr!=nullptr && arr->getEType()==ENTRY_VARIABLE && arr->getType()->val==TYPE_Array){
      if(ien>=1 && ien<=arr->getType()->size) {
      type = new Integer();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Not valid array dimension for return!!!");
        exit(1);
      }
    }
    else{
      fprintf(stderr, "Error: %s\n", "Invalid Type!!!");
      exit(1);
    }
    
  }

private:
  char *iden;
  int ien;
};


class Constreal: public Valexpr {
public:
  Constreal(float i, bool b): ien(i), check(b) {}
  ~Constreal() {}
  virtual void printOn(std::ostream &out) const override {
    if (check) out << "NegConstreal" << "(" << ien << ")"; 
    out << "Constreal" << "(" << ien << ")";
  }

  virtual void sem() override {
    type = new Real();
  }

  virtual void sem(Type* t) override {
    type = new Real();
  }

private:
  float ien;
  bool check;
};


class Constchar: public Valexpr {
public:
  Constchar(char *c): ch(c) {}
  ~Constchar() {}
  virtual void printOn(std::ostream &out) const override { 
    out << "Constchar" << "(" << ch << ")";
  }

  virtual void sem() override {
    type = new Char();
  }

  virtual void sem(Type* t) override {
    type = new Char();
  }

private:
  char *ch;
};


class Conststr: public Valexpr {
public:
  Conststr(const char *s): str(s) {}
  ~Conststr() { delete str; }
  virtual void printOn(std::ostream &out) const override { 
    out << "Conststr" << "(" << str << ")";
  }

  virtual void sem() override {
    type = new Array(new Char(), strlen(str)-1);
  }

private:
  const char *str;
};

class BrackExp: public Valexpr {
public:
  BrackExp(Expr *e): exp(e) {}
  ~BrackExp(){ delete exp; }
  virtual void printOn(std::ostream &out) const override {
    out << "BrackExpr( " << *exp << " )";  
  }

  virtual void sem() override {
    exp->sem();
    type = exp->getType();
  }

private:
  Expr *exp;  
};



class Constbool: public Valexpr {
public:
  Constbool(int i): ien(i) {}
  ~Constbool() {}
  virtual void printOn(std::ostream &out) const override { 
    out << "Constbool" << "(" << ien << ")";
  }

  virtual void sem() override {
    type = new Boolean();
  }

  virtual void sem(Type* t) override {
    type = new Boolean();
  }

private:
  int ien;
};


class Constunit: public Valexpr {
public:
  Constunit(){}
  ~Constunit() {}
  virtual void printOn(std::ostream &out) const override { 
    out << "Constunit" << "(" << ")";
  }

  virtual void sem() override {
    type = new Unit();
  }

};


class Id: public Valexpr {
public:
  Id(bool b, char *s): check(b), name(s) {}
  ~Id() { delete name; }
  virtual void printOn(std::ostream &out) const override { 
    if (check) out << "ConstrId" << "(" << name << ")";
    out << "Id" << "(" << name << ")";
  }

  virtual void sem() override {
    SymbolEntry* idd;
    idd = st.lookup(name);
    if(idd!=nullptr){
      type = idd->getType();  
    }
    else{
      fprintf(stderr, "Error: %s\n", "Invalid Type!!!");
      exit(1);
    }
  }

  virtual void sem(Type* t) override {
    st.insert(name, t, ENTRY_CONSTANT);
    type = t;
  }

private:
  bool check;
  char *name;
};


class Arrayitem: public Valexpr {
public:
  Arrayitem(char *s, Exprlist *l): id(s), elist(l)  {}
  ~Arrayitem() { delete id; }
  virtual void printOn(std::ostream &out) const override { 
    out << "Arrayitem" << "(" << id << ", " << *elist << ")";
  }

  virtual void sem() override{
    SymbolEntry* arr;
    arr = st.lookup(id);
    if(arr!=nullptr && arr->getEType()==ENTRY_VARIABLE && arr->getType()->val==TYPE_Array){
      elist->sem();
      for (Expr *e : elist->getExps()) {
        if(e->getType()->val!=TYPE_Integer) {
          fprintf(stderr, "Error: %s\n", "Invalid Type!!!");
          exit(1);
        }
      }
      type = new Tref(arr->getType());
      }
    else {
      fprintf(stderr, "Error: %s\n", "Not array!!!");
      exit(1);
    }
    
  }

private:
  char *id;
  Exprlist *elist;
};


class Deref: public Valexpr {
public:
  Deref(Valexpr *v): vexp(v)  {}
  ~Deref() { delete vexp; }
  virtual void printOn(std::ostream &out) const override { 
    out << "Deref" << "(" << *vexp << ")";
  }

  virtual void sem() override {
    vexp->sem();
    if(vexp->getType()->val==TYPE_Tref) {
      type = vexp->getType()->oftype;
    }
    else{
      fprintf(stderr, "Error: %s\n", "Invalid Type!!!");
      exit(1);
    }
}

private:
  Valexpr *vexp;
};



class Valexprlist: public AST {
public:
  Valexprlist(): velist(), size(0) {}
  ~Valexprlist() {
    for (Valexpr *e : velist) delete e;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Valexprlist(";
    bool first = true;
    for (Valexpr *e : velist) {
      if (!first) out << ", ";
      first = false;
      out << *e;
    }
    out << ")";
  }
  void append(Valexpr *vv) { velist.push_back(vv); }

  virtual void sem() override{
    for (Valexpr *v : velist) v->sem();
  }

  std::vector<Valexpr *> getVexps() {
    return velist;
  }
  
private:
  std::vector<Valexpr *> velist;
  int size;
};

class Call: public Expr {
public:
  Call(char *i, Valexprlist *l): id(i), list(l) {}
  ~Call() { delete id; delete list; }
  virtual void printOn(std::ostream &out) const override {
    out << "Call" << "(" << id << ", " << *list << ")";
  }

  virtual void sem() override {
    SymbolEntry* idd;
    idd = st.lookup(id);
    if(idd!=nullptr && (idd->getEType()==ENTRY_FUNCTION || idd->getEType()==ENTRY_CONSTRUCTOR)){
      list->sem();
      std::vector<Valexpr*> ves;
      std::vector<Type*> vtypes;
      std::vector<Type*> argtypes;
      vtypes = idd->getVector();
      ves = list->getVexps();
      for (Valexpr *v: ves) {
        argtypes.push_back(v->getType());
      }
      if(vtypes.size()!=argtypes.size()){
        fprintf(stderr, "Error: %s\n", "Unequal sizes!!!");
        exit(1);
      }
      for (int i=0; i<int(argtypes.size()); i++) {
        if(vtypes[i]->val!=argtypes[i]->val){
          fprintf(stderr, "Error: %s\n", "Not valid types!!!");
          exit(1);
        }
      }
      type = idd->getType();

    }
    else {
      fprintf(stderr, "Error: %s\n", "Not function or constructor!!!");
      exit(1);
    }
  }

private:
  char *id;
  Valexprlist *list;
};


class Pattern: public AST {
public:
  Pattern(Valexpr *v = nullptr, char *s = nullptr, Valexprlist *l = nullptr): ve(v), id(s), velist(l)  {}
  ~Pattern() { delete ve; delete id; delete velist; }
  virtual void printOn(std::ostream &out) const override {
    if(ve != nullptr) out << "PatternVal( " << *ve << " )";
    else out << "Pattern" << "(" << id << ", " << *velist << ")";
  }

  virtual void sem(Type* t) override {
    if(id!=nullptr) {
      ve->sem(t);
      switch(ve->getVal()) {
        case(TYPE_Integer):
          if(t->val!=TYPE_Integer){
            fprintf(stderr, "Error: %s\n", "Not valid types!!!");
            exit(1);
          }
          break;

        case(TYPE_Real):
           if(t->val!=TYPE_Real){
            fprintf(stderr, "Error: %s\n", "Not valid types!!!");
            exit(1);
          }
          break;

        case(TYPE_Char):
          if(t->val!=TYPE_Char){
            fprintf(stderr, "Error: %s\n", "Not valid types!!!");
            exit(1);
          }
          break;

        case(TYPE_Boolean):
          if(t->val!=TYPE_Boolean){
          fprintf(stderr, "Error: %s\n", "Not valid types!!!");
          exit(1);
          }
          break;

        default:
          fprintf(stderr, "Error: %s\n", "Not valid types!!!");
          exit(1);
      }
    }

    else {
      SymbolEntry* con;
      con = st.lookup(id);
      if(con!=nullptr && con->getType()->val==t->val) {
        std::vector<Type*> vtypes;
        vtypes = con->getVector();
        velist->sem();
        std::vector<Valexpr*> ves;
        std::vector<Type*> argtypes;
        ves = velist->getVexps();
        for (Valexpr *v: ves) {
          argtypes.push_back(v->getType());
        }
        if(vtypes.size()!=argtypes.size()){
        fprintf(stderr, "Error: %s\n", "Unequal sizes!!!");
        exit(1);
      }
      for (int i=0; i<int(argtypes.size()); i++) {
        if(vtypes[i]->val!=argtypes[i]->val){
          fprintf(stderr, "Error: %s\n", "Not valid types!!!");
          exit(1);
        }
      }
      }
    }
  }

  Type* gett() {
    return ve->getType();
  }

private:
  Valexpr *ve;
  char *id;
  Valexprlist *velist;
};

class BrackPat: public Valexpr {
public:
  BrackPat(Pattern *p): pat(p) {}
  ~BrackPat(){ delete pat; }
  virtual void printOn(std::ostream &out) const override {
    out << "BrackPat( " << *pat << " )";  
  }

  virtual void sem(Type* t) {
    pat->sem(t);
    type = pat->gett();
  }

private:
  Pattern *pat;  
};



class Clause: public AST {
public:
  Clause(Pattern *p, Expr *e): pat(p), exp(e)  {}
  ~Clause() { delete pat; delete exp; }
  virtual void printOn(std::ostream &out) const override { 
    out << "Clause" << "(" << *pat << ", " << *exp << ")";
  }

  virtual void sem(Type* t) override {
    st.openScope();
    pat->sem(t);
    exp->sem();
    st.closeScope();
  }

  Type* getetype() {
    return exp->getType();
  }

private:
  Pattern *pat;
  Expr *exp;
};

 
class Clauselist: public AST {
public:
  Clauselist(): clist(), size(0) {}
  ~Clauselist() {
    for (Clause *c : clist) delete c;
  }
  virtual void printOn(std::ostream &out) const override {
    out << "Clauselist(";
    bool first = true;
    for (Clause *c : clist) {
      if (!first) out << ", ";
      first = false;
      out << *c;
    }
    out << ")";
  }
  void append(Clause *cc) { clist.push_back(cc); }

  virtual void sem(Type* t) override {
    Type* check;
    clist[0]->sem(t);
    check = clist[0]->getetype();
    for (Clause *c : clist) {
      c->sem(t);
      if(c->getetype()!=check){
        fprintf(stderr, "Error: %s\n", "Not valid types!!!");
        exit(1);
      }
    }
  }

  Type* getctype() {
    return clist[0]->getetype();
  }
  
private:
  std::vector<Clause *> clist;
  int size;
};


class Match: public Expr {
public:
  Match(Expr *e, Clauselist *l): exp(e), clist(l) {}
  ~Match() { delete exp; delete clist;}
  virtual void printOn(std::ostream &out) const override {
    out << "Match" << "(" << *exp << ", " << *clist << ")"; 
  }

  virtual void sem() override {
    exp->sem();
    if(exp->getType()->val==TYPE_Tid) {
      SymbolEntry* exist;
      exist = st.lookup(exp->getType()->getID());
      if(exist!=nullptr && exist->getEType()==ENTRY_TYPE) {
        clist->sem(exp->getType());
        type = clist->getctype();
      }
      else {
        fprintf(stderr, "Error: %s\n", "Not valid type!!!");
        exit(1);
      }
    }
    else {
        fprintf(stderr, "Error: %s\n", "Not valid type!!!");
        exit(1);
    }
  }

private:
  Expr *exp;
  Clauselist *clist;
};