#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> ComputePrefixFunction(const string &S){
  int n = S.size();
  vector<int> s(n,-1);
  s[0] = 0;
  int border = 0;
  for(int i=1; i<n; i++){
    while(border > 0 && S[i]!=S[border]){
      border = s[border-1];
    }
    if(S[i]==S[border]){
      border += 1 ;
    }
    else{
      border = 0;
    }
    s[i] = border;
  }
  return s;
}

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where 
// the pattern starts in the text.
vector<int> find_pattern(const string& pattern, const string& text) {
  vector<int> result;
  string S = pattern + "$" + text;
  vector<int> s = ComputePrefixFunction(S);
  int p = pattern.size();
  int n = S.size();
  for(int i = p+1; i<n; i++){
    if(s[i] == p){
      result.push_back(i-(2*p));
    }
  }
  return result;
}

int main() {
  string pattern, text;
  cin >> pattern;
  cin >> text;
  vector<int> result = find_pattern(pattern, text);
  for (int i = 0; i < result.size(); ++i) {
    printf("%d ", result[i]);
  }
  printf("\n");
  return 0;
}
