class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> q_idx;
        for (int i = 0; i < queries.size(); ++i) {
            q_idx.push_back({queries[i], i});
        }
        sort(q_idx.begin(), q_idx.end());
        sort(queries.begin(), queries.end());
        // min heap could be ordered by size and then end value as well
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> output(queries.size());
        int p = 0;
        for (int i = 0; i < queries.size(); ++i) {
            // keep adding in the queries until the query is smaller than the 
            // interval because then it could no longer be part of that
            while (p < intervals.size() && intervals[p][0] <= queries[i]) {
                int size = intervals[p][1] - intervals[p][0] + 1;
                pq.push({size, intervals[p][1]});
                p++;
            }
            // then we have to take off any at the top that are not within our range
            while (!pq.empty() && queries[i] > pq.top().second) {
                pq.pop();
            }
            if (pq.empty()) {
                output[q_idx[i].second] = -1;
            } else {
                output[q_idx[i].second] = pq.top().first;
            }
        }
        return output;
    }
};
