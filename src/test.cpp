#include <iostream>
#include <vector>

#include <chrono>

#include "numpp.cpp"

using namespace std;

using namespace std::chrono;

int main() {

  numpp<int> np({2, 2});

  np.push_vec({2, 2}, {1, 2, 3, 4});
  np.print();

  np.random_normal(2, 6);
  np.print();

  np.random_uniform(2, 6);
  np.print();

  np.shape();
  cout<<endl;
}
