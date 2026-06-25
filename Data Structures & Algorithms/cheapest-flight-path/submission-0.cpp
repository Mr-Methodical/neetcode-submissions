class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // from_i -> to_i, price_i
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        // which nodes do we want to explore
        queue<int> explore_nodes;
        vector<int> curr(n, INT_MAX);
        // we start off being at our src node for free
        curr[src] = 0;
        explore_nodes.push(src);
        // there will be k + 1 flights (as k stops mean k + 1 flights)
        for (int i = 1; i <= k + 1; ++i) {
            // explore the connected ones
            int level = explore_nodes.size();
            vector<int> copy_begin = curr;
            for (int i = 0; i < level; ++i) {
                int curr_node = explore_nodes.front();
                explore_nodes.pop();
                for (const auto& [to_i, price_i] : adj[curr_node]) {
                    if (price_i + copy_begin[curr_node] < curr[to_i]) {
                        // we should explore this node, as it might be right path
                        explore_nodes.push(to_i);
                        // we update it
                        curr[to_i] = min(price_i + copy_begin[curr_node], curr[to_i]);
                    }
                }
            } 
        }
        // return
        return (curr[dst] == INT_MAX) ? -1 : curr[dst];
    }
};
