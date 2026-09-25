class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // we will put index where it should be 
        for (int i = 0; i < nums.size(); ++i) {
            nums[i]--;
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            // now we put it where the index should be 
            while (nums[i] >= 0 && nums[i] != i && nums[i] < nums.size()) {
                swap(nums[i], nums[nums[i]]);
                if (nums[i] < 0 || nums[i] >= nums.size() || nums[i] == nums[nums[i]]) {
                    break;
                }
            }
        }
        // now we just need to find where it is not increasing by 1
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num = i;
            if (nums[i] < 0 || nums[i] >= nums.size() || nums[i] != i) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};