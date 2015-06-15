//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "AtomSymbol.h"

AtomSymbol::AtomSymbol(string* name) {
    this->underlying = name;
}

AtomSymbol::~AtomSymbol() {
    delete(underlying);
}

Type AtomSymbol::getType() {
    return Symbol::Type::Atom;
}

string AtomSymbol::repr() {
    return *underlying;
}

bool AtomSymbol::operator ==(Symbol that) {
    if (that.getType() == Atom) {
        auto atom = ((AtomSymbol*)&that);
        return *(atom->underlying) == *underlying;
    } else {
        return false;
    }
}
