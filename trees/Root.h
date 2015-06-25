//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include "LRT.h"

using std::map;

template <typename T> 
class Root : public LRT<T> {
  private:
    map<T, LRT<T>> *children;

  public:
    Root(map<T, LRT<T>> *children);

    Root();

    ~Root();

    map<T, LRT<T>>* getChildren();

    bool isLeaf();

    bool isCompatibleWith(LRT<T>* that);

    LRT<T>* query(LRT<T>* q);

    void assert(LRT<T>* assertion);

    void retract(LRT<T>* retraction);
};

#endif //__InclusiveLRT_H_
