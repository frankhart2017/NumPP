#include <iostream>
#include <vector>

#include <chrono>

#include "numpp.cpp"

using namespace std;

using namespace std::chrono;

int main() {

  numpp<int> np({2, 2});
  np.max();
  auto start = high_resolution_clock::now();

  np.push_vec({2, 2}, {1, 2, 3, 4});
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  cout<<duration.count()<<endl;

  np.shape();
  cout<<endl;
}
