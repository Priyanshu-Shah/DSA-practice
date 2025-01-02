#include <iostream>
#include <vector>

using namespace std;

void explore(vector<vector<int> > &adj, vector<bool> &visited, int i){
  visited[i] = true;
  for(int j : adj[i]){
    if(visited[j] != true){
      explore(adj, visited, j);
    }
  }
}

int number_of_components(vector<vector<int> > &adj) {
  int res = 0;
  vector<bool> visited(adj.size(), false);
  for(int i=0; i<adj.size(); i++){
    if(!visited[i]){
      explore(adj, visited,i);
      res++;
    }
  }
  return res;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  cout << number_of_components(adj);
}
