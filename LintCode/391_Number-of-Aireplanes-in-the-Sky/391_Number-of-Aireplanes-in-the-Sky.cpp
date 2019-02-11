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
    int eventType;
    event(int ti, int ty) : eventTime(ti), eventType(ty) {}
};

struct cmp{
    bool operator() (event & a, event & b) {
        if (a.eventTime < b.eventTime) {
            return true;
        } else if (a.eventTime == b.eventTime) {
            return a.eventType > b.eventType;
        } else {
            return false;
        }
    }
} compare;

class Solution {
public:
    /**
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        int count = 0, maxCount = 0;
        int len1 = airplanes.size();
        vector<event> events;
    
        for (int i = 0; i < len1; ++i) {
            events.push_back(event(airplanes[i].start, 0));
            events.push_back(event(airplanes[i].end, 1));
        } 
        
        sort(events.begin(), events.end(), compare);
    
        int len2 = events.size();
        
        for (int i = 0; i < len2; ++i) {
            if (events[i].eventType == 0) {
                count++;
                maxCount = max(maxCount, count);
            }
            else count--;
        }
        
        return maxCount;
    }
};