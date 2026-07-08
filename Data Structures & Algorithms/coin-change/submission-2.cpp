class Solution {
public:
    int dfs(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (memo[amount] != -2) return memo[amount];
        int mv = -1;
        for (const auto& coin : coins) {
            int retval = dfs(coins, amount - coin, memo);
            if (retval != -1) {
                if (mv == -1) {
                    mv = retval + 1; // for this coin
                } else {
                    mv = min(mv, retval + 1);
                }
            }
        }
        memo[amount] = mv;
        return mv;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2);
        return dfs(coins, amount, memo);
    }
};
