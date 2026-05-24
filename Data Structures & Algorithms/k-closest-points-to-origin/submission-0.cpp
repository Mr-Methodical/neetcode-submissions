class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // we just need relative size so we don't have to use the distance formula we can take away the sqrt
        priority_queue<pair<int, int>> pq; // the first is distance and the next is the index:
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0];
            int y = points[i][1];
            int dist = x * x + y * y;
            if (pq.size() < k) {
                pq.push({dist, i});
            } else if (pq.top().first > dist) {
                pq.pop();
                pq.push({dist, i});
            }
            // other case it is greater than we don't need to include it
        }
        vector<vector<int>> result(k);
        int i = 0;
        while (!pq.empty()) {
            result[i++] = points[pq.top().second];
            pq.pop();
        }
        return result;
    }
};
