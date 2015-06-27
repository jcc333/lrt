#ifndef __ExcLRT_H_
#define __ExcLRT_H_

#include "LRT.h"
#include "VertexLRT.h"

template <typename T> class ExcLRT : public VertexLRT<T> {
  private:
    LRT<T>* child;

  public:
    ExcLRT(T vtx, LRT<T>* child);

    ~ExcLRT();

    map<T, LRT<T>>* getChildren();

    LRT<T>* getChild();

    bool isInclusive();

    bool isCompatibleWith(LRT<T> *that);

    LRT<T>* query(LRT<T>* q) {
      return this;
    }

    void assert(LRT<T>* prop) {
    }
    
    void retract(LRT<T>* prop) {
    }
};

#endif //__ExcLRT_H_
