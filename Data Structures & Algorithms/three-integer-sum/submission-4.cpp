class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size() - 2; ++i) {
            // we want to only choose the first one that shows up
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            // we are finding which value works with this target
            while (left < right) {
                if (nums[left] + nums[right] == -(nums[i])) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left + 1] == nums[left]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (nums[left] + nums[right] < -(nums[i])) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};
