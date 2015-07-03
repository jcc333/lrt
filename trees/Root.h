//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include <set>
#include "LRT.h"
#include "VertexLRT.h"

using std::set;
using std::map;

template <typename T> 
class Root : public LRT<T> {
  private:
    map<T, VertexLRT<T>*>* children;

  public:
    Root(map<T, VertexLRT<T>*>* children) : children(children) {}

    Root() : children(new map<T, VertexLRT<T>*>()) {}

    ~Root() {
      delete children;
    }

    bool isInclusive() {
      return true;
    }

    map<T, VertexLRT<T>*>* getChildren() {
      return this->children;
    }

    bool isLeaf() {
      return ! this->getChildren()->empty();
    }

    bool isCompatibleWith(LRT<T>* that) {
      auto these = *(this->getChildren());
      auto those = *(that->getChildren());

      //incidence set to avoid redundant comparisons
      auto seenKeys = new set<T>();

      //these children are compatible with that's
      for (auto lc: these) {
        T key = lc.first;
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
          T key = rc.first;
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
};

#endif
