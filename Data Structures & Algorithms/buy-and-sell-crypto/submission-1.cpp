class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int left = 0;
        for (int right = 1; right < prices.size(); ++right) {
            if (prices[right] < prices[left]) {
                left = right;
                continue;
            }
            while (left < right && prices[left] > prices[left + 1]) {
                left++;
            }
            profit = max(profit, prices[right] - prices[left]);
        }
        return profit;
    }
};
