#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int optimal_weight(int W, const vector<int> &w, int n) {
  vector<vector<int>> d(n+1, vector<int>(W+1,0));
  for(int i=1; i<=n; i++){
    for(int j=0; j<=W; j++){
      if(w[i-1] <= j){
        d[i][j] = max(d[i-1][j], d[i-1][j-w[i-1]]+w[i-1]);
      }
      else{
        d[i][j] = d[i-1][j];
      }
    }
  }
  // int current_weight = 0;
  // for (size_t i = 0; i < w.size(); ++i) {
  //   if (current_weight + w[i] <= W) {
  //     current_weight += w[i];
  //   }
  // }
  // return current_weight;
  return d[n][W];
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w, n) << '\n';
}
