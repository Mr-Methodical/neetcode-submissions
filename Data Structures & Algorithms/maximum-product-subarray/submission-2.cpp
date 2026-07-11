class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int best = nums[0];
        int curr_min = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < 0) swap(curr_max, curr_min);
            curr_max = max(nums[i], nums[i] * curr_max);
            curr_min = min(nums[i], nums[i] * curr_min);
            best = max(best, curr_max);
        }
        return best;
    }
};
