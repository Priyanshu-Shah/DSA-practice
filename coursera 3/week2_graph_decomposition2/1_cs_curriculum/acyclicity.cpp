#include <iostream>
#include <vector>

using namespace std;

bool explore(vector<vector<int> > &adj, vector <bool> &visited, vector<bool>&rec, int v){
  visited[v] = true;
  rec[v] = true;
  for(int u:adj[v]){
    if(!visited[u] && explore(adj, visited, rec, u)){
      return true;
    }
    else if(rec[u]){
      return true;
    }
  } 
  rec[v] = false;
  return false;
}

int acyclic(vector<vector<int> > &adj) {
  int n = adj.size();
  vector<bool> check(n, false);
  vector<bool> rec(n,-1);
  for(int i=0; i<n; i++){
    if(!check[i]){
      if(explore(adj, check, rec, i)){
        return 1;
      }
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
  }
  cout << acyclic(adj);
}
