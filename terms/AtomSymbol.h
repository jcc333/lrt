//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __AtomSymbol_H_
#define __AtomSymbol_H_


#include "Symbol.h"

class AtomSymbol : public Symbol {
    string* underlying;
public:
    AtomSymbol(string* name);

    ~AtomSymbol();

    Type getType();

    string repr();

    bool operator ==(Symbol that);
};

#endif //__AtomSymbol_H_
