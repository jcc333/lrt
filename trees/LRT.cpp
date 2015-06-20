//
// Created by James Clemer on 5/17/15.
// Copyright (c) 2015 clem. All rights reserved.
//

#include "LRT.h"
template <typename T>
LRT<T> Lib::root(map<T, LRT<T>>* children) {
  return new Root<T>(children);
}

template <typename T>
LRT<T> Lib::root() {
  return new Root();
}

template <typename T>
LRT<T> Lib::inc(T t, map<T, LRT<T>>* children) {
  return new IncLRT<T>(t, children);
}

template <typename T>
LRT<T> Lib::exc(T t, LRT<T> child) {
  return new ExcLRT<T>(t, child);
}

template <typename T>
LRT<T> Lib::leaf(T t) {
  return new IncLRT<T>(t);
}
