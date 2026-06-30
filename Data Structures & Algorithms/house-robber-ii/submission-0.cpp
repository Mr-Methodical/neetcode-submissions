class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        if (n == 3) return max({nums[0], nums[1], nums[2]});
        // we can either rob the first house or the last house not both
        // let's rob the first house
        int back2 = nums[0];
        int back1 = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; ++i) {
            int curr = max(nums[i] + back2, back1);
            back2 = back1;
            back1 = curr;
        }
        int rob_first = back1;
        // let's rob the last house instead
        back2 = nums[1];
        back1 = max(nums[1], nums[2]);
        for (int i = 3; i < n; ++i) {
            int curr = max(nums[i] + back2, back1);
            back2 = back1;
            back1 = curr;
        }
        int rob_second = back1;
        return max(rob_first, rob_second);
    }
};
