#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef map<char, int> edges; 
typedef vector<edges> trie;

struct Node{
  map<char, pair<int,int>> children;
};

void compressNode(const trie& t, const string& text, vector<Node>& suffixTree, int node, int parent, int start) {
  if (t[node].size() == 1) {
    auto it = t[node].begin();
    compressNode(t, text, suffixTree, it->second, parent, start);
  } 
  else {
    for (auto& edge : t[node]) {
      int child = edge.second;
      int edgeStart = start;
      int edgeLength = 1;
      while (t[child].size() == 1) {
        auto it = t[child].begin();
        child = it->second;
        edgeLength++;
      }
      suffixTree[parent].children[edge.first] = {edgeStart, edgeLength};
      suffixTree.resize(max(suffixTree.size(), (size_t)(child + 1)));
      compressNode(t, text, suffixTree, child, child, start + edgeLength);
    }
  }
}

void extractEdge(const vector<Node>& suffixTree, const string& text, vector<string>& result, int node) {
  for (const auto& child : suffixTree[node].children) {
    int start = child.second.first;
    int length = child.second.second;
    result.push_back(text.substr(start, length));
    extractEdge(suffixTree, text, result, node + length);
  }
}

vector<string> ComputeSuffixTreeEdges(const string& text) {
  vector<string> result;
  int n = text.size();

  //Making the suffixes into a vector
  vector<string> patterns;
  for(size_t i=0; i<n; i++){
    patterns.push_back(text.substr(i));
  }
   
  //Making the text suffix trie
  trie t;
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

  

  vector<Node> suffixTree(1); // start with root node
  compressNode(t, text, suffixTree, 0, 0, 0);
  extractEdge(suffixTree, text, result, 0);
  return result;
}

int main() {
  string text;
  cin >> text;
  text += '$';
  vector<string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}
