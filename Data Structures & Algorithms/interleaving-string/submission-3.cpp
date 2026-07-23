class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (n + m != s3.size()) return false;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true; // must be true 
        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = dp[i][0] && (s1[i] == s3[i]);
        }
        for (int i = 0; i < m; ++i) {
            dp[0][i + 1] = dp[0][i] && (s2[i] == s3[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (s3[i + j + 1] == s1[i] || s3[i + j + 1] == s2[j]) {
                    bool up = dp[i + 1][j] && s3[i + j + 1] == s2[j];
                    bool left = dp[i][j + 1] && s3[i + j + 1] == s1[i];
                    // one of them match
                    // so we choose one of these paths like one of them got us here
                    dp[i + 1][j + 1] = up || left;
                } else {
                    // neither match, so this should be 0, not a possible path
                    dp[i + 1][j + 1] = false;
                }
            }
        }
        return dp[n][m];
    }
};
