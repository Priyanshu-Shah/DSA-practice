#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.size();
  int m = str2.size();
  vector<vector<int>> d(n+1, vector<int>(m+1));
  for(int i=0; i<=n; i++){
    d[i][0] = i;
  }
  for(int j=0; j<=m; j++){
    d[0][j] = j;
  }
  for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= m; ++j){
        int insertion = d[i][j - 1] + 1;
        int deletion = d[i - 1][j] + 1;
        int match = d[i - 1][j - 1];
        int mismatch = d[i - 1][j - 1] + 1;
        if(str1[i - 1] == str2[j - 1]){
          d[i][j] = min({insertion, deletion, match});
        } 
        else{
          d[i][j] = min({insertion, deletion, mismatch});
        }
      }
    }
  return d[n][m];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
