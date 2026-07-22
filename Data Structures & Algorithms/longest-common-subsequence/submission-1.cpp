class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // we will take the max of what we have seen so far to left and up, and then if we have another match add 1
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // we want to not include both these letters
                if (text1[i] == text2[j]) {
                    // then we found one more to increase the subsequence
                    // and we can't use any of the letters again
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    // what is the best that we have seen with and without each letter
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[m][n];
    }
};
