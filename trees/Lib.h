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
    LRT<Symbol>* root(map<Symbol, LRT<Symbol>>* children);
    
    LRT<Symbol>* root();

    LRT<Symbol>* inc(Symbol t, map<Symbol, LRT<Symbol>>* children);

    LRT<Symbol>* exc(Symbol t, LRT<Symbol> child);

    LRT<Symbol>* leaf(Symbol t);
};

#endif
