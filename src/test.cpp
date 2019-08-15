#include <iostream>
#include <vector>

#include <chrono>

#include "numpp.cpp"

using namespace std;

using namespace std::chrono;

int main() {

  numpp<int> np({3, 3});

  auto start = high_resolution_clock::now();

  np.push_vec({3, 3}, {5, 2, 7, 5, 1, 8, 9, 4, 2});

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  cout<<duration.count()<<endl;

  np.shape();
  np.search(5,"Binary");
  np.sort("Selection");
  


  cout<<endl;
}
