//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __ExcLRT_H_
#define __ExcLRT_H_

#include "LRT.h"
#include "VertexLRT.h"

template <typename T> class ExcLRT : public VertexLRT<T> {
  private:
    LRT<T> child;

  public:
    ExcLRT(T vtx, LRT<T> child);

    ~ExcLRT();

    map<T, LRT<T>>* getChildren();

    LRT<T>* getChild();

    bool isInclusive();

    bool isCompatibleWith(LRT<T> *that);
};

#endif //__ExcLRT_H_
