class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int node) {
        // we are going to remove all the ones that it is connected to from adj
        // we don't really want in the case that there is a cycle for it to repeat so we should remove before hand
        vector<int> temp = adj[node];
        adj.erase(node);
        for (int new_node : temp) {
            dfs(adj, new_node);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // lets see what they are all connected to:
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // we do also have to account for the ones that have no edges connected to them so we can just say that they are connected to themselves
        for (int i = 0; i < n; ++i) adj[i].push_back(i);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (adj.contains(i)) {
                ++count;
                dfs(adj, i);
            }
        }
        return count;
    }
};
