class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // pair representing coordinate:
        queue<pair<int, int>> q;
        // We will do multi source BFS, so the moment one changes we are guaranteed that it
        //   is the shorting path:
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int cr = r + dr[i];
                int cc = c + dc[i];
                if (cr >= 0 && cc >= 0 && cr < grid.size() && cc < grid[0].size() &&
                    grid[cr][cc] == INT_MAX) {
                    grid[cr][cc] = grid[r][c] + 1;
                    q.push({cr, cc});
                }
            }
        }
    }
};
