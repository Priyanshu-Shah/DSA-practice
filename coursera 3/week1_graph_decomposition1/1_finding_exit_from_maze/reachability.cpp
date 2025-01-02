#include <iostream>
#include <vector>

using namespace std;

int reach(vector<vector<int> > &adj, int x, int y, vector<bool>&visited) {
  if(x==y){
    return 1;
  }
  visited[x] = true;
  for(int i=0; i<adj[x].size(); i++){
    if(!visited[adj[x][i]] && reach(adj,adj[x][i], y, visited)){
      return 1;
    }
  }
  
  return 0;
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
  int x, y;
  cin >> x >> y;
  vector<bool> visited(n,false);
  cout << reach(adj, x - 1, y - 1, visited);
}
