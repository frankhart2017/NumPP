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

template <class T>
void numpp<T>::reshape(vector<int> new_dim) {
  this->ndim = 1;
  int new_ndim = 1;
  for(int i=0; i<this->dim.size(); i++)
    this->ndim *= this->dim[i];
  for(int i=0; i<new_dim.size(); i++)
    new_ndim *= new_dim[i];

  if(this->ndim == new_ndim) {
    cout<<"New dimensions: ";
    cout<<"{ ";
    for(int i=0; i<new_dim.size()-1; i++)
      cout<<new_dim[i]<<", ";
    cout<<new_dim[new_dim.size() - 1]<<" }";
  } else
    cerr<<"\033[1;31m Error\033[0m: Invalid dimensions!";
}
