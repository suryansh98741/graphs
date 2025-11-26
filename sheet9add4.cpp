#include <iostream>
#include <vector>
using namespace std;

int m, n;

void dfs(int r, int c, vector<vector<int>>& grid) {
    if (r < 0 || c < 0 || r >= m || c >= n) return;
    if (grid[r][c] == 0) return;

    grid[r][c] = 0;

    dfs(r+1, c, grid);
    dfs(r-1, c, grid);
    dfs(r, c+1, grid);
    dfs(r, c-1, grid);
}

int main() {
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(i, j, grid);
                islands++;
            }
        }
    }

    cout << islands;
    return 0;
}
