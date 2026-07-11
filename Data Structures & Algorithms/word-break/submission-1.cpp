class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        // dp[i] is true when it is possible to reach there
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) continue;
            for (const string& word : wordDict) {
                int n_word = word.size();
                if (n_word + i > n) continue; // too big
                bool match = true;
                for (int j = 0; j < n_word; ++j) {
                    if (word[j] != s[i + j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    // we were able to reach this part
                    dp[i + n_word] = true;
                }
            }
        }
        // were we able to get to the end:
        return dp[n];
    }
};
