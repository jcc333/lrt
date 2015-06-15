//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __RationalSymbol_H_
#define __RationalSymbol_H_

#include "Symbol.h"

class RationalSymbol : public Symbol {
    double underlying;
public:
    RationalSymbol(double q);

    Type getType();

    string repr();

    bool operator ==(Symbol that);
};

#endif //__RationalSymbol_H_
