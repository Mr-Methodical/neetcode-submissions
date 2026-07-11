class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // dp[i] is true when we can reach the ith index
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;
            for (const string& word : wordDict) {
                int len = word.size();
                if (i + len <= n && (s.compare(i, len, word) == 0)) {
                    dp[i + len] = true; // we were able to reach here
                }
            }
        }
        return dp[n];
    }
};
