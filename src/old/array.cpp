#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <iterator>

#include <chrono>

using namespace std;

using namespace std::chrono;

vector<int> split_string(string s) {
  vector<int> ret_vec;
  string buf = "";
  int temp;
  for(int i=0; i<s.length(); i++) {
    if(s[i] == ',') {
      stringstream int_str(buf);
      int_str >> temp;
      ret_vec.push_back(temp);
      buf = "";
      continue;
    }
    buf += s[i];
  }

  stringstream int_str(buf);
  int_str >> temp;
  ret_vec.push_back(temp);

  return ret_vec;
}

vector<int> mul_ret(vector<int> dimensions) {

  reverse(dimensions.begin(), dimensions.end());

  vector<int> ret_arr;
  int mul = 1;
  for(int i=0; i<dimensions.size(); i++) {
    mul *= dimensions[i];
    ret_arr.push_back(mul);
  }

  reverse(ret_arr.begin(), ret_arr.end());

  return ret_arr;
}

vector<int> partitioning(int size, int partition_size) {
  vector<int> ret_vec;
  for(int i=0; i<size; i++) {
    if(i%partition_size == 0)
      ret_vec.push_back(i);
  }

  return ret_vec;
}

int index(int idx, vector<int> row, int prev_dim=0) {
  int ind=0;
  //vector<int> indexing;
  int indexing;
  for(int i=0; i<row.size(); i++) {
    if(ind == prev_dim && prev_dim > 0)
      ind = 0;
    if(row[i] > idx) {
      return indexing;
    }
    if(idx == row[i]) {
      return ind;
    }
    indexing = ind;
    ind++;
  }
  return ind-1;
}

int main() {

  string s;

  cout<<"Enter the dimensions: ";
  getline(cin, s);

  auto start = high_resolution_clock::now();

  std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
  s.erase(end_pos, s.end());

  vector<int> dimensions = split_string(s);
  dimensions.push_back(1);

  int npp_arr_size = 1;

  for(int i=0; i<dimensions.size(); i++)
    npp_arr_size *= dimensions[i];

  vector<int> mul_vector = mul_ret(dimensions);

  vector<vector<int> > partitions;

  for(int i=1; i<mul_vector.size(); i++)
    partitions.push_back(partitioning(npp_arr_size, mul_vector[i]));

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout<<"Time taken for array creation and partition: "<<duration.count()<<endl;

  vector<int>().swap(mul_vector);

  vector<int> true_index;

  int mode;

  cout<<"Mode: ";
  cin>>mode;

  if(mode == 0) {
    for(int idx=0; idx<npp_arr_size; idx++) {
      cout<<idx<<"->";

      for(int i=0; i<partitions.size(); i++) {
        cout<<i<<endl;
        if(i > 0) {
          true_index.push_back(index(idx, partitions[i], dimensions[i]));
        } else {
          true_index.push_back(index(idx, partitions[i]));
        }
      }
      cout<<true_index.size()<<endl;
      for(int i=0; i<true_index.size(); i++)
        cout<<true_index[i]<<" ";
      cout<<endl;

      true_index.clear();
    }
  } else {
    int idx;
    cout<<"Enter idx: ";
    cin>>idx;

    for(int i=0; i<partitions.size(); i++) {
      if(i > 0) {
        cout<<index(idx, partitions[i], dimensions[i])<<" ";
      } else {
        cout<<index(idx, partitions[i])<<" ";
      }
    }

    for(int i=0; i<true_index.size(); i++)
      cout<<true_index[i]<<" ";
    cout<<endl;
  }

  return 0;
}
