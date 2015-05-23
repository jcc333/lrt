//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_
#include "LabeledRootedTree.h"

template <class T>
class InclusiveLRT : public LRT {
public:
    vector<LRT<T>>*getChildren();
    Node<T> getNode();
    T* getVertex();
    bool inclusive();
private:
    Node<T> node;
    vector<LRT<T>>* children;
};

#endif //__InclusiveLRT_H_
