//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __ExcLRT_H_
#define __ExcLRT_H_

#include "LRT.h"

template <class T>
class ExcLRT : public VertexLRT<T>  {
  private:

    LRT<T> child;

  public:

    ExcLRT(T vtx, LRT<T> child) : VertexLRT(vtx) {
      this->child = child;
    }

    ~ExcLRT() {
      delete(child);
    }

    map<T, LRT<T>>* getChildren() {
      auto children = new map<T, LRT<T>>();
      (*children)[child.getVertex()] = &child;
      return children;
    }

    LRT<T>* getChild() {
      return this->child;
    }

    bool isInclusive() {
      return false;
    }

    bool isCompatibleWith(LRT<T> *that) {
      if (that->isLeaf()) {
        return true;
      } else if (that->isExclusive()) {
        auto match = & ((ExcLRT*) that)->child;
        return this->child.isCompatibleWith(match);
      } else {
        return false;
      }
    }
};

#endif //__ExcLRT_H_
