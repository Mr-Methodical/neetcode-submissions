class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        if (visited[r][c]) return;
        visited[r][c] = true;
        static constexpr int dr[] = {-1, 1, 0, 0};
        static constexpr int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];
            if (cr >= 0 && cc >= 0 && cr < heights.size() && cc < heights[0].size() &&
                heights[r][c] <= heights[cr][cc]) {
                dfs(heights, visited, cr, cc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<bool>> reach_atl(row, vector<bool>(col, false));
        vector<vector<bool>> reach_pac(row, vector<bool>(col, false));
        for (int i = 0; i < col; ++i) {
            dfs(heights, reach_atl, row - 1, i);
            dfs(heights, reach_pac, 0, i);
        }
        for (int i = 0; i < row; ++i) {
            dfs(heights, reach_atl, i, col - 1);
            dfs(heights, reach_pac, i, 0);
        }
        // now we need to find overlap as that is where it can reach both
        vector<vector<int>> result;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (reach_atl[i][j] && reach_pac[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};
