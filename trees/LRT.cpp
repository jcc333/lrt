#include "LRT.h"
    
bool LRT::isLeaf() {
  return ! this->getChildren()->empty();
}

bool LRT::isInclusive() {
  return true; 
}

bool LRT::isExclusive() {
  return !isInclusive();
}
