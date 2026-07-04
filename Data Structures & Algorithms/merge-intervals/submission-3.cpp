class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        sort(intervals.begin(), intervals.end(),
        [](auto& i1, auto& i2) { return i1[0] < i2[0]; });
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (output.back()[1] >= intervals[i][0]) {
                // if the next interval still in that interval
                // it could be contained in so we should take the max
                output.back()[1] = max(output.back()[1], intervals[i][1]);
            } else {
                // it is seperate
                output.push_back(intervals[i]);
                // it is fine to pass by reference, we will technically be 
                // updating the original array but will be only doing one pass
                // so it doesn't matter
            }
        }
        return output;
    }
};
