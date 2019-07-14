#include <iostream>
#include <vector>

#include <chrono>

#include "numpp.cpp"

using namespace std;

using namespace std::chrono;

int main() {

  numpp<int> np({2, 2, 3});

  np.shape();
  cout<<endl;
  np.reshape({3, 4});

  cout<<endl;
}
