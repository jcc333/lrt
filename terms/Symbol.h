//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __Symbol_H_
#define __Symbol_H_


#include <string>

using std::string;
class Symbol {
public:
    enum Type {
        Integer,
        Rational,
        Atom
    };

    virtual string repr();

    virtual bool operator ==(Symbol that);

    virtual Type getType();
};

#endif //__Symbol_H_
