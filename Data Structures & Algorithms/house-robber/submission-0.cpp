class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> arr(n);
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; ++i) {
            arr[i] = max(nums[i] + arr[i - 2], arr[i - 1]);
        } 
        return arr[n - 1];
    }
};
