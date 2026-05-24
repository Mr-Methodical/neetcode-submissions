class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int curr_sum, int target, int idx) {
        if (curr_sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (curr_sum + candidates[i] > target) break;
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            curr.push_back(candidates[i]);
            backtrack(candidates, result, curr, curr_sum + candidates[i], target, i + 1);
            curr.pop_back();
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
