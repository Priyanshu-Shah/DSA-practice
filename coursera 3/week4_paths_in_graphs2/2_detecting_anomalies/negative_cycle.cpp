#include <iostream>
#include <vector>
#include <climits>

using std::vector;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
  int n = adj.size();
  vector<long long> dist(n, LLONG_MAX);
  vector<int> prev(n,-1);
  dist[0] = 0;
  int x = -1;
  for(int j=0; j<n; j++){
    x=-1;
    for(int u=0; u<n; u++){
      if(dist[u] != LLONG_MAX){
        for(size_t i = 0; i<adj[u].size(); i++){
          int v = adj[u][i];
          if (dist[u] != LLONG_MAX && dist[v] > dist[u] + cost[u][i]) {
            dist[v] = dist[u] + cost[u][i];
            x = v;
          }
        }
      }
    }
  }
  if(x==-1){
    return 0;
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
