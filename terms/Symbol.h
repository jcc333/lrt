#ifndef __Symbol_H_
#define __Symbol_H_


#include <string>

using std::string;

struct Symbol {
  enum {
    Integer,
    Rational,
    Atom,
    Nil
  } type;

  union {
    int integer;
    double rational;
    const string* atom;
  };

  Symbol() : type(Symbol::Nil), atom(new string("Nil")) {}

  Symbol(int i) : type(Symbol::Integer), integer(i) {}

  Symbol(double d) : type(Symbol::Rational), rational(d) {}

  Symbol(string* s) : type(Symbol::Atom), atom(s) {}

  string repr() {
    switch(this->type) {
      case Symbol::Integer:
        return std::to_string(this->integer);
      case Symbol::Rational:
        return std::to_string(this->rational);
      case Symbol::Atom:
        return *(this->atom);
      case Symbol::Nil:
        return "NIL";
    }
  }

  bool operator ==(Symbol that) const {
    if (this->type == that.type) {
      switch(this->type) {
        case Symbol::Integer:
          return this->integer == that.integer;
        case Symbol::Rational:
          return this->rational == that.rational;
        case Symbol::Atom:
          return this->atom == that.atom;
        default:
          return true;
      }
    } else if ((this->type == Symbol::Nil && that.type == Symbol::Atom)
        || (this->type == Symbol::Atom && that.type == Symbol::Nil)) {
      return this->atom == that.atom;
    } else if (this->type == Symbol::Atom && that.type == Symbol::Nil) {
      return this->atom == that.atom;
    } else {
      return false;
    }
  }

  bool operator >(Symbol that) const {
    if (this->type == that.type) {
      switch(this->type) {
        case Symbol::Integer:
          return this->integer > that.integer;
        case Symbol::Rational:
          return this->rational > that.rational;
        case Symbol::Atom:
          return this->atom > that.atom;
        default:
          return true;
      }
    } else {
      switch(this->type) {
        case Symbol::Atom:
          return true;
        case Symbol::Rational:
          return !(that.type == Symbol::Atom);
        case Symbol::Integer:
          return !(that.type == Symbol::Atom || that.type == Symbol::Rational);
        default:
          return false;
      }
    }
  }

  bool operator >=(Symbol that) const {
    return (*this == that) || (*this > that);
  }
  bool operator <(Symbol that) const {
    return !(*this == that) && !(*this > that);
  }
  bool operator <=(Symbol that) const {
    return (*this == that) || (*this < that);
  }

};
#endif //__Symbol_H_
