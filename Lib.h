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
  Root<Symbol>* root(map<Symbol, VertexLRT<Symbol>*>* children) {
    return new Root<Symbol>(children);
  }

  Root<Symbol>* root() {
    return new Root<Symbol>();
  }

  IncLRT<Symbol>* inc(Symbol sym, map<Symbol, VertexLRT<Symbol>*>* children) {
    return new IncLRT<Symbol>(sym, children);
  }

  ExcLRT<Symbol>* exc(Symbol sym, VertexLRT<Symbol>* child) {
    return new ExcLRT<Symbol>(sym, child);
  }

  IncLRT<Symbol>* leaf(Symbol sym) {
    return new IncLRT<Symbol>(sym);
  }
};

#endif
