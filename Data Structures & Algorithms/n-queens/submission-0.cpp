class Solution {
public:
    unordered_set<int> row, pos_diag, neg_diag;
    void backtrack(vector<vector<string>>& result, vector<string>& curr, int n, int col, int row_size) {
        if (n == 0) {
            result.push_back(curr);
            return;
        }
        // we need to check through everything on our current row
        for (int i = 0; i < row_size; ++i) {
            if (!row.contains(i) && !pos_diag.contains(i + col) && !neg_diag.contains(i - col)) {
                row.insert(i);
                pos_diag.insert(i + col);
                neg_diag.insert(i - col);
                string s(row_size, '.');
                s[i] = 'Q';
                curr.push_back(s);
                backtrack(result, curr, n - 1, col + 1, row_size);
                curr.pop_back();
                row.erase(i);
                pos_diag.erase(i + col);
                neg_diag.erase(i - col);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> curr;
        int row_size = n;
        backtrack(result, curr, n, 0, row_size);
        return result;
    }
};
