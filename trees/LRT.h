#ifndef __LRT_H_
#define __LRT_H_

#include <utility>
#include <map>
#include "../terms/Symbol.h"

using std::map;

class VertexLRT;

class LRT {
  public:
    virtual bool proves(LRT* hypothesis) {
      return false;
    }
    
    virtual map<Symbol, VertexLRT*>* getChildren() = 0;

    virtual bool isLeaf() = 0;

    virtual bool isInclusive() = 0;

    virtual bool isExclusive() {
      return !isInclusive();
    }

    virtual bool isCompatibleWith(LRT* that) = 0;

    virtual LRT* query(LRT* q) = 0; //return the sub-tree that matches the query

    virtual void assert(LRT* assertion) = 0; //assert/override the contradictions

    virtual void retract(LRT* retraction) = 0; //remove the tree
};

#endif
