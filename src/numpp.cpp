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
  is_zero = false;
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
  if(shape_match(dim))
    this->data = data;
  else
    cerr<<"\033[1;31m Error\033[0m: Dimension doesn't match declared numpp dimension!";
}


template <class T>
long long int numpp<T>::max() {
  long long int maximum=data[0];
  long i=1;
  while(i!=ndim)
  {
    if(data[i]>maximum)
     maximum=data[i++];
  }
  return maximum;

}

template <class T>
long long int numpp<T>::min() {
  long long int minimum=data[0];
  long i=1;
  while(i!=ndim)
  {
    if(data[i]<minimum)
     minimum=data[i];

     i++;
  }
  return minimum;

}

template <class T>
void numpp<T>::zeros() {
 is_zero = true;
}

template <class T>
void numpp<T>::print() {
 long i=1;
 cout<<endl;
 if(is_zero) {
   cout<<"{";
   i--;
    while(i != ndim-1) {
      cout<<"0, ";
      i++;
    }
    cout<<"0}";
  } else {
   cout<<"{ "<<data[0];
   if(ndim==1)
   cout<<" }";
   else
   {
      while(i!=ndim)
   {
     cout<<", "<<data[i++];
   }
   cout<<" }";
   }
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
