//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "LabeledRootedTree.h"

LRT<T> LRT::exc(LRT<T> *child) {
    return new ExclusiveLRT<T>(new RootNode<T>(), child);
}

LRT<T> LRT::inc(vector<LRT<T>> *children) {
    return new InclusiveLRT<T>(new RootNode<T>(), children);
}

LRT<T> LRT::ex(T t, LRT<T>* child) {
    return new ExclusiveLRT<T>(child);
}

LRT<T> LRT::in(T t, vector<LRT<T>>* children) {
    return new InclusiveLRT<T>(children);
}

LRT<T> LRT::leaf(T t) {
    return new InclusiveLRT<T>(t);
}

LRT<T> LRT::root() {
    return new InclusiveLRT<T>(new RootNode<T>(), new vector<LRT<T>>());
}

Node<T> LRT::getNode() {
    return this->node;
}
