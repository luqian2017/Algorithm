class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the maximum value
     */
    int getAnswer(vector<int> &a) {
        int len = a.size();
        if (len <= 1) return 0;
        
        int min_odd_so_far = INT_MAX;
        long long max_gap = 0;
        int odd_count = 0;

        for (int i = 0; i < len; ++i) {
            if (a[i] & 0x1) {
                min_odd_so_far = min(min_odd_so_far, a[i]);
                odd_count++;
            } else {
                max_gap = max(max_gap, (long long )a[i] - min_odd_so_far);  
            }
            
        }
        
        if (odd_count == 0 || odd_count == len) return 0;
        else return max_gap;
        
    }
};