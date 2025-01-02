#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef map<char, int> edges; 
typedef vector<edges> trie; //Each element of vector is a layer/depth of the trie and each layer is denoted as a map of chacaters and its index

trie build_trie(vector<string> & patterns) {
  trie t;
  vector<int> neww; 
  t.push_back(edges());

  for(string pattern : patterns){
    int starting_node = 0;
    for(char c: pattern){
      if(t[starting_node].find(c) != t[starting_node].end()){ //Because the find method returns either the iterator of found key, or it return itrator of element past the last element (accessed by end() method)
        starting_node = t[starting_node][c]; //If already present then next node is the index at that symbols stored map
      }
      else{
        t[starting_node].insert({c,t.size()});
        starting_node = t.size();
        t.push_back(edges());
      }
    }
  }
  return t;
}

int main() {
  size_t n;
  cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++) {
    string s;
    cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i) {
    for (const auto & j : t[i]) {
      cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}