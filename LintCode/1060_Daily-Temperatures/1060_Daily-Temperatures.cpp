class Solution {
public:
    /**
     * @param temperatures: a list of daily temperatures
     * @return: a list of how many days you would have to wait until a warmer temperature
     */
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                result[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) {
            result[s.top()] = 0;
            s.pop();
        }
        
        return result;
    }
};