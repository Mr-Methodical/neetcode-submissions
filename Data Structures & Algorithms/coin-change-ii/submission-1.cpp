class Solution {
public:
    // we will be returning the number of ways so far:
    // the situation does depend on both coins you have left and also amount
    int dp(int amount, vector<int>& coins, int idx, vector<vector<int>>& memo) {
        if (amount == 0) {
            return 1;
        }
        if (amount < 0 || idx == coins.size()) {
            return 0;
        }
        if (memo[amount][idx] != -1) return memo[amount][idx];
        int sum = dp(amount, coins, idx + 1, memo) + dp(amount - coins[idx], coins, idx, memo);
        return memo[amount][idx] = sum;
    }
    int change(int amount, vector<int>& coins) {
        // there are only so many ways 
        vector<vector<int>> memo(amount + 1, vector<int>(coins.size(), -1));
        return dp(amount, coins, 0, memo);
    }
};
