class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // let's do bottom up. Find number of ways to obtain target at each step
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, 0));
        // dp[i][j] represents for the ith index how many ways are there to get to 
        // a sum of j
        dp[0][nums[0] + sum] += 1;
        dp[0][-1 * nums[0] + sum] += 1;
        for (int i = 1; i < nums.size(); ++i) {
            // for each number we can add up what else would have contributed to it
            for (int j = 0; j < dp[0].size(); ++j) {
                if (dp[i - 1][j] != 0) {
                    dp[i][j + nums[i]] += dp[i - 1][j];
                    dp[i][j - nums[i]] += dp[i - 1][j];
                }
            }
        }
        return dp[nums.size() - 1][target + sum];
    }
};
