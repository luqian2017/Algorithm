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
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    vector<Interval> mergeTwoInterval(vector<Interval> &list1, vector<Interval> &list2) {
        if (list1.size() == 0) return list2;
        else if (list2.size() == 0) return list1;
        
        vector<Interval> result;
        
        int p1 = 0, p2 = 0;
        Interval itv;
        if (list1[p1].start < list2[p2].start) 
            itv = Interval(list1[p1].start, list1[p1].end);
        else
            itv = Interval(list2[p2].start, list2[p2].end);
            
        while ((p1 < list1.size()) || (p2 < list2.size())) {
            
            if (p1 < list1.size() && isOverlapping(list1[p1], itv)) {
                itv = merging(list1[p1], itv);
                p1++;
            } else if (p2 < list2.size() && isOverlapping(list2[p2], itv)) {
                itv = merging(list2[p2], itv);
                p2++;
            } else {
                result.push_back(itv);
                if (p1 < list1.size() && p2 < list2.size()) {
                    if (list1[p1].start < list2[p2].start) 
                        itv = Interval(list1[p1].start, list1[p1].end);
                    else
                        itv = Interval(list2[p2].start, list2[p2].end);
                } else if (p1 < list1.size())
                    itv = Interval(list1[p1]);
                else 
                    itv = Interval(list2[p2]);
            }
        }
        
        result.push_back(itv);
        
        return result;
    }
    
private:
    bool isOverlapping(Interval const & itv1, Interval const & itv2) {
        if ((itv1.end >= itv2.start) && (itv1.end <= itv2.end))  return true;
        if ((itv2.end >= itv1.start) && (itv2.end <= itv1.end))  return true;
        return false;
    }
    
    Interval merging(Interval const & itv1, Interval const & itv2) {
        return Interval(min(itv1.start, itv2.start), max(itv1.end, itv2.end));
    }
};