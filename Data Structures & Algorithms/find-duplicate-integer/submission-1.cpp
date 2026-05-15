class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // We need to find where the slow and fast pointer intersect
        int slow = 0;
        int fast = 0;
        while (1) {
            // slows new index is whatever is at slow
            slow = nums[slow];
            // fast goes two steps forward
            fast = nums[nums[fast]];
            if (fast == slow) {
                // we found our intersection point
                break;
            }
        }
        // now we need to find where the loop starts
        // using floyd cycle detection we can start at beginning again
        int restart = 0;
        while (1) {
            if (restart == slow) {
                break;
            }
            restart = nums[restart];
            slow = nums[slow];
        }
        // now we are on the start of the cycle which is the repeat element
        // Idea is that the start of the cycle will have two pointers 
        // going towards it so it is the duplicate one
        // when slow == restart they are both sitting on the correct val
        return slow;
    }
};
