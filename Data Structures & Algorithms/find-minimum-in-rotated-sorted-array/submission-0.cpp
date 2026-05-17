class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[r]) {
                // then the pivot must be somewhere in between
                l = mid + 1;
            } else {
                // then pivot would be somwhere on the left side
                r = mid;
            }
        }
        return nums[l];
    }
};
