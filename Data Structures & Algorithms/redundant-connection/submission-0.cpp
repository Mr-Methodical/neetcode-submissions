class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, unordered_set<int> visited, int start, int destination) {
        // our whole goal is to see if there is some way to get from the start to the destination
        if (start == destination) return true;
        for (const auto& neighbor : adj[start]) {
            if (!visited.contains(neighbor)) {
                visited.insert(neighbor);
                if (dfs(adj, visited, neighbor, destination)) return true;
                visited.erase(neighbor);
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        /*for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }*/
        // almost we should be building up our adj list
        // we will go through iteratively and if we could have already got there by using a path we already have then we found our redundant connection
        unordered_set<int> visited;
        for (const auto& edge : edges) {
            // can we already make that connection? Yes then return our redundant edge
            if (dfs(adj, visited, edge[0], edge[1])) return edge;
            // now we will add it to our list
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // that will always happen so we will just return something that will never happen:
        return {-1, -1};
    }
};
