class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // let's find the total
        int total = 0;
        for (int num : nums) {
            total += num;
        }
        if ((total % 2) == 1) return false;
        int half = total / 2;
        // we just need to find some that add up to this half
        vector<bool> dp(half + 1, false); // represents if we were able to hit it
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            // so we will go through every number and try using it to see what
            // it helps with
            for (int j = half; j >= nums[i]; --j) {
                // we go backwards so we don't double count the number
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[half];
    }
};
