#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x, int l, int r) {
    if (l > r){
      return -1;
    }
    int mid = l + ((r - l)/2);
    if (x == a[mid]){
      while(mid - 1 >= 0 && a[mid - 1] == x){
        mid--;
      }
      return mid;
    } 
    else if(x > a[mid]){
      return binary_search(a, x, mid + 1, r);
    } 
    else{
      return binary_search(a, x, l, mid - 1);
    }
}


int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    int l = 0;
    int r = n-1;
    std::cout << binary_search(a, b[i], l ,r) << ' ';
  }
}
