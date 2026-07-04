class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // this new interval basically tells us what we need to combine
        vector<vector<int>> output;
        int n = intervals.size();
        if (n == 0) return {newInterval};
        // the first phase should be all them guaranteed less
        int i = 0; 
        while (i < n && newInterval[0] > intervals[i][1]) {
            // start of new_interval is greater than the end of current interval
            output.push_back(intervals[i]); // push on copy
            i++;
        }
        // all we know is that the last value's end was before our newInterval current
        // says nothing about current really so we will have to check
        // we also know though that the first value of the new interval is less than or equal to our current last value
        while (i < n && newInterval[1] >= intervals[i][0]) {
            // so we know that it intersects new region
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]); // technically it could be after as well
            i++;
        }
        output.push_back(newInterval);
        // now the rest are bigger intervals so we can just push them on
        while (i < n) {
            output.push_back(intervals[i]);
            i++;
        }
        return output;
    }
};
