//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __LIB_H_
#define __LIB_H_

#include <utility>
#include <map>
#include "LRT.h"
#include "Root.h"
#include "ExcLRT.h"
#include "IncLRT.h"
#include "../terms/Symbol.h"
#include "../terms/IntegerSymbol.h"
#include "../terms/AtomicSymbol.h"
#include "../terms/RationalSymbol.h"

using std::map;

class Lib {
  public:
    LRT<Symbol>* root(map<Symbol, LRT<Symbol>>* children) {
      return new Root<Symbol>(children);
    }

    LRT<Symbol>* root() {
      return new Root<Symbol>();
    }

    LRT<Symbol>* inc(Symbol t, map<Symbol, LRT<Symbol>>* children) {
      return new IncLRT<Symbol>(t, children);
    }

    LRT<Symbol>* exc(Symbol t, LRT<Symbol> child) {
      return new ExcLRT<Symbol>(t, child);
    }

    LRT<Symbol>* leaf(Symbol t) {
      return new IncLRT<Symbol>(t);
    }
};

#endif
