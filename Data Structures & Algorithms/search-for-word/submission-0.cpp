class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, 
                   int idx_word, int r, int c) {
        if (idx_word == word.size()) return true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int cr = r + dr[i];
            int cc = c + dc[i];
            // we need it to not be visited and also to be the current idx
            if (cr >= 0 && cc >= 0 && cr < board.size() && cc < board[0].size() && 
                visited[cr][cc] == 0 && board[cr][cc] == word[idx_word]) {
                visited[cr][cc] = true;
                bool retval = backtrack(board, visited, word, idx_word + 1, cr, cc);
                if (retval == true) return true;
                visited[cr][cc] = false;
            }
        }
        // if we got to the end then we didn't find any path
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // we haven't visited any yet
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        // we can go up down, or left right
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                // we could start anywhere:
                
                if (board[i][j] == word[0]) {
                    // then this is a valid start:
                    visited[i][j] = true;
                    if (backtrack(board, visited, word, 1, i, j)) return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
