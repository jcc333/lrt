//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __LRT_H_
#define __LRT_H_

#include <utility>
#include <map>

using std::map;

template <class T> class LRT {
  public:
    virtual bool proves(LRT *hypothesis) {
      return false;
    }

    virtual bool isLeaf() {
      return ! this->getChildren()->empty();
    }

    virtual bool isInclusive() { return true; }

    bool isExclusive() { return !isInclusive(); };

    virtual map<T, LRT>* getChildren();

    virtual bool isCompatibleWith(LRT* that);

    virtual LRT query(LRT* q);

    virtual void assert(LRT* assertion);

    virtual void retract(LRT* retraction);
};

#endif //__LabeledRootedTree_H_
