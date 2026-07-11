class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < 0) {
                // multiplying by a negative will cause them to switch
                swap(curr_max, curr_min);
            }
            // we can either take the new value or go on a streak
            curr_max = max(nums[i], curr_max * nums[i]);
            curr_min = min(nums[i], curr_min * nums[i]);
            best = max(curr_max, best);
        }
        return best;
    }
};
