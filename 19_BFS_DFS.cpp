#include <bits/stdc++.h>
using namespace std;

void bfs(int src, const vector<vector<int>> &adj, vector<int> &order) {
    int n = adj.size();
    vector<bool> vis(n, false);
    queue<int> q;
    vis[src] = true;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfsUtil(int u, const vector<vector<int>> &adj, vector<bool> &vis, vector<int> &order) {
    vis[u] = true;
    order.push_back(u);
    for (int v : adj[u]) if (!vis[v]) dfsUtil(v, adj, vis, order);
}

void dfs(int src, const vector<vector<int>> &adj, vector<int> &order) {
    int n = adj.size();
    vector<bool> vis(n, false);
    dfsUtil(src, adj, vis, order);
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v) 0-based:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // for undirected
    }
    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<int> order;
    bfs(src, adj, order);
    cout << "BFS order: ";
    for (int x : order) cout << x << " ";
    cout << "\n";
    order.clear();
    dfs(src, adj, order);
    cout << "DFS order: ";
    for (int x : order) cout << x << " ";
    return 0;
}
