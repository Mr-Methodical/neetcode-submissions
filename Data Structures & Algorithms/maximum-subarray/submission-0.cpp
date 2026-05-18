class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curr_max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (curr_max < 0) {
                // no reason to take it would only bring us down
                curr_max = nums[i];
            } else {
                curr_max += nums[i];
            }
            res = max(res, curr_max);
        }
        return res;
    }
};
