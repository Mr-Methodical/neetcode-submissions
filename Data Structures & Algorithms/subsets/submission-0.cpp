class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& curr, int idx, vector<int>& nums) {
        result.push_back(curr);
        for (int i = idx; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            // we wouldn't want to double include it
            backtrack(result, curr, i + 1, nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result, curr, 0, nums);
        return result;
    }
};
