#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, E, K;
    cin >> N >> E >> K;

    vector<vector<pair<int,int>>> adj(N+1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dist(N+1, 1e9);

    priority_queue<pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>> pq;

    dist[K] = 0;
    pq.push({0, K});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int time = cur.first;
        int node = cur.second;

        for (auto &p : adj[node]) {
            int nb = p.first;
            int w = p.second;

            if (time + w < dist[nb]) {
                dist[nb] = time + w;
                pq.push({dist[nb], nb});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == 1e9) {
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
    return 0;
}
