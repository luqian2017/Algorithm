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

class Solution {
public:
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        int insert_pos = 0;
        for (int i = 0; i < n; ++i) {
            if (intervals[i].end < newInterval.start) {
                res.push_back(intervals[i]);
                insert_pos = i + 1;
            } else if (intervals[i].start > newInterval.end) {
                res.push_back(intervals[i]);
            } else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
       // cout << "insert_pos=" << insert_pos << endl;
        res.insert(res.begin() + insert_pos, newInterval);
        return res;
    }
};