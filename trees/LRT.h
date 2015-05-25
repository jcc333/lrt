//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __LabeledRootedTree_H_
#define __LabeledRootedTree_H_

#include <utility>
#include <vector>
#include "Node.h"
#include "Arrow.h"

using std::vector;

template <class T>
class LRT {
    Node<T>* node;

public:
    static LRT<T> root();

    static LRT<T> root(vector<LRT<T>> *children);

    static LRT<T> leaf(T* t);

    static LRT<T> inc(T* t, vector<LRT<T>> *children);

    static LRT<T> exc(T* t, LRT<T> *child);

    LRT<T>(T vtx) {
        this->node = new Node<T>(vtx);
    }

    LRT<T>() {
        this->node = new Node<T>();
    }

    virtual bool isInclusive() { return true; }

    bool isExclusive() { return !isInclusive(); };

    Node<T> getNode();

    virtual T* getVertex();

    bool proves(LRT<T>* hypothesis);

    virtual vector<LRT<T>>* getChildren() { return new vector<LRT<T>>(); };

    virtual LRT<T>* greatestLowerBound(LRT<T>* that);

    virtual LRT<T>* leastUpperBound(LRT<T>* that);

    bool isCompatibleWith(LRT<T>* that);

    LRT<T> query(LRT<T>* q);

    void assert(LRT<T>* assertion);

    void retract(LRT<T>* retraction);
};

#endif //__LabeledRootedTree_H_
