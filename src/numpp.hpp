#ifndef NUMPP_H
#define NUMPP_H

#include <vector>

using namespace std;

template <class T>
class numpp {
  private:
    vector<int> dim;
    vector<T> data;
    int ndim;
  public:
    numpp(vector<int>);
    void shape();
    void reshape(vector<int>);
};

#endif
