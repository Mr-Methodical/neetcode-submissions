class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // we could just do something like remove it if it going into the next noe
        // [1,3][2,4][3,5]
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        // the idea is that what should happen 
        int count = 0;
        int overlap = INT_MIN;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] < overlap) {
                count++;
                // overlap should be the smallest of two, we will get rid of which
                // ever one is going farther
                // you can htink of overlap as the past one
                overlap = min(intervals[i][1], overlap);
            } else {
                // if we don't end up having any then we go with the new value
                overlap = intervals[i][1];
            }
        } 
        return count;
    }
};
