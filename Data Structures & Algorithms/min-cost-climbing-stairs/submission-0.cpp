class Solution {
public:
    int min_cost(vector<int>& memo, vector<int>& cost, int idx) {
        if (memo[idx] != -1) return memo[idx]; // pre-computed
        if (idx < 2) return cost[idx];
        memo[idx] = cost[idx] + min(min_cost(memo, cost, idx - 1), min_cost(memo, cost, idx - 2));
        return memo[idx];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> memo(n + 1, -1);
        return min_cost(memo, cost, n);
    }
};
