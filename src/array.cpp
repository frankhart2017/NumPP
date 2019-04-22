#include <algorithm>
#include <iostream>
#include <typeinfo>

#include "../includes/array.hpp"

template <typename T>
Array<T>::Array(int n) {
  this->size = n;
  this->arr.reserve(n);
  this->dtp = typeid(T).name();
  for(int i=0; i<this->size; i++)
    this->arr[i] = 0;
}

template <typename T>
int Array<T>::shape() {
  return this->size;
}

template <typename T>
std::string Array<T>::dtype() {
  return this->dtp;
}

template <typename T>
void Array<T>::show() {
  std::cout<<"NP Arr([";
  for(int i=0; i<this->size-1; i++) {
    std::cout<<this->arr[i]<<",";
  }
  std::cout<<this->arr[this->size-1]<<"])";
}
