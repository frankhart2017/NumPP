#ifndef NUMPP_H
#define NUMPP_H

#include <vector>
#include<string>
using namespace std;

template <class T>
class numpp {
  private:
    vector<int> dim;
    vector<T> data;
    bool is_zero;
    long long int ndim;
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
    void add(numpp,numpp);
    void sub(numpp,numpp);
    void search(T, string);
    void sort(string);
    void random_normal(double, double);
    void random_uniform(double, double);
};

#endif
