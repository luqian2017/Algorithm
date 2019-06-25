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
        if (a.start < b.start) return true;
        if (a.start == b.start) return a.end < b.end;
        return false;
    }
}compare;

class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the minimal points number
     */
    int getAns(vector<Interval> &a) {
        int n = a.size();
        if (n == 0) return 0;
        sort(a.begin(), a.end(), compare);
        int result = 1;
        int rangeLeft = a[0].start;
        int rangeRight = a[0].end;
        
        for (int i = 1; i < n; ++i) {
            if (a[i].start <= rangeRight) {
                rangeRight = min(a[i].end, rangeRight);
            } else {
                result++;
                rangeLeft = a[i].start;
                rangeRight = a[i].end;
            }
            
        }
        
        return result;
    }
};