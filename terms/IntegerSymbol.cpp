//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "IntegerSymbol.h"

IntegerSymbol::IntegerSymbol(int n) {
    this->underlying = n;
}

string IntegerSymbol::repr() {
    return std::to_string(underlying);
}

bool IntegerSymbol::operator ==(Symbol that) {
    if (that.getType() == Integer) {
        auto integer = (IntegerSymbol *) &that;
        return integer->underlying == this->underlying;
    } else {
        return false;
    }
}

Type IntegerSymbol::getType() {
    return Symbol::Type::Integer;
}
