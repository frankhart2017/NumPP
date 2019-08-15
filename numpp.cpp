#include <iostream>
#include <typeinfo>
#include <map>

#include "numpp.hpp"

using namespace std;

template <class T>
int numpp<T>::shape_match(vector<int> dim) {
  if(this->dim.size() == dim.size()) {
    for(int i=0; i<this->dim.size(); i++)
      if(this->dim[i] < dim[i])
        return 0;
    return 1;
  }

  return 0;
}

template <class T>
numpp<T>::numpp(vector<int> dim) {
  this->dim = dim;
  this->ndim = 1;
  for(int i=0; i<this->dim.size(); i++)
    this->ndim *= this->dim[i];
  try {
    T *a = new T[this->ndim];
    delete[] a;
  } catch(bad_alloc&) {
    cerr<<"\033[1;31m Error\033[0m: Memory out of bounds!";
  }
}

template <class T>
void numpp<T>::shape() {
  cout<<"{ ";
  for(int i=0; i<this->dim.size()-1; i++)
    cout<<this->dim[i]<<", ";
  cout<<this->dim[this->dim.size() - 1]<<" }";

}

template <class T>
void numpp<T>::add(numpp np1,numpp np2){
	cout<<endl;
   for(int i=0;i<this->dim.size()*dim.size();i++)
   {
   	this->data[i]=np1.data[i]+np2.data[i];
   	cout<<this->data[i]<<" ";
   }
}
template <class T>
void numpp<T>::sub(numpp np1,numpp np2){
	cout<<endl;
   for(int i=0;i<this->dim.size()*dim.size();i++)
   {
   	this->data[i]=np1.data[i]-np2.data[i];
   	cout<<this->data[i]<<" ";
   }
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

template <class T>
void numpp<T>::push_vec(vector<int> dim, vector<T> data) {
  if(shape_match(dim)) {
    this->ndim = 1;
    for(int i=0; i<dim.size(); i++)
      this->ndim *= dim[i];
    if(data.size() == this->ndim)
      this->data = data;
    else
      cerr<<"\033[1;31m Error\033[0m: Dimension doesn't match declared numpp dimension!\n";
  }
  else
    cerr<<"\033[1;31m Error\033[0m: Dimension doesn't match declared numpp dimension!\n";
}
