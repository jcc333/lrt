//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include <stdlib.h>
#include "Node.h"

T* Node::getVertex() {
    if (this->isVertex()) {
        return vtx;
    } if (this->isRoot()) {
        throw std::out_of_range("no vertex at Node::getVertex");
    }
};

Node<T> Node::RootNode<T>() {
    return new Node<T>();
}

bool Node::isRoot() {
    return isRootSwitch;
}

bool Node::isVertex() {
    return ! isRootSwitch;
}
