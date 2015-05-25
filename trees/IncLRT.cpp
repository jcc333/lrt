//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "IncLRT.h"

bool IncLRT::isInclusive() {
    return true;
}

vector<LRT<T>>*IncLRT::getChildren() {
    return this->children;
}
