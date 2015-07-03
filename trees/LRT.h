#ifndef __LRT_H_
#define __LRT_H_

#include <utility>
#include <map>

using std::map;

template <typename T> class VertexLRT;

template <typename T> class LRT {
  public:
    virtual bool proves(LRT* hypothesis) {
      return false;
    }
    
    virtual map<T, VertexLRT<T>*>* getChildren() = 0;

    virtual bool isLeaf() = 0;

    virtual bool isInclusive() = 0;

    virtual bool isExclusive() {
      return !isInclusive();
    }

    virtual bool isCompatibleWith(LRT* that) = 0;
//
//    virtual LRT* query(LRT* q) =0;
//
//    virtual void assert(LRT* assertion) =0;
//
//    virtual void retract(LRT* retraction) =0;
};

#endif
