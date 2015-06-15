//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "RationalSymbol.h"

RationalSymbol::RationalSymbol(double q) {
    this->underlying = q;
}

Type RationalSymbol::getType() {
    return Symbol::Type::Rational;
}

string RationalSymbol::repr() {
    return std::to_string(underlying);
}

bool RationalSymbol::operator ==(Symbol that) {
    if (that.getType() == Rational) {
        auto rational = ((RationalSymbol*)&that);
        return rational->underlying == this->underlying;
    } else {
        return false;
    }
}
