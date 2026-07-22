class Solution {
public:
    int uniquePaths(int m, int n) {
        // so we are only allowed to move down and to the right
        // let's go backwards, how many options do we have at the goal
        // honestly you could also do this in O(m) space or O(n)
        vector<vector<int>> grid(m, vector<int>(n, 0)); // grid represents number of ways to get there
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = 1;
        }
        for (int i = 0; i < n; ++i) {
            grid[m - 1][i] = 1;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == 0) {
                    grid[i][j] = grid[i][j + 1] + grid[i + 1][j]; // how many paths to the right and also down
                }
            }
        }
        return grid[0][0];
    }
};
