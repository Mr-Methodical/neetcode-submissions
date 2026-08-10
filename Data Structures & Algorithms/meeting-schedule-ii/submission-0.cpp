/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // let's have two arrays 
        vector<int> start(intervals.size());
        vector<int> end(intervals.size());
        for (int i = 0; i < intervals.size(); ++i) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }
        sort(start.begin(), start.end());;
        sort(end.begin(), end.end());
        int s = 0;
        int e = 0;
        int max_meet = 0;
        int curr_meet = 0;
        while (s != intervals.size()) { // s not at end
            // because it doesn't matter when e ends like once s ends
            // we are not going to get any more meetings
            if (start[s] < end[e]) {
                s++;
                curr_meet++;
            } else if (start[s] == end[e]) {
                // they cancel out
                s++;
                e++;
            } else {
                // end is actually smaller
                e++;
                curr_meet--;
            }
            max_meet = max(max_meet, curr_meet);
        }
        return max_meet;
    }
};

