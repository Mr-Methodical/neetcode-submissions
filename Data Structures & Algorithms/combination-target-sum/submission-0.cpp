class Solution {
public:
    void backtrack(vector<vector<int>>& result, int curr_sum, vector<int>& curr, int target, int idx, vector<int>& nums) {
        if (curr_sum > target) return;
        if (curr_sum == target) {
            result.push_back(curr);
            return;
            // we can't get anything more out of it
        }
        // idea is that we will go through and maybe reuse
        // we fully explore that path, and then we move on and try another one
        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            // we can use idx multiple times
            backtrack(result, curr_sum + nums[i], curr, target, i, nums);
            curr.pop_back();
        } 
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int curr_sum = 0;
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result, curr_sum, curr, target, 0, nums);
        return result;
    }
};
