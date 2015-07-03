#ifndef __IncLRT_H_
#define __IncLRT_H_

#include <set>
#include "LRT.h"
#include "VertexLRT.h"

using std::map;
using std::set;

template <typename T>
class IncLRT : public VertexLRT<T> {
private:
    map<T, VertexLRT<T>*>* children;

public:
    IncLRT(T vtx, map<T, VertexLRT<T>*>* children) : VertexLRT<T>(vtx) {
      this->children = children;
    }

    IncLRT(T vtx, VertexLRT<T>* link) : VertexLRT<T>(vtx) {
      auto kids = new map<T*, VertexLRT<T>*>();
      kids->emplace(link->getVertex(), link);
      this->children = kids;
    }

    bool isLeaf() {
      return this->children->empty();
    }

    bool isInclusive() {
      return true;
    }

    IncLRT(T vtx) : VertexLRT<T>(vtx), children(new map<T, VertexLRT<T>*>()) {}

    ~IncLRT() {
      delete(children);
    }


    map<T, VertexLRT<T>*>* getChildren() {
      return this->children;
    }


    bool isCompatibleWith(LRT<T>* that) {
      auto these = *(this->getChildren());
      auto those = *(that->getChildren());

      //incidence set to avoid redundant comparisons
      auto seenKeys = new set<T>();

      //these children are compatible with that's
      for (auto &lc: these) {
        T key = lc.first;
        LRT<T>* tree = lc.second;
        auto rcIter = those.find(key);
        if (rcIter != these.end()) {
          auto rc = rcIter->second;
          if (!tree->isCompatibleWith(rc)) {
            return false;
          } else {
            seenKeys->insert(key);
          }
        }
      }

      //that's children are compatible with these
      for (auto &rc: those) {
        if (!seenKeys->count(rc.first)) {
          T key = rc.first;
          LRT<T>* tree = rc.second;
          auto lcIter = those.find(key);
          if (lcIter != these.end()) {
            auto lc = lcIter->second;
            if (! tree->isCompatibleWith(lc)) {
              return false;
            }
          }
        }
      }
      return true;
    }
};

#endif
