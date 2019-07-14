#include <iostream>
#include <vector>

#include <chrono>

#include "numpp.cpp"

using namespace std;

using namespace std::chrono;

int main() {

  numpp<int> np({100,100,100,100,100,100,100,100,100,100,100,100,100});

  np.shape();

  cout<<endl;
}
