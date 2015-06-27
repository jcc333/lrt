#ifndef __Symbol_H_
#define __Symbol_H_


#include <string>

using std::string;

struct Symbol {
  enum {
    Integer,
    Rational,
    Atom
  } type;

  union {
    int integer;
    double rational;
    const string* atom;
  };

  string repr() {
    switch(this->type) {
      case Symbol::Integer:
        return std::to_string(this->integer);
      case Symbol::Rational:
        return std::to_string(this->rational);
      case Symbol::Atom:
        return *(this->atom);
    }
  }

  bool operator ==(Symbol that) {
    if (this->type == that.type) {
      switch(this->type) {
        case Symbol::Integer:
          return this->integer == that.integer;
        case Symbol::Rational:
          return this->rational == that.rational;
        case Symbol::Atom:
          return this->atom == that.atom;
      }
    } else {
      return false;
    }
  }
};
#endif //__Symbol_H_
