#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;



double clustering(vector<int> x, vector<int> y, int k) {
  
  return -1.;
} 

int main() {
  size_t n;
  int k;
  cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cin >> k;
  cout << setprecision(10) << clustering(x, y, k) << endl;
}

