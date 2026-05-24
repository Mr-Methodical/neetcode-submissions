class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<int>& nums, int idx) {
        result.push_back(curr);
        for (int i = idx; i < nums.size(); ++i) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(result, curr, nums, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        // sort so then we will be able to smartly skip
        sort(nums.begin(), nums.end());
        backtrack(result,curr, nums, 0);
        return result;
    }
};
