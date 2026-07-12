class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int best = 1;
        // dp is the LIS that ends at index i
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    // we could keep what we have or add nums[i] to front of a LIS 
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            best = max(dp[i], best);
        }
        return best;
    }
};
