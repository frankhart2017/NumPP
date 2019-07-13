#include <iostream>
#include <vector>

#include <chrono>

#include "numpp.cpp"

using namespace std;

using namespace std::chrono;

int main() {
  auto start = high_resolution_clock::now();
  numpp<int> np({100,100,100,100,100,100,100,100,100,100,100,100,100});
  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<nanoseconds>(stop - start);

  cout<<duration.count()<<endl;
}
