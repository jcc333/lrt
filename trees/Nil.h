#ifndef __Nil_H_
#define __Nil_H_

#include <set>
#include "LRT.h"
#include "VertexLRT.h"
#include "../terms/Symbol.h"

using std::map;
using std::set;

class Nil : public LRT {
  public:
    Nil() : VertexLRT(Symbol()) {}

    bool isLeaf() {
      return true;
    }

    bool isInclusive() {
      return true;
    }

    map<Symbol, VertexLRT*>* getChildren() {
      return new map<Symbol, VertexLRT*>();
    }

    bool isCompatibleWith(LRT* that) {
      if (Nil* nil = dynamic_cast<Nil*>(that)) {
        return true;
      } else {
        return false;
      }
    }

    bool proves(LRT* q) {
      return this->isCompatibleWith(q);
    }

    LRT* query(LRT* q) {
      return this;
    }

    void assert(LRT* assertion) {
    }

    void retract(LRT* retraction) {
    }
};

#endif
