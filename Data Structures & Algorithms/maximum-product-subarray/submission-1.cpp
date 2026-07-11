class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MIN;
        int product = 1;
        // idea is that the first pass will check every thing going from the left side
        // like if negatives then we would not be including the last negative
        // also seeing a zero splits it up
        for (int i = 0; i < n; ++i) {
            product *= nums[i];
            best = max(product, best);
            if (product == 0) product = 1;
        }
        product = 1;
        // This pass should fine them from the right side
        // the idea is that if there are odd number of negatives we either take first or last
        // this is because we would always want to include at least one of them getting rid of both would be nonsensincal
        // because then we would still have odd number of negatives and smaller range, and then we cna't keep both
        // we maximize the number of values that can come into product by doing the outsides
        for (int i = n - 1; i >= 0; --i) {
            product *= nums[i];
            best = max(product, best);
            // no point in continuing if product is 0
            if (product == 0) product = 1;
        }
        return best;
    }
};
