class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        // we assume that our current position is good and replace with sentinel:
        grid[r][c] = '#';
        int dc[] = {-1, 1, 0, 0};
        int dr[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            // we will check all sides:
            int cr = r + dr[i];
            int cc = c + dc[i];
            if (cr >= 0 && cc >= 0 && cr < grid.size() && cc < grid[0].size() && grid[cr][cc] == '1') {
                dfs(grid, cr, cc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // so we will go over every square and we will fully go down the path
        // and replace with a sentinel
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;    
    }
};
