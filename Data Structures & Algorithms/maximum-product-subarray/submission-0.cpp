class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product_best = INT_MIN;
        // we could do slow version first
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int product = 1;
            for (int j = i; j < n; ++j) {
                product *= nums[j];
                product_best = max(product_best, product);
            }
        }
        return product_best;
    }
};
