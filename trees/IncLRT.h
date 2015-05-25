//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include <set>
#include "LRT.h"

using std::map;
using std::set;

template <typename T>
class IncLRT : public LRT {
    map<T*, LRT<T>*>* children;

public:
    IncLRT(T val, map<T*, LRT<T>*>* children) : LRT<T>(val) {
        this->children = children;
    }

    IncLRT(Node<T> node, map<T*, LRT<T>*>* children) : LRT<T>(node) {
        this->children = children;
    }

    IncLRT(map<T*, LRT<T>*>* children) : LRT<T>(Node::RootNode()) {
        this->children = children;
    }

    IncLRT() : LRT<T>(Node::RootNode()) {
        this->children = new map<T*, LRT<T>*>();
    }

    map<T*, LRT<T>*>* getChildren() {
        return this->children;
    }

    bool isLeaf() {
        return ! this->getChildren()->empty();
    }

    bool isCompatibleWith(LRT<T> *that) {
        auto leftChildren = *(this->getChildren());
        auto rightChildren = *(that->getChildren());
        //incidence set to avoid redundant comparisons
        auto seenKeys = new set<T>();
        //these children are compatible with that's
        for (auto &lc: leftChildren) {
            T key = &lc.first;
            LRT<T> *tree = lc.second;
            LRT<T> *rc = rightChildren.find(key);
            if (rc != leftChildren.end()) {
                if (!tree->isCompatibleWith(rc)) {
                    return false;
                } else {
                    seenKeys->insert(key);
                }
            }
        }
        //that's children are compatible with these
        for (auto &rc: rightChildren) {
            if (!seenKeys->count(&rc.first)) {
                T key = &rc.first;
                LRT<T> *tree = rc.second;
                LRT<T> *lc = rightChildren.find(key);
                if (lc != leftChildren.end()) {
                    if (! tree->isCompatibleWith(lc)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

#endif //__InclusiveLRT_H_
