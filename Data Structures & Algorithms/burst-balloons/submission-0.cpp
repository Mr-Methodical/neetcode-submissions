class Solution {
public:
    int dp(vector<int>& arr, int l, int r, vector<vector<int>>& memo) {
        if (l > r) return 0;
        if (memo[l][r] != -1) {
            return memo[l][r];
        }
        if (l == r) {
            return memo[l][r] = arr[l] * arr[l - 1] * arr[l + 1]; 
        }
        int max_path = 0;
        for (int i = l; i <= r; ++i) {
            // if it's on the left side then we should probably only multiply 
            // by the last element and one because that is how it would be in the 
            // reverse order
            max_path = max(max_path, arr[i] * arr[r + 1] * arr[l - 1] + 
                                     dp(arr, l, i - 1, memo) + 
                                     dp(arr, i + 1, r, memo));
        }
        return memo[l][r] = max_path;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> arr(nums.size() + 2);
        arr[0] = 1;
        arr[nums.size() + 1] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            arr[i] = nums[i - 1];
        }
        vector<vector<int>> memo(arr.size(), vector<int>(arr.size(), -1));
        int max_sum = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            // for each of them we will consider that being the last
            // memo[l][r] represents the total for that subproblem
            max_sum = max(max_sum, arr[i] + 
                          dp(arr, i + 1, nums.size(), memo)
                           + dp(arr, 1, i - 1, memo));
        }
        return max_sum;
    }
};
