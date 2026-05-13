class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // one way is to build it up with multiple arrays
        // because we just need to know what we need to multiply from
        // the left and right side
        // ok let's do brute force solution first then
        vector<int> output(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                product *= nums[j];
            }
            output[i] = product;
        }
        return output;
    }
};
