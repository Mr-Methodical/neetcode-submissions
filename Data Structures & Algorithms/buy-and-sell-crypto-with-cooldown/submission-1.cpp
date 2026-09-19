class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,  0));
        // state 1 represents that we have a coin
        // state 2 represents no coin
        dp[0][0] = -1 * prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            // to acquire a coin we can keep what we had last round or buy from new
            // we can't buy a new coin though if we were on cooldown down though
            if (i == 1) {
                dp[i][0] = max(dp[i - 1][0], -1 * prices[1]);
            } else {
                // we are not allowed to buy from the day before
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);
            }
            // how do we end with no coin
            // stay no coin or sell coin
            // we favor not havig a cooldown
            if (dp[i - 1][1] >= dp[i - 1][0] + prices[i]) {
                dp[i][1] = dp[i - 1][1];
            } else {
                dp[i][1] = dp[i - 1][0] + prices[i];
            }
        }
        return dp[prices.size() - 1][1]; // we have no coin, it would never be more optimal for us
        // to still have a coin
    }
};
