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
  Root* root(map<Symbol, VertexLRT*>* children) {
    return new Root(children);
  }

  Root* root() {
    return new Root();
  }

  IncLRT* inc(Symbol sym, map<Symbol, VertexLRT*>* children) {
    return new IncLRT(sym, children);
  }

  ExcLRT* exc(Symbol sym, VertexLRT* child) {
    return new ExcLRT(sym, child);
  }

  IncLRT* leaf(Symbol sym) {
    return new IncLRT(sym);
  }

  NilLRT* nil() {
    return new NilLRT();
  }
};

#endif
