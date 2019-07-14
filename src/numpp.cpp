#include <iostream>

#include "numpp.hpp"

using namespace std;

template <class T>
numpp<T>::numpp(vector<int> dim) {
  this->dim = dim;
}

template <class T>
void numpp<T>::shape() {
  cout<<"{ ";
  for(int i=0; i<this->dim.size()-1; i++)
    cout<<this->dim[i]<<", ";
  cout<<this->dim[this->dim.size() - 1]<<" }";
}
