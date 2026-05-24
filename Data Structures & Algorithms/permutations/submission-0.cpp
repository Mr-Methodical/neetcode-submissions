class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& curr, vector<bool>& visited) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        // we need to have some way to be able to go back
        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i] == true) continue;
            visited[i] = true;
            curr.push_back(nums[i]);
            backtrack(result, nums, curr, visited);
            curr.pop_back();
            visited[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // we should use backtracking for permuations
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), 0); // will initialize to all zero's
        vector<int> curr;
        backtrack(result, nums, curr, visited);
        return result;
    }
};
