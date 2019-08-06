#ifndef NUMPP_H
#define NUMPP_H

#include <vector>

using namespace std;

template <class T>
class numpp {
  private:
    vector<int> dim;
    vector<T> data;
    unsigned long long int ndim;
    int shape_match(vector<int>);
  public:
    numpp(vector<int>);
    void shape();
    void reshape(vector<int>);
    void push_vec(vector<int>, vector<T>);
    void max();
};

#endif
