#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void explore(vector<vector<int> > &adj, vector<bool> &visited, vector<int> &order, int v) {
  visited[v] = true;
  for(int u: adj[v]){
    if(!visited[u]){
      explore(adj, visited, order, u);
    }
  }
  order.push_back(v);
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<bool> visited(adj.size(), false);
  vector<int> order;
  int n = adj.size();
  for(int i=0; i<n; i++){
    if(!visited[i]){
      explore(adj, visited, order, i);
    }
  }
  reverse(order.begin(), order.end());
  return order;
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
  vector<int> order = toposort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    cout << order[i] + 1 << " ";
  }
}
