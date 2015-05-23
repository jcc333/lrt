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
#include <>

using std::vector;

template <class T>
class LRT {
public:
    //tree construction conveniences
    static LRT<T> root();
    static LRT<T> leaf(T t);

    static LRT<T> inc(T t, vector<LRT<T>> *children);
    static LRT<T> inc(vector<LRT<T>> *children);

    static LRT<T> exc(T t, LRT<T> *child);
    static LRT<T> exc(LRT<T> *child);

    virtual bool inclusive();
    constexpr bool exclusive() { return ! inclusive(); };

    virtual vector<LRT<T>>* getChildren();
    virtual Node<T> getNode();
    virtual T* getVertex();

    bool proves(LRT<T>* hypothesis);
    bool isCompatibleWith(LRT<T>* that);
    char* display();

    LRT<T> query(LRT<T>* q);
    void assert(LRT<T>* q);
    void imply(Arrow<T>* rule);
private:
    Node<T> node;
};

#endif //__LabeledRootedTree_H_
