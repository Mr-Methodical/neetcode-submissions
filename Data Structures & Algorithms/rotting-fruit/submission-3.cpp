class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        // find all the rotting bananas:
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j  < n; ++j) {
                if (grid[i][j] == 2) {
                        q.push({i, j});
                }
            }
        }
        int time = 0;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        // case of no rotten fruit:
        while (!q.empty()) {
                int level = q.size();
                // we should do all the ones on current level as that is what
                //   we can do in one time instance:
                for (int i = 0; i < level; ++i) {
                        auto [r, c] = q.front();
                        q.pop();
                        for (int j = 0; j < 4; ++j) {
                                int cr = r + dr[j];
                                int cc = c + dc[j];
                                if (cr >= 0 && cc >= 0 && cr < m && cc < n && grid[cr][cc] == 1) {
                                        grid[cr][cc] = 2;
                                        q.push({cr, cc});
                                }
                        }
                }
                time++;
        }
        // scan grid to check if any fresh fruit remain
        for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                        if (grid[i][j] == 1) {
                                return -1;
                        }
                }
        }
        
        // time will have had to go through one extra cycle as the last round of nums
        //   created nothing new, so they shouldn't actaully count.
        //   but there is also the case that time is 0, so the grid has no rotten fruit, but
        //   in that case it should return -1, so it wouldn't be possible
        // so this max check saves us against the case that there are no rotten oranges
        //   and there are no fresh oranges:
        return max(0, time - 1);
    }
};
