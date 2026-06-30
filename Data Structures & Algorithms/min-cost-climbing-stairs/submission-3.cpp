class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int sub1 = 0;
        int sub2 = 0;
        for (int i = 2; i <= n; ++i) {
            int curr = min(sub1 + cost[i - 1], sub2 + cost[i - 2]); 
            sub2 = sub1;
            sub1 = curr;
        }
        return sub1;
    }
};
