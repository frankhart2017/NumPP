#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>
#include <iterator>

#include <chrono>

using namespace std;

using namespace std::chrono;

template <class T>
class nparr {
  private:
    string dim;
    vector<int> dimensions;
    vector<vector<int> > partitions;

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

  public:
    int npp_arr_size = 1;

    nparr(string s) {
      dim = s;

      string::iterator end_pos = remove(dim.begin(), dim.end(), ' ');
      dim.erase(end_pos, dim.end());

      dimensions = split_string(dim);
      dimensions.push_back(1);

      for(int i=0; i<dimensions.size(); i++)
        npp_arr_size *= dimensions[i];

      vector<int> mul_vector = mul_ret(dimensions);

      for(int i=1; i<mul_vector.size(); i++)
        partitions.push_back(partitioning(npp_arr_size, mul_vector[i]));
    }
};

int main() {
  nparr<double> np("100, 100");

  return 0;
}
