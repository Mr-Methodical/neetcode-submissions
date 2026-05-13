class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // we will first do columns then do rows then do squares
        // columns first:
        for (int i = 0; i < board.size(); ++i) {
            unordered_set<int> rows;
            unordered_set<int> cols;
            unordered_set<int> sqr;
            // I guess we could also figure out square in this as well
            // each i uniquely identifies which square we do 
            int meta_row = i / 3;
            int meta_col = i % 3;
            int start_row = 3 * meta_row;
            int start_col = 3 * meta_col; 
            // we will insert and then
            // we could actually check both columns and rows
            for (int j = 0; j < board.size(); ++j) {
                // we also need to skip periods:
                if (board[i][j] != '.') {
                    if (rows.contains(board[i][j])) return false;
                    rows.insert(board[i][j]);
                }
                if (board[j][i] != '.') {
                    if (cols.contains(board[j][i])) return false;
                    cols.insert(board[j][i]);
                }
                int delta_row = j / 3;
                int delta_col = j % 3;
                int f = start_row + delta_row;
                int g = start_col + delta_col;
                if (board[f][g] != '.') {
                    if (sqr.contains(board[f][g])) return false;
                    sqr.insert(board[f][g]);
                }
            }
        }
        // we need to figure out how to do the squares
        return true;
    }
};
