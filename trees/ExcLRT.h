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
    map<T*, LRT<T>>* getChildren() {
//        return new map<T*, LRT<T>*> { child.getVertex()};
    }

    bool isInclusive();

    bool isCompatibleWith(LRT<T>* that);
};

#endif //__ExcLRT_H_