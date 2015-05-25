//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __ExcLRT_H_
#define __ExcLRT_H_

#include "LRT.h"

template <class T>
class ExcLRT : public LRT<T> {
    Node<T> child;

public:
    vector<LRT<T>>* getChildren();

    bool isInclusive();
};

#endif //__ExcLRT_H_