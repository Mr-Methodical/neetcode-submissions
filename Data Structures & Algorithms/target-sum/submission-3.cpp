class Solution {
public:
    int dp(vector<int>& nums, int target, int idx, 
           int sum, vector<vector<int>>& memo, int total) {
        // the only thing that matters at each stage is the sum and if you could hit 
        // it or not and what index you are at
        // so idx is one and then sum is another, we can sum up 20,000
        // memo[idx][sum] is the number of ways
        if (memo[idx][total + sum] != -1) {
            return memo[idx][total + sum];
        }
        if (idx == nums.size()) {
            // we are past the array
            if (sum == target) {
                return memo[idx][total + sum] = 1;
            } else {
                return memo[idx][total + sum] = 0;
            }
        }
        // we can either add or subtract
        return memo[idx][total + sum] = dp(nums, target, idx + 1, sum + nums[idx], memo, total) +
                                dp(nums, target, idx + 1, sum - nums[idx], memo, total);
    }  
    int findTargetSumWays(vector<int>& nums, int target) {
        // total sum needs to equal target
        // we have a choice on each one whether to add or subtract
        // the only thing that matters is what sum we are at and what index
        // let's recurse to see what the recurrence is
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(nums.size() + 1, vector<int>(2 * sum + 1, -1));
        return dp(nums, target, 0, 0, memo, sum);
    }
};
