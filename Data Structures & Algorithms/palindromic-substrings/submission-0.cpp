class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        // let's do dynamic programming
        int n = s.size();
        // rows represent start and columns represent end
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            // outer loop represent length - 1
            for (int j = 0; j < n - i; ++j) {
                if (s[j] == s[j + i] && (i <= 2 || dp[j + 1][j + i - 1])) {
                    dp[j][j + i] = true;
                    count++;
                }
            }
        }
        return count;
    }
};
