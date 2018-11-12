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


bool compare(Interval &a, Interval &b) {
    if (a.start == b.start) {
        return a.end < b.end;
    } else {
        return a.start < b.start;
    }
}

class Solution {
public:


    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval> result;
        int len = intervals.size();
        if (len == 0) return result;
        if (len == 1) {
            result.push_back(intervals[0]);
            return result;
        }
        
        Interval itv;
        sort(intervals.begin(), intervals.end(), compare);
        itv = intervals[0];
        for (int i = 0; i < len - 1; ++i) {
            
            if (overlapping(itv, intervals[i + 1])) {
                itv.end = max(itv.end, intervals[i + 1].end);
                continue;
            }
            result.push_back(itv);
            itv = intervals[i + 1];
        }
        
        result.push_back(itv);
        return result;
    }
    
private:
    bool overlapping(Interval &a, Interval &b) {
        
        return ((a.end >= b.start) && (a.end <= b.end)) ||
               ((b.end >= a.start) && (b.end <= a.end));    
    }
    
};