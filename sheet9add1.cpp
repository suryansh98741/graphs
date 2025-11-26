#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    for (int nb : adj[node]) {
        if (!vis[nb]) dfs(nb, adj, vis);
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    vector<bool> vis(V, false);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int components = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            components++;
        }
    }

    cout << components;
    return 0;
}
