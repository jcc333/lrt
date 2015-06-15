//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include <set>
#include "LRT.h"

using std::map;
using std::set;

template <typename T>
class VertexLRT : public LRT {
  private:
    T vertex;

  public:
    VertexLRT(T vtx) {
      this->vertex = vtx;
    }

    ~VertexLRT() {
      delete(T);
    }
};

#endif //__InclusiveLRT_H_
