class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n + 1);
        arr[0] = 0;
        arr[1] = 0;
        for (int i = 2; i <= n; ++i) {
            // think about arr[i] as being the cost it took to get there
            arr[i] = min(cost[i - 1] + arr[i - 1], cost[i - 2] + arr[i - 2]);
        }
        return arr[n];
    }
};
