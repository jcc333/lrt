#ifndef __IncLRT_H_
#define __IncLRT_H_

#include <set>
#include "LRT.h"
#include "VertexLRT.h"
#include "../terms/Symbol.h"

using std::map;
using std::set;

class IncLRT : public VertexLRT {
private:
    map<Symbol, VertexLRT*>* children;

public:
    IncLRT(map<Symbol, VertexLRT*>* children) : VertexLRT(vtx) {
      this->children = children;
    }

    IncLRT(Symbol vtx, VertexLRT* link) : VertexLRT(vtx) {
      auto kids = new map<Symbol, VertexLRT*>();
      kids->emplace(link->vtx, link);
      this->children = kids;
    }

    bool isLeaf() {
      return this->children->empty();
    }

    bool isInclusive() {
      return true;
    }

    IncLRT() : children(new map<Symbol, VertexLRT*>()) {}

    ~IncLRT() {
      delete(children);
    }

    map<Symbol, VertexLRT*>* getChildren() {
      return this->children;
    }

    bool isCompatibleWith(LRT* that) {
      auto these = *(this->getChildren());
      auto those = *(that->getChildren());
      auto seen = new set<Symbol>();

      //these children are compatible with that's
      for (auto &lc: these) {
        auto key = lc.first;
        LRT* tree = lc.second;
        auto rcIter = those.find(key);
        if (rcIter != these.end()) {
          auto rc = rcIter->second;
          if (!tree->isCompatibleWith(rc)) {
            return false;
          } else {
            seen->insert(key);
          }
        }
      }
      //that's children are compatible with these
      for (auto &rc: those) {
        if (!seen->count(rc.first)) {
          auto key = rc.first;
          LRT* tree = rc.second;
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

    bool operator <(LRT& r) {
    }

    bool proves(LRT* q) {
    }

    LRT* query(LRT* q) {
    }

    void assert(LRT* assertion) {
    }

    void retract(LRT* retraction) {
    }
};

#endif
