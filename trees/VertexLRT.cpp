//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "VertexLRT.h"

template <typename T>
VertexLRT::VertexLRT(T vtx) {
  this->vertex = vtx;
}

VertexLRT::~VertexLRT<T>() {
  delete(vertex);
}

template <typename T>
T VertexLRT::getVertex() {
  return vertex;
}
