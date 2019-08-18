#include <iostream>
#include <typeinfo>
#include <map>
#include <random>

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
long long int numpp<T>::max() {
  if(this->data.empty())
  {
    cerr<<"\033[1;31m Error\033[0m: Empty array!\n";
    return 0;
  }
  else
  {
  
  long long int maximum=data[0];
  long i=1;
  while(i!=ndim)
  {
    if(data[i]>maximum)
     maximum=data[i++];
  }
  return maximum;
  }
}

template <class T>
long long int numpp<T>::min() {
  if(this->data.empty())
  {
    cerr<<"\033[1;31m Error\033[0m: Empty array!\n";
    return 0;

  }
  else
  {
  
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
      while(i!=ndim)
        cout<<", "<<data[i++];
   cout<<" }";
   }
  cout<<endl;
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
void numpp<T>::search(T a, string ch) {
  if(ch == "linear") {
    int count=0;
    for(int i=0; i<ndim; i++)
      if(a == data[i])
        count++;

    if(count == 0)
      cout<<a<<" not found!";
    else
      cout<<a<<" found!";
  } else if(ch == "binary") {
    int i, j;
    T temp;
    for (i = 0; i < ndim-1; i++) {
      for (j = 0; j < ndim-i-1; j++) {
        if (data[j] > data[j+1]) {
          temp=data[j];
          data[j]=data[j+1];
          data[j+1]=temp;
        }
      }
    }
    int count=0;
    int start, end, middle;
    start=0;
    end=ndim-1;
    for(int i=0;i<ndim;i++) {
      middle=(start+end)/2;
      if(a==data[middle])
        count++;
      else if(a>data[middle])
        start=middle+1;
      else
        end=middle-1;
    }
    if(count>0)
      cout<<a<<" found!";
    else
      cout<<a<<" not found!";
  }
}

template <class T>
void numpp<T>::sort(string ch) {
  if(ch=="Bubble") {
    int i, j;
    T temp;
    for (i = 0; i < ndim-1; i++) {
      for (j = 0; j < ndim-i-1; j++) {
        if (data[j] > data[j+1]) {
          temp=data[j];
          data[j]=data[j+1];
          data[j+1]=temp;
        }
      }
    }
  } else if(ch=="Insertion") {
    int i, j;
    T key;
    for (i = 1; i < ndim; i++) {
      key = data[i];
      j = i - 1;
      while (j >= 0 && data[j] > key) {
        data[j + 1] = data[j];
        j = j - 1;
      }
      data[j + 1] = key;
    }
  } else if(ch=="Selection") {
    int i, j, min_idx;
    T temp;

    for (i = 0; i < ndim-1; i++) {
      min_idx = i;
      for (j = i+1; j < ndim; j++)
      if (data[j] < data[min_idx])
        min_idx = j;
      temp=data[min_idx];
      data[min_idx]=data[i];
      data[i]=temp;
    }
    for(i=0;i<ndim;i++)
      cout<<data[i];
    }
 }

 template <class T>
 void numpp<T>::random_normal(double mean, double stddev) {
   default_random_engine generator;
   normal_distribution<double> distribution(mean, stddev);
   this->data.clear();
   for(int i=0; i<this->ndim; i++)
     this->data.push_back(distribution(generator));
 }

 template <class T>
 void numpp<T>::random_uniform(double mean, double stddev) {
   default_random_engine generator;
   uniform_real_distribution<double> distribution(mean, stddev);
   this->data.clear();
   for(int i=0; i<this->ndim; i++)
    this->data.push_back(distribution(generator));
 }
