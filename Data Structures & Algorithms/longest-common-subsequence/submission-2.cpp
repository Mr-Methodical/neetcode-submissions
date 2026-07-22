class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // we will take the max of what we have seen so far to left and up, and then if we have another match add 1
        int m = text1.size();
        int n = text2.size();
        if (m < n) return longestCommonSubsequence(text2, text1);
        // m >= n now
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; ++i) {
            int prev = 0; // this is the left diagonal
            for (int j = 0; j < n; ++j) {
                int temp = dp[j + 1];
                // we want to not include both these letters
                if (text1[i] == text2[j]) {
                    // then we found one more to increase the subsequence
                    // and we can't use any of the letters again
                    dp[j + 1] = prev + 1;
                } else {
                    // what is the best that we have seen with and without each letter
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                }
                prev = temp;
            }
        }
        return dp[n];
    }
};
