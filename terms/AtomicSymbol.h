//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __AtomicSymbol_H_
#define __AtomicSymbol_H_


#include "Symbol.h"

class AtomicSymbol : public Symbol {
    string* underlying;
public:
    AtomicSymbol(string* name);

    ~AtomicSymbol();

    Type getType();

    string repr();

    bool operator ==(Symbol that);
};

#endif //__AtomicSymbol_H_
