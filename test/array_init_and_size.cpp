#include <iostream>

#include "../src/array.cpp"

using namespace std;

int main() {
  Array<float> num(10);
  cout<<num.shape()<<endl;
  cout<<num.dtype()<<endl;
  num.show();
  cout<<endl;
}
