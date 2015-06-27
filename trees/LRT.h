#ifndef __LRT_H_
#define __LRT_H_

#include <utility>
#include <map>

using std::map;

template <class T> class LRT {
  public:
    virtual bool proves(LRT *hypothesis) { //NOT IMPLEMENTED
      return false;
    }

    virtual bool isLeaf();

    virtual bool isInclusive();

    bool isExclusive();

    virtual map<T, LRT>* getChildren() =0;

//    virtual bool isCompatibleWith(LRT* that) =0;
//
//    virtual LRT* query(LRT* q) =0;
//
//    virtual void assert(LRT* assertion) =0;
//
//    virtual void retract(LRT* retraction) =0;
};

#endif //__LabeledRootedTree_H_
