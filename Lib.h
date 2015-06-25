#ifndef __LIB_H_
#define __LIB_H_

#include <utility>
#include <map>
#include "trees/LRT.h"
#include "trees/Root.h"
#include "trees/ExcLRT.h"
#include "trees/IncLRT.h"
#include "terms/Symbol.h"

using std::map;

namespace Lib {
  LRT<Symbol>* root(map<Symbol, LRT<Symbol>>* children) {
    return new Root<Symbol>(children);
  }

  LRT<Symbol>* root() {
    return new Root<Symbol>();
  }

  LRT<Symbol>* inc(Symbol sym, map<Symbol, LRT<Symbol>>* children) {
    return new IncLRT<Symbol>(sym, children);
  }

  LRT<Symbol>* exc(Symbol sym, LRT<Symbol>* child) {
    return new ExcLRT<Symbol>(sym, child);
  }

  LRT<Symbol>* leaf(Symbol sym) {
    return new IncLRT<Symbol>(sym);
  }
};

#endif
