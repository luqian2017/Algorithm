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

struct event {
    int eventTime;
    int eventType;  //start = 0, end = 1
    event(int eTime, int eType) : eventTime(eTime), eventType(eType) {}
};

struct cmp {
    bool operator () (event & a, event &b) {
        if (a.eventTime < b.eventTime) {
            return true;
        } else if (a.eventTime == b.eventTime) {
            return a.eventType < b.eventType;
        } else {
            return false;
        }
    }    
} compare;


class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int intervalSize = intervals.size();
        if (intervalSize == 0) return 0;
        
        vector<event> events;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < intervalSize; ++i) {
            events.push_back(event(intervals[i].start, 0));
            events.push_back(event(intervals[i].end, 1));
        }
        sort(events.begin(), events.end(), compare);
        
        int eventSize = events.size();
        for (int i = 0; i < eventSize; ++i) {
            if (events[i].eventType == 0) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count--;
            }
        }
        
        return maxCount;
    }
};