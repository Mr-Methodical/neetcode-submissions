class Solution {
public:
    void dfs(unordered_map<string, multiset<string>>& adj, const string& curr, 
             vector<string>& order) {
        while (!adj[curr].empty()) {
            // pull the first thing from the list
            string nxt = *adj[curr].begin();
            adj[curr].erase(adj[curr].begin());
            dfs(adj, nxt, order);
        }
        order.push_back(curr);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        vector<string> order;
        dfs(adj, "JFK", order);
        reverse(order.begin(), order.end());
        return order;
    }
};
