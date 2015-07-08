#ifndef __ExcLRT_H_
#define __ExcLRT_H_

#include "LRT.h"
#include "VertexLRT.h"

class ExcLRT : public VertexLRT {
  private:
    VertexLRT* child;

  public:
    ExcLRT(Symbol vtx, VertexLRT* child) : VertexLRT(vtx) {
      this->child = child;
    }

    map<Symbol, VertexLRT*>* getChildren() {
      auto children = new map<Symbol, VertexLRT*>();
      (*children)[child->getVertex()] = child;
      return children;
    }

    LRT* getChild() {
      return this->child;
    }

    bool isInclusive() {
      return false;
    }

    bool isLeaf() {
      return false;
    }

    bool isCompatibleWith(LRT* that) {
      if (that->isLeaf()) {
        return true;
      } else if (that->isExclusive()) {
        auto match = & ((ExcLRT*) that)->child;
        return this->child->isCompatibleWith(*match);
      } else {
        return false;
      }
    }
};

#endif //__ExcLRT_H_
