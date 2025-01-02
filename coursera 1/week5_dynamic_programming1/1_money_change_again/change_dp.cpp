#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>  

using namespace std;

int get_change(int m) {
  vector<int> mini(m+1, INT_MAX);
  vector<int> coins = {1,3,4};
  mini[0] = 0;
  for(int i=1; i<m+1; i++){
    for(int j=0; j<3; j++){
      int c = coins[j];
      if(i >= c && mini[i-c] != INT_MAX){
        mini[i] = min(mini[i], mini[i-c]+1);
      }
    }
  }
  return mini[m];
}

int main(){
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
  return 0;
}
