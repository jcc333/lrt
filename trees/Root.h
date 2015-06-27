//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include "LRT.h"

using std::set;
using std::map;

template <typename T> 
class Root : public LRT<T> {
  private:
    map<T, LRT<T>> *children;

  public:
    Root(map<T, LRT<T>> *children) {
      this->children = children;
    }


    Root() {
      this->children = new map<T, LRT<T>>();
    }

    ~Root() {
      delete children;
    }


    map<T, LRT<T>>* getChildren() {
      return this->children;
    }

    bool isLeaf() {
      return ! this->getChildren()->empty();
    }


    bool isCompatibleWith(LRT<T>* that) {
      auto these = *(this->getChildren());
      auto those = *(that->getChildren());

      //incidence set to avoid redundant comparisons
      auto seenKeys = new map<T, bool>();

      //these children are compatible with that's
      for (auto lc: these) {
        T key = lc.first;
        auto tree = lc.second;
        auto rc = those.find(key);
        if (rc != these.end()) {
          if (!tree->isCompatibleWith(rc)) {
            return false;
          } else {
            seenKeys->insert(key, true);
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
            if (! tree->isCompatibleWith(lc)) {
              return false;
            }
          }
        }
      }
      return true;
    }
};

#endif //__InclusiveLRT_H_
