/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * 
 * }
 */

class Solution {
public:
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int len = intervals.size();
        vector<Interval> result;
        if (len == 0) {
            result.push_back(newInterval);
            return result;
        }
        
        for (int i = 0; i < len; ++i) {
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(intervals[i]);
            } else {
                result.back().start = min(result.back().start, newInterval.start);
                result.back().end = max(result.back().end, newInterval.end);
            }
        }
        
        return result;        
    }
    
};