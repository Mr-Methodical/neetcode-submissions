class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int curr, int parent) {
        // maybe we go and explore all the way down
        // but if we have already visited it then that means there is a cycle:
        if (visited.contains(curr)) return false;
        visited.insert(curr);
        for (int connection : adj[curr]) {
            // explore all the nodes below:
            if (connection == parent) continue; // we already know connected
            if (!dfs(adj, visited, connection, curr)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        // in a tree every node will be connected,so we can just do dfs on node 0:
        if (!dfs(adj, visited, 0, -1)) return false; // if there is a cycle
        // did we explore every node? We need everything to be connected
        return (visited.size() == n);
    }
};
