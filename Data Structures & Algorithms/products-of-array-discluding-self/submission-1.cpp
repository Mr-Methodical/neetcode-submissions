class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // one way is to build it up with multiple arrays
        // because we just need to know what we need to multiply from
        // the left and right side
        vector<int> output(nums.size());
        // ok we first need to get all the left multipliers
        output[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            output[i] = output[i - 1] * nums[i - 1];
            // idea is that this is the product of everything on the left
        }
        // now we got left side:
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};
