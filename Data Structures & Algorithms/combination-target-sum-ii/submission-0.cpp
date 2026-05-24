class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int curr_sum, int target, int idx) {
        if (curr_sum > target) return;
        if (curr_sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            backtrack(candidates, result, curr, curr_sum + candidates[i], target, i + 1);
            curr.pop_back();
            // we want to be at the very last nums[i] we don't want to repeat
            // if we needed to then we would have already included the extra nums[i] as we can have those
            // in them as well, but now that we have done that then we need to keep moving on to the next one
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) ++i;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        // we could sort the list and then we keep going till the next one
        sort(candidates.begin(), candidates.end());
        int curr_sum = 0;
        backtrack(candidates, result, curr, curr_sum, target, 0);
        return result;
    }
};
