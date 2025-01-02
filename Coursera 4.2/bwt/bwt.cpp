//Linear time algo

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string BWT(const string& text) {
  int n = text.size();
  vector<string> rot(n);
  for(int i=0; i<n; i++){
    rot[i] += text.substr(i) + text.substr(0,i);
  }

  sort(rot.begin(), rot.end());

  string result;
  for(int i=0; i<n; i++){
    result += rot[i][n-1];
  }
  return result;
}

int main() {
  string text;
  cin >> text;
  string result;
  result.resize(text.size());
  result = BWT(text);
  cout << result << endl;
  return 0;
}