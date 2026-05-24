class Solution {
public:
    void backtrack(vector<string>& result, string curr, int open, int close) {
        if (open == 0 && close == 0) {
            result.push_back(curr);
            return;
        }
        if (open > 0) {
            backtrack(result, curr + "(", open - 1, close);
        }
        // we really shouldn't be closing unless close is greater than open as well to keep order
        if (close > open && close > 0) {
            backtrack(result, curr + ")", open, close - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backtrack(result, curr, n, n);
        return result;
    }
};
