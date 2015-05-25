//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __Node_H_
#define __Node_H_
#include <stdexcept>

template <class T>
class Node {
public:
    Node() : isRootSwitch { true }, vtx { nullptr } {};

    Node(T vtx) : isRootSwitch { false }, vtx { vtx } {};

    bool isRoot();

    bool isVertex();

    T* getVertex();

    static Node RootNode();

private:
    const bool isRootSwitch;
    const T vtx;
};
#endif //__Node_H_
