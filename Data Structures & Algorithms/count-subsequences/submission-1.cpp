class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        // nothing technically can go in once
        for (int i = 0; i <= s.size(); ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= t.size(); ++i) {
            for (int j = 1; j <= s.size(); ++j) {
                // we get the same counts as before because a constant size word
                // will always have same count in a bigger sized word that had one
                // less option, it is just give more optionality
                // we get all the ways that we had before
                dp[i][j] = dp[i][j - 1];
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};
