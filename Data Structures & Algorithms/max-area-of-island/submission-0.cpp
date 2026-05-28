class Solution {
public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        // we will still replace with 2 to show we visited
        grid[r][c] = 2;
        int count = 1; // as we are currently at a node
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];
            if (cr >= 0 && cc >=0 && cr < grid.size() && cc < grid[0].size() && grid[cr][cc] == 1) {
                count += dfs(grid, cr, cc);
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
};
