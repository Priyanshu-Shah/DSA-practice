#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> SortCharacters(const string &text){
  int n = text.size();
  const int m = 256;
  vector<int> order(n);
  vector<int> count(m,0);
  for(int i=0; i<n; i++){
    count[text[i]]++;
  }
  for(int j=1; j<m; j++){
    count[j] += count[j-1];
  }
  for(int i=n-1; i>=0; i--){
    char c = text[i];
    count[c]--;
    order[count[c]] = i;
  }
  return order;
}

vector<int> ComputeCharClasses(const string &text, vector<int> order){
  int n = text.size();
  vector<int> classs(n);
  classs[order[0]] = 0;
  for(int i=1; i<n; i++){
    if(text[order[i]] != text[order[i-1]]){
      classs[order[i]] = classs[order[i-1]]+1;
    }
    else{
      classs[order[i]] = classs[order[i-1]];
    }
  }
  return classs;
}

vector<int> SortDoubled(const string &text, int l, vector<int> order, vector<int> classs){
  int n = text.size();
  vector<int> count(n,0);
  vector<int> newOrder(n);
  for(int i=0; i<n; i++){
    count[classs[i]]++;
  }
  for(int j=1; j<n; j++){
    count[j]+=count[j-1];
  }
  for(int i=n-1; i>=0; i--){
    int start = (order[i]-l+n)%n;
    int cl = classs[start];
    count[cl]--;
    newOrder[count[cl]] = start;
  }
  return newOrder;
}

vector<int> UpdateClasses(vector<int> order, vector<int> classs, int l){
  int n = order.size();
  vector<int> newClass(n);
  newClass[order[0]] = 0;
  for(int i=1; i<n; i++){
    int cur = order[i];
    int prev = order[i-1];
    int mid = cur + l;
    int midPrev = (prev + l)%n;
    if((classs[cur] != classs[prev]) || classs[mid]!=classs[midPrev]){
      newClass[cur] = newClass[prev]+1;
    }
    else{
      newClass[cur] = newClass[prev];
    }
  }
  return newClass;
}

vector<int> BuildSuffixArray(const string& text) {
  int n = text.size();
  vector <int> order(n,0);
  vector<int> classs(n,0);
  order = SortCharacters(text);
  classs = ComputeCharClasses(text, order);
  int l = 1;
  while(l < n){
    order = SortDoubled(text, l, order, classs);
    classs = UpdateClasses(order, classs, l);
    l = 2*l;
  }
  return order;
}

int main() {
  string text;
  cin >> text;
  vector<int> suffix_array = BuildSuffixArray(text);
  for (int i = 0; i < suffix_array.size(); ++i) {
    cout << suffix_array[i] << ' ';
  }
  cout << endl;
  return 0;
}
