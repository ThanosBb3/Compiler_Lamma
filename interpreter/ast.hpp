#pragma once

#include <iostream>
#include <map>
#include <vector>

class AST {
public:
  virtual ~AST() {}
  virtual void printOn(std::ostream &out) const = 0;
};

inline std::ostream& operator<< (std::ostream &out, const AST &t) {
  t.printOn(out);
  return out;
}

class Expr: public AST {
public:
  virtual int eval() const = 0;
};



extern std::map<char, int> globals;

class Id: public Expr {
public:
  Id(char v): var(v) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Id(" << var << ")";
  }
  virtual int eval() const override {
    return globals[var];
  }
private:
  char var;
};

class Const: public Expr {
public:
  Const(int n): num(n) {}
  virtual void printOn(std::ostream &out) const override {
    out << "Const(" << num << ")";
  }
  virtual int eval() const override {
    return num;
  }
private:
  int num;
};

class Binop: public Expr {
public:
  Binop(Expr *l, const char *o, Expr *r): left(l), op(o), right(r) {}
  ~Binop() { delete left; delete right; }
  virtual void printOn(std::ostream &out) const override {
    out << op << "(" << *left << ", " << *right << ")";
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

private:
  const char *op;
  Expr *right;
};

class Call: public Expr {
public:
  Call(Id *i, Exprlist *l): id(i), list(l) {}
  ~Call() { delete id; delete list; }
  virtual void printOn(std::ostream &out) const override {
    out << "Call" << "(" << *id << ", " << *list << ")";
  }

private:
  Id *id;
  Exprlist *list;
};


class Letin: public Expr {
public:
  Letin(Let *l, Expr *e): let(l), expr(e) {}
  ~Letin() { delete let; delete expr; }
  virtual void printOn(std::ostream &out) const override {
    out << "Letin" << "(" << *let << ", " << *expr << ")";
  }

private:
  Let *let;
  Expr *expr;
};


class Dim: public Expr {
public:
  Dim(Id *id, Constint *i = nullptr): iden(id), ien(i) {}
  ~Dim() { delete id; delete ien; }
  virtual void printOn(std::ostream &out) const override {
    out << "Dim" << "(" << *iden;
    if (ien != nullptr) out << ", " << *ien;
    out << ")"; 
  }

private:
  Id *iden;
  Constint *ien;
};


class New: public Expr {
public:
  New(Type *t): type(t) {}
  ~New() { delete type; }
  virtual void printOn(std::ostream &out) const override {
    out << "New" << "(" << *type << ")"; 
  }

private:
  Type *type;
};


class Delete: public Expr {
public:
  Delete(Expr *e): exp(e) {}
  ~Delete() { delete exp; }
  virtual void printOn(std::ostream &out) const override {
    out << "Delete" << "(" << *exp << ")"; 
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

private:
  Expr *cond;
  Expr *stmt1;
};


class For: public Expr {
public:
  For( bool b, Id *id, Expr *c, Expr *s1, Expr *s2 ):
    check(b), iden(id), cond(c), stmt1(s1), stmt2(s2) {}
  ~For() { delete iden; delete cond; delete stmt1; delete stmt2; }
  virtual void printOn(std::ostream &out) const override {
    if (check) out << "ForDown(" << *iden << ", " << *cond << ", " << *stmt1 << ", " << *stmt2 << ")";
    out << "For(" << *iden << ", " << *cond << ", " << *stmt1 << ", " << *stmt2 << ")";
  }

private:
  bool check;
  Id *iden;
  Expr *cond;
  Expr *stmt1;
  Expr *stmt2;
};


class Match: public Expr {
public:
  Match(Expr *e, Clauselist *l): exp(e), clist(l) {}
  ~Match() { delete exp; delete clist;}
  virtual void printOn(std::ostream &out) const override {
    out << "Match" << "(" << *exp << ", " << *clist << ")"; 
  }

private:
  Expr *exp;
  Clauselist *clist;
};


class BlockComponent : public AST{
public:

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

private:
  bool check;
  Deflist *dlist;
};


class Mytype: public BlockComponent {
public:
  Mytype(Tdeflist *l): tdlist(l) {}
  ~Mytype() { delete tdlist; }
  virtual void printOn(std::ostream &out) const override {
    out << "Mytype(" << *tdlist << ")";
  }

private:
  Tdeflist *tdlist;
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
  
private:
  std::vector<BlockComponent *> blist;
  int size;
};



class Def: public AST {
public:
  Def(Id *id, Parlist *l = nullptr, Expr *e = nullptr, Type *t = nullptr, Exprlist *el = nullptr):
    iden(id), plist(l), exp(e), tp(t), elist(el) {}
  ~Def() { delete iden; delete plist; delete exp; delete tp; delete elist; }
  virtual void printOn(std::ostream &out) const override {
    if (plist != nullptr) {
      out << "Def(" << *iden << ", " << *plist << ", " << *exp; 
      if (tp != nullptr) out << ", " << *tp;
      out << ")"; 
    }
    else {
      out << "Def mutable(" << *iden;
      if (elist == nullptr && tp ==nullptr) out << ")";
      if (elist == nullptr && tp !=nullptr) out << ", " << *tp << ")";
      if (elist != nullptr && tp ==nullptr) out << ", " << *elist << ")" ;
      else out << ", " << *tp << ", " << *elist << ")";
    }
  }

private:
  Id *iden;
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
  
private:
  std::vector<Def *> dlist;
  int size;
};









class Let: public Stmt {
public:
  Let(char v, Expr *e): var(v), expr(e) {}
  ~Let() { delete expr; }
  virtual void printOn(std::ostream &out) const override {
    out << "Let(" << var << " = " << *expr << ")";
  }
  virtual void run() const override {
    globals[var] = expr->eval();
  }
private:
  char var;
  Expr *expr;
};

class Print: public Stmt {
public:
  Print(Expr *e): expr(e) {}
  ~Print() { delete expr; }
  virtual void printOn(std::ostream &out) const override {
    out << "Print(" << *expr << ")";
  }
  virtual void run() const override {
    std::cout << expr->eval() << std::endl;
  }
private:
  Expr *expr;
};

class If: public Stmt {
public:
  If(Expr *c, Stmt *s1, Stmt *s2 = nullptr):
    cond(c), stmt1(s1), stmt2(s2) {}
  ~If() { delete cond; delete stmt1; delete stmt2; }
  virtual void printOn(std::ostream &out) const override {
    out << "If(" << *cond << ", " << *stmt1;
    if (stmt2 != nullptr) out << ", " << *stmt2;
    out << ")";
  }
  virtual void run() const override {
    if (cond->eval())
      stmt1->run();
    else if (stmt2 != nullptr)
      stmt2->run();
  }
private:
  Expr *cond;
  Stmt *stmt1;
  Stmt *stmt2;
};

class For: public Stmt {
public:
  For(Expr *e, Stmt *s): expr(e), stmt(s) {}
  ~For() { delete expr; delete stmt; }
  virtual void printOn(std::ostream &out) const override {
    out << "For(" << *expr << ", " << *stmt << ")";
  }
  virtual void run() const override {
    for (int times = expr->eval(), i = 0; i < times; ++i)
      stmt->run();
  }
private:
  Expr *expr;
  Stmt *stmt;
};

class Block: public Stmt {
public:
  Block(): stmt_list() {}
  ~Block() { for (Stmt *s : stmt_list) delete s; }
  void append(Stmt *s) { stmt_list.push_back(s); }
  virtual void printOn(std::ostream &out) const override {
    out << "Block(";
    bool first = true;
    for (Stmt *s : stmt_list) {
      if (!first) out << ", ";
      first = false;
      out << *s;
    }
    out << ")";
  }
  virtual void run() const override {
    for (Stmt *s : stmt_list)
      s->run();
  }
private:
  std::vector<Stmt *> stmt_list;
};