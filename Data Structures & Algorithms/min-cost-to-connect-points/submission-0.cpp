class Solution {
public:
    vector<int> parent;
    vector<int> size_;
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return false;
        if (size_[ra] < size_[rb]) swap(ra, rb);
        parent[rb] = ra;
        size_[ra] += size_[rb];
        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size_.resize(n, 1);
        // we need to create the weights of all the edges
        // src, dest, cost
        vector<vector<int>> pedge;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int man = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pedge.push_back({i, j, man});

            }
        }
        // we are trying to find the MST so use kruskal's and sort by smallest cost
        sort(pedge.begin(), pedge.end(), 
        [](const vector<int>& p1, const vector<int>& p2) { return p1[2] < p2[2]; });
        // now they are sorted by cost
        int total = 0;
        for (const auto& p : pedge) {
            if (unite(p[0], p[1])) {
                // then this is a new group that we are adding
                total += p[2]; // we add the weight of this connection
            }
        }
        return total;
    }
};
