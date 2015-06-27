#include "Symbol.h"
string Symbol::repr() {
  switch(type) {
    case Symbol::Type::Integer:
      return std::to_string(integer);
    case Symbol::Type::Rational:
      return std::to_string(rational);
    case Symbol::Type::Atom:
      return *atom;
  }
}

bool Symbol::operator ==(Symbol that) {
  if (that.type == type) {
    switch(type) {
      case Symbol::Type::Integer:
        return this->integer == that.integer;
      case Symbol::Type::Rational:
        return this->rational == that.rational;
      case Symbol::Type::Atom:
        return *(this->atom) == *(that.atom);
    }
  } else {
    return false;
  }
}
