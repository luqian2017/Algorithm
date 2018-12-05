class Solution {
public:
    /**
     * @param t: the length of the flight
     * @param dur: the length of movies 
     * @return: output the lengths of two movies
     */
    vector<int> aerial_Movie(int t, vector<int> &dur) {
        int len = dur.size();
        sort(dur.begin(), dur.end());
        int target = t - 30;
        int p1 = 0, p2 = len - 1;
        int minGap = INT_MAX;
        vector<int> result(2, 0);
        
        while (p1 < p2) {
            int sum = dur[p1] + dur[p2];
            if (sum > target) {
                p2--;
            } else if (sum == target) {
                result[0] = dur[p1];
                result[1] = dur[p2];
                return result;
            } else {
                int gap = target - sum;
                if (minGap > gap) {
                    minGap = gap;
                    result[0] = dur[p1];
                    result[1] = dur[p2];
                }
                p1++;
            }
        } 
        
        return result;
    }
};