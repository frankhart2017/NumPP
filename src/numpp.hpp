#ifndef NUMPP_H
#define NUMPP_H

#include <vector>

using namespace std;

template <class T>
class numpp {
  private:
    vector<int> dim;
    vector<T> data;
    bool is_zero;
    uint64_t ndim;
    int shape_match(vector<int>);
  public:
    numpp(vector<int>);
    void shape();
    void reshape(vector<int>);
    void push_vec(vector<int>, vector<T>);
    long long int max();
    long long int min();
    void zeros();
    void print();
};

#endif
