/*
1. Perform a depth-first search (DFS) on the original graph to compute post-visit times for each vertex. The post-visit time indicates the order in which nodes finish the DFS.
   So a source would finish the dfs at last. But we want sinks (points where an SCC would end)
2. Transpose the graph (reverse the direction of all edges). In the transposed graph, sources become sinks and sinks become sources.
   By identifying a sink, we can go in reverse order to identify where this node can reach, thus giving us an SCC.
3. Process the nodes in decreasing order of their post-visit times from the initial DFS.
4. Perform a DFS on the transposed graph starting from the node with the highest post-visit time that hasn't been visited yet. Each DFS traversal identifies one strongly connected component (SCC).
5. Mark all nodes visited during each DFS traversal on the transposed graph.
6. Count the number of DFS traversals performed on the transposed graph. This count represents the number of SCCs in the original graph.

This algorithm ensures that all nodes are explored efficiently, and the SCCs are correctly identified.
*/


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void explore1(vector<vector<int>>& adj, vector<bool>& visited1, vector<int>& post_visit, int v, int& num) {
    visited1[v] = true;
    for (int u : adj[v]) {
        if (!visited1[u]) {
            explore1(adj, visited1, post_visit, u, num);
        }
    }
    post_visit[v] = num++;
}

void explore2(vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            explore2(adj, visited, u);
        }
    }
}

int number_of_strongly_connected_components(vector<vector<int>>& adj) {
    int result = 0;
    int num = 0;
    int n = adj.size();
    vector<bool> visited1(n, false);
    vector<bool> visited2(n, false);
    vector<int> post_visit(n, -1);

    // First DFS to compute finishing times
    for (int i = 0; i < n; ++i) {
        if (!visited1[i]) {
            explore1(adj, visited1, post_visit, i, num);
        }
    }

    // Transpose the graph
    vector<vector<int>> adj_transposed(n);
    for (int v = 0; v < n; ++v) {
        for (int u : adj[v]) {
            adj_transposed[u].push_back(v);
        }
    }

    // Process nodes in decreasing order of their post_visit values
    vector<pair<int, int>> order;
    for (int i = 0; i < n; ++i) {
        order.push_back({ post_visit[i], i });
    }
    sort(order.rbegin(), order.rend());

    for (size_t i = 0; i < order.size(); ++i) {
        int v = order[i].second;
        if (!visited2[v]) {
            explore2(adj_transposed, visited2, v);
            result++;
        }
    }


    return result;
}

int main() {
    size_t n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (size_t i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
    cout << number_of_strongly_connected_components(adj);
    return 0;
}
