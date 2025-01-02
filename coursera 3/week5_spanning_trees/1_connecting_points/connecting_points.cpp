#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <limits>

using namespace std;

struct coordinate{
  int x,y;
};

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  int n = x.size();
  vector<bool> visited(n,false);
  vector<double> dist(n, numeric_limits<double>::max());
  dist[0] = 0.;
  priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
  pq.push({0.0,0});
  while(!pq.empty()){
    int u = pq.top().second;
    double distance = pq.top().first;
    pq.pop();
    if(!visited[u]){
      visited[u] = true;
      result += distance;
    }
    for(int v=0; v<n; v++){
      if(!visited[v]){
        double length = sqrt(pow(x[u]-x[v],2) + pow(y[u]-y[v], 2));
        if(length < dist[v]){
          dist[v] = length;
          pq.push({length, v});
        }
      }
    }
  }
  return result;
}  

int main() {
  size_t n;
  cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cout << fixed << setprecision(10) << minimum_distance(x, y) << endl;
  return 0;
}

