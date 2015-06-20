//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __IncLRT_H_
#define __IncLRT_H_

#include <set>
#include "LRT.h"
#include "VertexLRT.h"

using std::map;
using std::set;

template <typename T>
class IncLRT : public VertexLRT<T> {
private:
    map<T, LRT<T>>* children;

public:
    IncLRT(T vtx, map<T, LRT<T>>* children);

    IncLRT(T vtx, LRT<T> child);

    IncLRT(T vtx);

    ~IncLRT();

    map<T, LRT<T>>* getChildren();

    bool isCompatibleWith(LRT<T> *that);
};

#endif
