//
// Created by James Clemer on 6/9/15.
// Copyright (c) 2015 clem. All rights reserved.
//


#ifndef __Symbol_H_
#define __Symbol_H_


#include <string>

using std::string;
class Symbol {
  private:
    enum Type {
      Integer,
      Rational,
      Atom
    };

    union {
      int integer;
      double rational;
      string* atom;
    };

    Type type;

  public:
    string repr();

    bool operator ==(Symbol that);
};

#endif //__Symbol_H_
