//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __Node_H_
#define __Node_H_
#endif //__Node_H_
#include <stdexcept>

template <class T>
class Node {
    enum NodeType { root, vertex };
public:
    Node() : nodeType { root }, vtx{ nullptr } {};

    Node(T t) : nodeType { vertex }, vtx{ t } {};

    bool isRoot() {
        return this->nodeType == root;
    };

    bool isVertex() {
        return this->nodeType == vtx;
    };

    T* getVertex() {
        if ((*this).isVertex()) {
            return vtx;
        } else {
            throw std::out_of_range("no vertex at Node::getVertex");
        }
    };

    static Node Root() {
        return *new Node<T>();
    }

private:
    const NodeType nodeType;
    const T vtx;
};
