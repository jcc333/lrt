//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "LRT.h"
#include "IncLRT.h"
#include "ExcLRT.h"

LRT<T> LRT::root(vector<LRT<T>> *children) {
    return new IncLRT<T>(new RootNode<T>(), children);
}

LRT<T> LRT::root() {
    return root(new vector<LRT<T>>());
}

LRT<T> LRT::inc(T* t, vector<LRT<T>>* children) {
    return new IncLRT<T>(t, children);
}

LRT<T> LRT::exc(T* t, LRT<T>* child) {
    return new ExcLRT<T>(t, child);
}

LRT<T> LRT::leaf(T t) {
    return new IncLRT<T>(t, new vector<LRT<T>>());
}

Node<T> LRT::getNode() {
    return this->node;
}

T* LRT::getVertex() {
    return this->node->getVertex();
}

bool LRT::proves(LRT *hypothesis) {
    return false;
}
