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
        int intervalSize = intervals.size();
        vector<bool> result;
        vector<int> counters(50000, 0);
        vector<int> preSums(50000, 0);
        int count = 0;
        int maxTime = 0;
          
        for (int i = 0; i < intervalSize; ++i) {
            counters[intervals[i][0]]++;
            counters[intervals[i][1]]--;
            maxTime = max(maxTime, intervals[i][1]);
        }
      
        for (int i = 0; i < ask.size(); ++i) {
            maxTime = max(maxTime, ask[i][1]);
        }
        
        int sum = 0;  

        for (int i = 0; i <= maxTime; ++i) {
            sum += counters[i];
            preSums[i] = sum < rooms ? 0 : 1;
        }
        
        for (int i = 1; i <= maxTime; ++i) {
            preSums[i] += preSums[i - 1];
        }
        
        for (int i = 0; i < ask.size(); i++) {
            if (preSums[ask[i][0] - 1] == preSums[ask[i][1] - 1]) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};