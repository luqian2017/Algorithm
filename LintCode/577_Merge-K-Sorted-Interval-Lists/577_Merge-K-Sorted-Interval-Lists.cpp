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

class cmp {
public: 
    bool operator() (tuple<int, int, Interval> &a, tuple<int, int, Interval> &b) {
        return get<2>(a).start > get<2>(b).start;
    }
};

class Solution {
public:

    /**
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        int len = intervals.size();
        vector<Interval> result;
        //tuple<int, int, Inteval>  is for i,j,intervals[i][j]
        priority_queue<tuple<int, int, Interval>, vector<tuple<int, int, Interval>>, cmp> pq;
        
        //push the head interval of each vector (if not empty) into pq
        for (int i = 0; i < len; ++i) {
            if (intervals[i].size() != 0) {
                pq.push(make_tuple(i, 0, intervals[i][0]));
            }
        }
        
        while(!pq.empty()) {
            tuple<int, int, Interval> head = pq.top();
            pq.pop();
            result.push_back(get<2>(head));
            get<1>(head)++;
            if (get<1>(head) < intervals[get<0>(head)].size()) {
                get<2>(head) = intervals[get<0>(head)][get<1>(head)];
                pq.push(head);
            }
        }
        
        return merge(result);
        
    }

private:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;
        
        vector<Interval> result;
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        
        for (auto interval: intervals) {
            if (interval.start <= end) {
                end = max(end, interval.end);
            } else {
                //no conflict, push_back current interval to result
                result.push_back(Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
         }
         //push_back the last one
         result.push_back(Interval(start, end));
         return result;
    }

};