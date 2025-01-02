// #include <iostream>
// #include <limits>
// #include <vector>
// #include <queue>

// using namespace std;

// void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
//   int n = adj.size();
//   distance[s] = 0;
//   reachable[s] = 1;

//   for (int i = 0; i < n - 1; ++i) {
//     for (int u = 0; u < n; ++u) {
//       if (distance[u] != numeric_limits<long long>::max()) {
//         for (size_t j = 0; j < adj[u].size(); ++j) {
//           int v = adj[u][j];
//           if (distance[v] > distance[u] + cost[u][j]) {
//             distance[v] = distance[u] + cost[u][j];
//             reachable[v] = 1;
//           }
//         }
//       }
//     }
//   }

//   for(int i=0; i<n; ++i){
//     for(int u=0; u<n; ++u){
//       if(distance[u]!=numeric_limits<long long>::max()){
//         for(size_t j=0; j<n; ++j){
//           int v = adj[u][j];
//           if(distance[v] > distance[u]+cost[u][j]){
//             distance[v] = distance[u] + cost[u][j];
//             reachable[v] = 1;
//             shortest[v] = 0; //meaning this vertex is part of negative cycle
//           }
//         }
//       }
//     }
//   }

//   queue<int> to_check;
//   for(int u=0; u<n; ++u){
//     if(shortest[u]==0){
//       to_check.push(u);
//     }
//   }

//   while(!to_check.empty()){
//     int u = to_check.front();
//     to_check.pop();
//     for(int v:adj[u]){
//       if(shortest[v]){
//         shortest[v] = 0;
//         to_check.push(v);
//       }
//     }
//   }
// }

// int main() {
//   int n, m, s;
//   cin >> n >> m;
//   vector<vector<int> > adj(n, vector<int>());
//   vector<vector<int> > cost(n, vector<int>());
//   for (int i = 0; i < m; i++) {
//     int x, y, w;
//     cin >> x >> y >> w;
//     adj[x - 1].push_back(y - 1);
//     cost[x - 1].push_back(w);
//   }
//   cin >> s;
//   s--;
//   vector<long long> distance(n, numeric_limits<long long>::max());
//   vector<int> reachable(n, 0);
//   vector<int> shortest(n, 1);
//   shortest_paths(adj, cost, s, distance, reachable, shortest);
//   for (int i = 0; i < n; i++) {
//     if (!reachable[i]) {
//       cout << "*\n";
//     } else if (!shortest[i]) {
//       cout << "-\n";
//     } else {
//       cout << distance[i] << "\n";
//     }
//   }
// }


#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

void shortest_paths(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
    int n = adj.size();
    distance[s] = 0;
    reachable[s] = 1;

    for (int i = 0; i < n - 1; ++i) {
        for (int u = 0; u < n; ++u) {
            if (distance[u] != numeric_limits<long long>::max()) {
                for (size_t j = 0; j < adj[u].size(); ++j) {
                    int v = adj[u][j];
                    if (distance[v] > distance[u] + cost[u][j]) {
                        distance[v] = distance[u] + cost[u][j];
                        reachable[v] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            if (distance[u] != numeric_limits<long long>::max()) {
                for (size_t j = 0; j < adj[u].size(); ++j) {
                    int v = adj[u][j];
                    if (distance[v] > distance[u] + cost[u][j]) {
                        distance[v] = distance[u] + cost[u][j];
                        reachable[v] = 1;
                        shortest[v] = 0; 
                    }
                }
            }
        }
    }

    queue<int> to_check;
    for (int u = 0; u < n; ++u) {
        if (shortest[u] == 0) {
            to_check.push(u);
        }
    }

    while (!to_check.empty()) {
        int u = to_check.front();
        to_check.pop();
        for (int v : adj[u]) {
            if (shortest[v]) {
                shortest[v] = 0;
                to_check.push(v);
            }
        }
    }
}

int main() {
    int n, m, s;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> cost(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    cin >> s;
    s--;
    vector<long long> distance(n, numeric_limits<long long>::max());
    vector<int> reachable(n, 0);
    vector<int> shortest(n, 1);
    shortest_paths(adj, cost, s, distance, reachable, shortest);
    for (int i = 0; i < n; ++i) {
        if (!reachable[i]) {
            cout << "*\n";
        } else if (!shortest[i]) {
            cout << "-\n";
        } else {
            cout << distance[i] << "\n";
        }
    }
}
