#include "Lib.h"

LRT<Symbol>* Lib::root(map<Symbol, LRT<Symbol>>* children) {
  return new Root<Symbol>(children);
}

LRT<Symbol>* Lib::root() {
  return new Root<Symbol>();
}

LRT<Symbol>* Lib::inc(Symbol t, map<Symbol, LRT<Symbol>>* children) {
  return new IncLRT<Symbol>(t, children);
}

LRT<Symbol>* Lib::exc(Symbol t, LRT<Symbol> child) {
  return new ExcLRT<Symbol>(t, child);
}

LRT<Symbol>* Lib::leaf(Symbol t) {
  return new IncLRT<Symbol>(t);
}
