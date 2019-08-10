#ifndef NUMPP_H
#define NUMPP_H

#include <vector>

using namespace std;

template <class T>
class numpp {
  private:
    vector<int> dim;
    int ndim;
    int shape_match(vector<int>);
  public:
    numpp(vector<int>);
    vector<T> data;
    void shape();
    void reshape(vector<int>);
    void push_vec(vector<int>, vector<T>);
    void add(vector<T>);
    void sub(vector<T>);
    
};

#endif
