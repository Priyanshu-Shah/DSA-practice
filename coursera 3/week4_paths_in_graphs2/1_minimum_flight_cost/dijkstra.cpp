#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  int n = adj.size();
  vector<long long> dist(n, LLONG_MAX);
  dist[s] = 0;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push({0,s});
  while(!pq.empty()){
    long long d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    for(size_t i = 0; i<adj[u].size(); i++){
      int v = adj[u][i];
      if(dist[v] > dist[u] + cost[u][i]){
        dist[v] = dist[u]+cost[u][i];
        pq.push({dist[v], v});
      }
    }
  }
  return (dist[t] == LLONG_MAX ? -1 : dist[t]);
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
  cout << distance(adj, cost, s, t);
}
