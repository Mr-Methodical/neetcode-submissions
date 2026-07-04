class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](auto& i1, auto& i2) { return i1[0] < i2[0]; });
        vector<vector<int>> output;
        for (int i = 0; i < (int)intervals.size() - 1; ++i) {
            if (intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
        }
        // so then this will update it and now we need to look at the best start
        for (int i = 0; i < (int)intervals.size(); ++i) {
            int s = intervals[i][0];
            while (i + 1 < intervals.size() && intervals[i + 1][0] == s) ++i;
            // the i we land is now the biggest interval so we add that
            output.push_back(intervals[i]);
        }
        return output;
    }
};
