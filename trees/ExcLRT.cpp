//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "ExcLRT.h"

vector<LRT<T>>* ExcLRT::getChildren() {
    return new vector<LRT<T>> { this->child };
}

bool ExcLRT::isInclusive() {
    return false;
}

bool ExcLRT::isCompatibleWith(LRT<T> *that) {
    if (that->isLeaf()) {
        return true;
    } else if (that->isExclusive()) {

    } else { //that isInclusive and non-terminal

    }
}
