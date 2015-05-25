//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_
#include "LabeledRootedTree.h"

using std::vector;

template <class T>
class IncLRT : public LRT {
public:
    IncLRT(T val, vector<LRT<T>>* children) : LRT<T>(val) {
        this->children = children;
    }

    vector<LRT<T>>* getChildren();

    bool isInclusive();

private:
    vector<LRT<T>>* children;
};

#endif //__InclusiveLRT_H_
