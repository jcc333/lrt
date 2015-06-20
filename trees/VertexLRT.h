//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __VertexLRT_H_
#define __VertexLRT_H_

#include <set>
#include "LRT.h"

using std::map;
using std::set;

template <typename T>
class VertexLRT : public LRT<T> {
  private:
    T vertex;

  public:
    VertexLRT(T vtx);

    ~VertexLRT();

    T getVertex();
};

#endif //__VertexLRT_H_
