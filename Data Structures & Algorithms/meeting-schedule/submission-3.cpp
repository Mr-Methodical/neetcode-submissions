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
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](const Interval& i1, const Interval& i2) { return i1.start < i2.start; });
        // now we have it in sorted order with the meeting times coming first
        for (int i = 0; i < (int)intervals.size() - 1; ++i) {
            // the end of one session goes into the next sessions time
            if (intervals[i].end > intervals[i + 1].start) {
                return false;
            }
        }
        return true;
    }
};
