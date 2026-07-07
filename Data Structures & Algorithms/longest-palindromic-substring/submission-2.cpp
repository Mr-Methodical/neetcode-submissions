class Solution {
public:
    string longestPalindrome(string s) {
        int max_idx = 0;
        int max_len = 0;
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // the first for loop is the size
        for (int i = 0; i <= n; ++i) {
            // length is actually i + 1 but this just makes it easier
            // next for loop is trying it out for all possible
            for (int j = 0; j < n - i; ++j) {
                if (s[j] == s[j + i] && (i <= 2 || dp[j + 1][j + i - 1])) {
                    dp[j][j + i] = 1;
                    if (i + 1 > max_len) {
                        max_len = i + 1;
                        max_idx = j;
                    }
                }
            }
        }
        return s.substr(max_idx, max_len);
    }
};
