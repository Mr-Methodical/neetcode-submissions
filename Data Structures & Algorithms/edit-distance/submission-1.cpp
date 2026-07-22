class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m < n) return minDistance(word2, word1);
        // now m >= n
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        } 
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // the question is what should dp[i + 1][j + 1]
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j]; // assume that is right then we are just at the same number
                    // of changes needed to be made to the diagonal without both letters
                } else {
                    // there is a difference so we will take the min of the best that we have seen previously but + 1
                    dp[i + 1][j + 1] = min({dp[i + 1][j], dp[i][j + 1], dp[i][j]}) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
