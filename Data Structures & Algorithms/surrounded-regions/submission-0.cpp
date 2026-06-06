class Solution {
public:
// maybe we only go from the outer and replace those with Z's as we know these are all safe
// and then marks all the ones that do not have Z with an X
    void dfs(vector<vector<char>>& board, int r, int c) {
        board[r][c] = 'Z';
        static constexpr int dr[] = {-1, 1, 0, 0};
        static constexpr int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];
            // we need to make sure it still in bounds and we only recurse if another O
            if (cr >= 0 && cc >= 0 && cr < board.size() && 
                cc < board[0].size() && board[cr][cc] == 'O') {
                dfs(board, cr, cc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        // we could go through every cell 
        // we need some way to mark if we have visited them and they are good
        // or to say they are visited and they are bad (that case they would just be x)
        // we could mark them with a Z if we have visited them and we know there is a connection
        // to the outer
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O') {
                    // then we are at outer edge, so we recurse as these are all good:
                    dfs(board, i, j);
                }
            }
        }
        // now we are in a situation where all the 'O's that are left should be taken over
        // and then all the Z's should be turn to O's as these were the safe ones:
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
