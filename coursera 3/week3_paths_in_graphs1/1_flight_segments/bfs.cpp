#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int distance(vector<vector<int> > &adj, int s, int t) {
  int n = adj.size();
  vector<int> dist(n,INT_MAX);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v: adj[u]){
      if(dist[v]==INT_MAX){
        q.push(v);
        dist[v] = dist[u] + 1;
      }
    }
  }
  return dist[t] == INT_MAX ? -1 : dist[t];
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
  int s, t;
  cin >> s >> t;
  s--, t--;
  cout << distance(adj, s, t);
}
