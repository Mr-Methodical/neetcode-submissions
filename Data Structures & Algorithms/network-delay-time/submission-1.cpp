class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // we are going to do our pq off of time from the source
        vector<int> mins(n + 1, INT_MAX);
        mins[k] = 0;
        // this will map source node to the list of target node and times that it hits
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& time : times) {
            int ui = time[0];
            int vi = time[1];
            int ti = time[2];
            adj[ui].push_back({vi, ti});
        }
        // pq max heap by default but we need min heap for shortest times
        // greater<> used because things that are greater will be pushed to the bottom
        // the pair is going to be distance and node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            auto [ti, vi] = pq.top();
            pq.pop();
            if (ti > mins[vi]) continue; // this one is stale
            // loop through all the ones that are next to them
            for (const auto& [target, t] : adj[vi]) {
                int new_time = t + mins[vi];
                if (new_time < mins[target]) {
                    mins[target] = new_time;
                    // add it back in our pq, like as we are essentially updating the value:
                    pq.push({new_time, target});
                }
            }
        }
        // we will go through and check what was the latest that a node was hit:
        int best_time = 0;
        for (int i = 1; i <= n; ++i) {
            best_time = max(best_time, mins[i]);
        }
        return (best_time == INT_MAX) ? -1 : best_time;
    }
};
