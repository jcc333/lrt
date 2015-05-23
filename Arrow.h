//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __Arrow_H_
#define __Arrow_H_

#include <utility>
#include "LabeledRootedTree.h"

template <class T>
class Arrow {
public:
    LRT<T>* apply(LRT<T>* kb);
private:
    LRT<T>* predicate;
    LRT<T>* consequent;
};

#endif //__Arrow_H_
