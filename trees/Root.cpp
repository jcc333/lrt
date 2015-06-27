//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "Root.h"
#include <set>

using std::map;
using std::set;

template <typename T>
Root::Root(map<T, LRT<T>> *children) {
  this->children = children;
}

template <typename T>
Root::Root() {
  this->children = new map<T, LRT<T>>();
}

Root::~Root() {
  delete(children);
}

template <typename T>
map<T, LRT>* Root::getChildren() {
  return this->children;
}

bool Root::isLeaf() {
  return ! this->getChildren()->empty();
}

template <typename T>
bool Root::isCompatibleWith(LRT* that) {
  auto these = *(this->getChildren());
  auto those = *(that->getChildren());

  //incidence set to avoid redundant comparisons
  auto seenKeys = new set<T>();

  //these children are compatible with that's
  for (auto &lc: these) {
    T key = &lc.first;
    auto tree = lc.second;
    auto rc = those.find(key);
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
