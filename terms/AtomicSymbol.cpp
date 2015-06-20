//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "AtomicSymbol.h"

AtomicSymbol::AtomicSymbol(string* name) {
    this->underlying = name;
}

AtomicSymbol::~AtomicSymbol() {
    delete(underlying);
}

Type AtomicSymbol::getType() {
    return Symbol::Type::Atom;
}

string AtomicSymbol::repr() {
    return *underlying;
}

bool AtomicSymbol::operator ==(Symbol that) {
    if (that.getType() == Atom) {
        auto atom = ((AtomicSymbol*)&that);
        return *(atom->underlying) == *underlying;
    } else {
        return false;
    }
}
