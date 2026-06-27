class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int total = 0;
        vector<int> in_tree(n, false);
        vector<int> weights(n, INT_MAX);
        weights[0] = 0; // we will arbitrarily start at the 0th point
        for (int i = 0; i < n; ++i) { // we want to add n nodes into the tree
            int u = -1; // find the cheapest index not in our set
            for (int j = 0; j < n; ++j) {
                if (!in_tree[j] && (u == -1 || weights[j] < weights[u])) u = j;
            }
            in_tree[u] = true; // we are now visiting this one
            total += weights[u];
            for (int j = 0; j < n; ++j) { // give our updates to the weights as we added new node
                if (in_tree[j]) continue; // already in our tree so no need to update these weights
                int w = abs(points[j][0] - points[u][0]) + abs(points[j][1] - points[u][1]);
                if (weights[j] > w) weights[j] = w;
            }
        }
        return total;
    }
};
