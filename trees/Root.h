//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include <set>
#include "LRT.h"
#include "NilLRT.h"
#include "VertexLRT.h"

using std::set;
using std::map;

class Root : public LRT {
  private:
    map<Symbol, VertexLRT*>* children;

  public:
    Root(map<Symbol, VertexLRT*>* children) : children(children) {}

    Root() : children(new map<Symbol, VertexLRT*>()) {}

    ~Root() {
      delete children;
    }

    bool isInclusive() {
      return true;
    }

    map<Symbol, VertexLRT*>* getChildren() {
      return this->children;
    }

    bool isLeaf() {
      return ! this->getChildren()->empty();
    }

    bool isCompatibleWith(LRT* that) {
      auto these = *(this->getChildren());
      auto those = *(that->getChildren());

      //incidence set to avoid redundant comparisons
      auto seenKeys = new set<Symbol>();

      //these children are compatible with that's
      for (auto lc: these) {
        Symbol key = lc.first;
        auto tree = lc.second;
        auto rc = those.find(key);
        if (rc != these.end()) {
          if (!tree->isCompatibleWith(rc->second)) {
            return false;
          } else {
            seenKeys->insert(key);
          }
        }
      }

      //that's children are compatible with these
      for (auto rc: those) {
        if (!seenKeys->count(rc.first)) {
          Symbol key = rc.first;
          auto tree = rc.second;
          auto lc = those.find(key);
          if (lc != these.end()) {
            if (! tree->isCompatibleWith(lc->second)) {
              return false;
            }
          }
        }
      }
      return true;
    }
    
    LRT* query(LRT* q) {
      if (this->proves(q)) {
        return new Root();
      } else {
        return new Root(Symbol(), new NilLRT());
      }
    }

    void assert(LRT* assertion) {
    }

    void retract(LRT* retraction) {
    }
};

#endif
