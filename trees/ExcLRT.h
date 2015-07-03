#ifndef __ExcLRT_H_
#define __ExcLRT_H_

#include "LRT.h"
#include "VertexLRT.h"

template <typename T> class ExcLRT : public VertexLRT<T> {
  private:
    VertexLRT<T>* child;

  public:
    ExcLRT(T vtx, VertexLRT<T>* child) : VertexLRT<T>(vtx) {
      this->child = child;
    }

    ~ExcLRT() {
      delete(child);
    }

    map<T, VertexLRT<T>*>* getChildren() {
      auto children = new map<T, VertexLRT<T>*>();
      (*children)[child->getVertex()] = child;
      return children;
    }

    LRT<T>* getChild() {
      return &(this->child);
    }

    bool isInclusive() {
      return false;
    }

    bool isLeaf() {
      return false;
    }

    bool isCompatibleWith(LRT<T>* that) {
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
