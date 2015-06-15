//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __IntegerSymbol_H_
#define __IntegerSymbol_H_


#include "Symbol.h"

class IntegerSymbol : public Symbol {
    int underlying;
public:
    IntegerSymbol(int n);

    Type getType();

    string repr();

    bool operator ==(Symbol that);
};


#endif //__IntegerSymbol_H_
