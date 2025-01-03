#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

int partition3(vector<int> &a, int l, int r, int &less, int &more){
  int x = a[l];
  int eq = l;
  int lt = l;
  int gt = r; 
  int i = l+1;
  while(i<=gt){
    if(a[i] < x){
      swap(a[i], a[lt]);
      lt++;
      i++;
    }
    else if(a[i]>x){
      swap(a[i], a[gt]);
      gt--;
    }
    else{
      i++;
    }

  }

  less = lt -1;
  more = gt + 1;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  int j = r - rand() % (r - l + 1);
  swap(a[r], a[j]);
  swap(a[l], a[k]);
  int m1 = l;
  int m2 = r;
  partition3(a,l,r,m1,m2);
  randomized_quick_sort(a, l, m1);
  randomized_quick_sort(a, m2, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
