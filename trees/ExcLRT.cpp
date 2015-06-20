//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "ExcLRT.h"

template <typename T>
ExcLRT::ExcLRT(T vtx, LRT<T> child) : VertexLRT(vtx) {
    this->child = child;
}

ExcLRT::~ExcLRT() {
    delete(child);
}

template <typename T>
map<T, LRT<T>>* ExcLRT::getChildren() {
    auto children = new map<T, LRT<T>>();
    (*children)[child.getVertex()] = &child;
    return children;
}

template <typename T>
LRT<T>* ExcLRT::getChild() {
    return &(this->child);
}

bool ExcLRT::isInclusive() {
    return false;
}

template <typename T>
bool ExcLRT::isCompatibleWith(LRT<T> *that) {
    if (that->isLeaf()) {
        return true;
    } else if (that->isExclusive()) {
        auto match = & ((ExcLRT*) that)->child;
        return this->child.isCompatibleWith(match);
    } else {
        return false;
    }
}
