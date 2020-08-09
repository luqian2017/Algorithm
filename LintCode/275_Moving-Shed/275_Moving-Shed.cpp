class Solution {
public:
    /**
     * @param stops: An array represents where each car stops.
     * @param k: The number of cars should be covered.
     * @return: return the minimum length of the shed that meets the requirements.
     */
    int calculate(vector<int> &stops, int k) {
        int len = stops.size();
        if (len < k) return -1;
        int result = 0;
        sort(stops.begin(), stops.end());
        if (k == len) return stops[len - 1] - stops[0] + 1;
        
        for (int i = k; i < len; ++i) {
            result = max(result, stops[i] - stops[i - k]);
        }
        
        return result;
    }
};
