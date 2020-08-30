class Solution {
public:
    /**
     * @param intervals: the intervals
     * @param rooms: the sum of rooms
     * @param ask: the ask
     * @return: true or false of each meeting
     */
    vector<bool> meetingRoomIII(vector<vector<int>> &intervals, int rooms, vector<vector<int>> &ask) {
        int askSize = ask.size();
        vector<bool> result;
        int intervalSize = intervals.size();
        vector<pair<int, int>> events; //<eventTime, eventType> eventType: 0 end, 1 start
        vector<int> counters(50000, -1);
        int count = 0;
        int maxTime = 0;
          
        for (int i = 0; i < intervalSize; ++i) {
            events.push_back({intervals[i][0], 1});
            events.push_back({intervals[i][1], 0});
            maxTime = max(maxTime, intervals[i][1]);
        }
      
        sort(events.begin(), events.end());
       
        for (int i = 0; i < events.size(); ++i) {
            if (events[i].second == 1) { //for start events
                count++;
            } else { //for end events
                count--;
            }
            counters[events[i].first] = count;
        }
        
        for (int i = 0; i < ask.size(); ++i) {
            maxTime = max(maxTime, ask[i][1]);
        }

        for (int i = 1; i <= maxTime; ++i) {
            if (counters[i] == -1 && counters[i - 1] > 0) counters[i] = counters[i - 1];
        }

        for (int i = 1; i <= maxTime; ++i) {
             if (counters[i] >= rooms) counters[i] = 1;
             else counters[i] = 0;
        }

        for (int i = 1; i <= maxTime; ++i) {
              counters[i] += counters[i - 1];
        }

        for (int i = 0; i < ask.size(); i++) {
            if (counters[ask[i][0] - 1] == counters[ask[i][1] - 1]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};