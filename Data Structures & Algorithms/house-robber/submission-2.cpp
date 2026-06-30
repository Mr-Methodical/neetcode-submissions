class Solution {
public:
    int max_cost(vector<int>& nums, int idx, vector<int>& memo) {
        if (memo[idx] != -1) return memo[idx];
        if (idx == 0) return nums[0];
        if (idx == 1) return max(nums[0], nums[1]);
        memo[idx] = max(max_cost(nums, idx - 1, memo), 
                        nums[idx] + max_cost(nums, idx - 2, memo));
        return memo[idx];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        vector<int> memo(n, -1);
        return max_cost(nums, n - 1, memo);
    }
};
