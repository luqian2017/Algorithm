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
     * @param intervals: the given k sorted interval lists
     * @return:  the new sorted interval list
     */
    vector<Interval> mergeKSortedIntervalLists(vector<vector<Interval>> &intervals) {
        int len = intervals.size();
        vector<Interval> result;
        map<int, int> mp; 
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < intervals[i].size(); ++j) {
                if (mp.find(intervals[i][j].start) == mp.end()) {
                    mp[intervals[i][j].start] = 1;
                } else {
                    mp[intervals[i][j].start]++;
                }
                
                if (mp.find(intervals[i][j].end) == mp.end()) {
                    mp[intervals[i][j].end] = -1;
                } else {
                    mp[intervals[i][j].end]--;
                }
            }
        }

        int count = 0;
        int start = 0, end = 0;
        bool newInterval = true;
        for (auto i : mp) {
            if (newInterval) {
                start = i.first;
            }
            count += i.second;
            if (count == 0) {
                end = i.first;
                result.push_back(Interval(start, end));
                newInterval = true;
            } else {
                newInterval = false;
            }
        }
        
        return result;
    }
};