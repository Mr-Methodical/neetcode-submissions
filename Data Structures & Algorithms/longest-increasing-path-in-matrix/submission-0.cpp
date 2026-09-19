class Solution {
public:
    int dp(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& memo) {
        if (memo[x][y]) {
            return memo[x][y];
        }
        vector<int> dx{0, 1, -1, 0};
        vector<int> dy{1, 0, 0, -1};
        // we should explore all 4 around us and only go down if increasing
        // return 1 if it is just us
        int max_curr = 1;
        for (int i = 0; i < 4; ++i) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (cx >= 0 && cx < matrix.size() && cy >= 0 && cy < matrix[0].size() &&
                matrix[cx][cy] > matrix[x][y]) {
                max_curr = max(max_curr, 1 + dp(matrix, cx, cy, memo));
            }
        }
        return memo[x][y] = max_curr;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // we should go through every index
        int n = matrix.size();
        int m = matrix[0].size();
        int max_path = 0;
        vector<vector<int>> memo(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_path = max(max_path, dp(matrix, i, j, memo));
            }
        }
        return max_path;
    }
};
