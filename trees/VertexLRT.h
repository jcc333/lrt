//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __VertexLRT_H_
#define __VertexLRT_H_

#include <set>
#include "LRT.h"
#include "../terms/Symbol.h"

using std::map;
using std::set;

class VertexLRT : public LRT {
  private:
    Symbol vertex;

  public:
    VertexLRT(Symbol vtx) {
      this->vertex = vtx;
    }

    Symbol getVertex() {
      return vertex;
    }
};

#endif //__VertexLRT_H_
