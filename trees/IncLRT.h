//
// Created by James Clemer on 5/23/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#ifndef __InclusiveLRT_H_
#define __InclusiveLRT_H_

#include <set>
#include "LRT.h"

using std::map;
using std::set;

template <typename T>
class IncLRT : public VertexLRT {
  private:
    map<T, LRT<T>>* children;

  public:
    IncLRT(T vtx, map<T, LRT<T>>* children) : VertexLRT<T>(vtx) {
      this->children = children;
    }

    IncLRT(T vtx, map<T, LRT<T>>* children) : VertexLRT<T>(vtx) {
      this->children = new map<T*, LRT<T>>()
    }

    IncLRT(T vtx, map<T, LRT<T>>* children) : VertexLRT<T>(vtx) {
      this->children = children;
    }

    ~IncLRT() {
      delete(children);
    }

    map<T, LRT<T>>* getChildren() {
      return this->children;
    }

    bool isCompatibleWith(LRT<T> *that) {
      auto these = *(this->getChildren());
      auto those = *(that->getChildren());

      //incidence set to avoid redundant comparisons
      auto seenKeys = new set<T>();

      //these children are compatible with that's
      for (auto &lc: these) {
        T key = &lc.first;
        LRT<T> *tree = lc.second;
        LRT<T> *rc = those.find(key);
        if (rc != these.end()) {
          if (!tree->isCompatibleWith(rc)) {
            return false;
          } else {
            seenKeys->insert(key);
          }
        }
      }

      //that's children are compatible with these
      for (auto &rc: those) {
        if (!seenKeys->count(&rc.first)) {
          T key = &rc.first;
          LRT<T> *tree = rc.second;
          LRT<T> *lc = those.find(key);
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
