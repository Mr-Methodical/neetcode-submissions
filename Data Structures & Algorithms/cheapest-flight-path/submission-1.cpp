class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> node_cost(n, INT_MAX);
        node_cost[src] = 0; // as we are already there
        for (int i = 0; i < k + 1; i++) {
            // k + 1 since that is the number of flights that we can take
            vector<int> snapshot = node_cost; // we don't want to jump two in one
            for (const auto& flight : flights) {
                int from_i = flight[0], to_i = flight[1], price_i = flight[2];
                // go through every edge
                // if snap_shot is at INT_MAX we haven't visited the node yet
                if (snapshot[from_i] != INT_MAX && snapshot[from_i] + price_i < node_cost[to_i]) {
                    node_cost[to_i] = snapshot[from_i] + price_i;
                }
            }
        }
        return (node_cost[dst] == INT_MAX) ? -1 : node_cost[dst];
    }
};
