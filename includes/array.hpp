#include <string>
#include <vector>

template <typename T>
class Array {
private:
  std::string dtp;
  int size;
  std::vector<T> arr;
public:
  Array(int n);

  int shape();
  std::string dtype();
  void show();
};
