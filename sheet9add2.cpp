#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(m, vector<int>(n, 1e9));

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int cost = cur.first;
        int r = cur.second.first;
        int c = cur.second.second;

        if (r == m-1 && c == n-1) {
            cout << cost;
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];
                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, {nr, nc}});
                }
            }
        }
    }

    return 0;
}
