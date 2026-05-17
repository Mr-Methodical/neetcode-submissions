class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if ((nums[mid] < target && target <= nums[r]) || (nums[mid] > nums[r] && (target <= nums[r] || target > nums[mid]))) {
                // 2 situations: sorted through and between 
                l = mid + 1;
            } else {
                r = mid - 1; // as i
            }
        }
        return  -1;
    }
};
