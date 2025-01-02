#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bipartite(vector<vector<int> > &adj) {
  int n = adj.size();
  vector<int> type(n,-1);
  for(int i=0; i<n; i++){
    if(type[i] == -1){
      queue<int> q;
      q.push(i);
      type[i] = 0;
      while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
          if(type[v] == -1){
            type[v] = 1-type[u];
            q.push(v);
          }
          else if(type[v] == type[u]){
            return 0;
          }
        }
      }
    }
  }
  return 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  cout << bipartite(adj);
}
