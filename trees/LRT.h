//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __LabeledRootedTree_H_
#define __LabeledRootedTree_H_

#include <utility>
#include <map>
#include "Node.h"
#include "LRT.h"
#include "IncLRT.h"
#include "ExcLRT.h"

using std::map;

template <class T>
class LRT {
    Node<T>* node;

public:

    LRT<T> root(map<T*, LRT<T>> *children) {
        return new IncLRT<T>(children);
    }

    LRT<T> root() {
        return new IncLRT();
    }

    LRT<T> inc(T* t, map<T*, LRT<T>>* children) {
        return new IncLRT<T>(t, children);
    }

    LRT<T> exc(T* t, LRT<T>* child) {
        return new ExcLRT<T>(t, child);
    }

    LRT<T> leaf(T t) {
        return new IncLRT<T>(t, new map<T*, LRT<T>>());
    }

    Node<T> getNode() {
        return this->node;
    }

    T* getVertex() {
        return this->node->getVertex();
    }

    bool proves(LRT *hypothesis) {
        return false;
    }

    LRT<T>(T vtx) {
        this->node = new Node<T>(vtx);
    }

    LRT<T>() {
        this->node = new Node<T>();
    }

    virtual bool isInclusive() { return true; }

    bool isExclusive() { return !isInclusive(); };

    virtual map<T*, LRT<T>*>* getChildren();

    virtual bool isLeaf();

    virtual bool isCompatibleWith(LRT<T>* that);

    virtual LRT<T> query(LRT<T>* q);

    virtual void assert(LRT<T>* assertion);

    virtual void retract(LRT<T>* retraction);
};

#endif //__LabeledRootedTree_H_
