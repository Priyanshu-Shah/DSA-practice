#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int remaining = n;
  int cnt = 1;
  while(remaining > 0){
    if(remaining-cnt > cnt || remaining-cnt == 0){
      summands.push_back(cnt);
      remaining -= cnt;
      cnt++;
    }
    else{
      summands.push_back(remaining);
      remaining = 0;
    }
  }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
