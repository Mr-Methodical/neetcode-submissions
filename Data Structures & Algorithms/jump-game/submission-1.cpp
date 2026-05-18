class Solution {
public:
    bool canJump(vector<int>& nums) {
        // we are already at end if the size if only 1:
        if (nums.size() == 1) return true;
        // maybe we go from the back instead actually
        int min_count = 1;
        for (int i = nums.size() - 2; i > 0; --i) {
            // the current one we are on would need to get us all the way for 
            // us to use else we couldn't use it:
            if (min_count - nums[i] <= 0) {
                min_count = 1;
            } else {
                min_count++;
            }
        }
        return (nums[0] >= min_count) ? true : false;
    }
};
