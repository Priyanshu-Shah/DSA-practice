#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> dynamic_sequence(int n){
  vector<int> count(n+1);
  vector<int> sequence;
  vector<int> previous(n+1);
  count[1] = 0;
  for(int i=2; i<n+1; i++){
    count[i] = count[i-1]+1;
    previous[i] = i-1;
    if(i % 2 == 0){
      if(count[i] > count[i / 2] + 1){
        count[i] = count[i / 2] + 1;
        previous[i] = i / 2;
      }
    }
    if(i % 3 == 0){
      if(count[i] > count[i / 3] + 1){
        count[i] = count[i / 3] + 1;
        previous[i] = i / 3;
      }
    }
  }
  for(int i=n; i!=0; i=previous[i]){
    sequence.push_back(i);
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  cin >> n;
  vector<int> sequence = dynamic_sequence(n);
  cout << sequence.size() - 1 << endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    cout << sequence[i] << " ";
  }
  cout << endl;
  return 0;
}
