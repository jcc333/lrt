#ifndef __LIB_H_
#define __LIB_H_

#include <utility>
#include <map>
#include "trees/LRT.h"
#include "trees/ExcLRT.h"
#include "trees/IncLRT.h"
#include "trees/NilLRT.h"
#include "terms/Symbol.h"

using std::map;

namespace Lib {
  IncLRT* inc() {
    return new IncLRT(new map<Symbol, LRT*>());
  }
  
  IncLRT* root() {
    return inc();
  }

  IncLRT* inc(map<Symbol, VertexLRT*>* children) {
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
