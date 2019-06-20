/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

struct cmp {
    bool operator() (Interval & a, Interval & b) {
        return a.start < b.start;
    }
} compare;

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        
        for (int i = 0; i < n - 1; ++i) {
            if (intervals[i].end > intervals[i + 1].start) return false;
        }
        
        return true;
    }
};