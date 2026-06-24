class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        // we need a pq to keep track of the closest node on our frontier
        // we need a min heap: first: time, second two are coordinates
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (t > time[x][y]) continue; // stale
            for (int i = 0; i < 4; ++i) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    // then it is a valid new square that we can go to
                    // t + 1 would be swimming to that new square
                    int new_time = max(grid[nx][ny], t);
                    if (new_time < time[nx][ny]) {
                        time[nx][ny] = new_time;
                        // we will push it on as we have explored a new frontier:
                        pq.push({new_time, nx, ny});
                    }
                }
            }
        }
        return time[n - 1][n - 1];
    }
};

