class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int total = 0;
        int n = points.size();
        vector<int> min_dist(n, INT_MAX); // this is from our structure
        // arbitrarily we will start at the first point:
        min_dist[0] = 0;
        unordered_set<int> mst;
        unordered_set<int> outside_mst;
        for (int i = 0; i < n; ++i) {
            outside_mst.insert(i);
        }
        while (!outside_mst.empty()) {
            // check out the closest rope and we will explore that
            int best_index = -1;
            for (int i = 0; i < n; ++i) {
                // we must not have explored it yet, not in our half
                if ((best_index == -1 || min_dist[best_index] > min_dist[i]) && outside_mst.contains(i)) best_index = i;
            }
            total += min_dist[best_index]; // add in the cost
            // we will add this one to our mst as the cut property says this must help us
            mst.insert(best_index);
            outside_mst.erase(best_index);
            // now we should see if this best_index can help us discover any better dist
            for (int i = 0; i < n; ++i) {
                if (outside_mst.contains(i)) {
                    int man_dist = abs(points[i][0] - points[best_index][0]) + abs(points[i][1] - points[best_index][1]);
                    if (min_dist[i] > man_dist) {
                        min_dist[i] = man_dist;
                    }
                }
            }
        }
        return total;
    }
};
