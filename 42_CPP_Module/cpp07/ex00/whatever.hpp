#ifndef _WHATEVER_HPP
#define _WHATEVER_HPP
#include <iostream>
#include <string>

template <typename T>
void swap(T& arg1, T& arg2){
  T temp;
  temp = arg1;
  arg1 = arg2;
  arg2 = temp;
}

template <typename T>
T min(T arg1, T arg2){
  if (arg1 < arg2)
    return arg1;
  return arg2;
}

template <typename T>
T max(T arg1, T arg2){
  if (arg1 > arg2)
    return arg1;
  return arg2;
}



#endif