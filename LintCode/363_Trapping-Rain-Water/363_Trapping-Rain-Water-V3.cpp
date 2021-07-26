class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int res = 0;        
        int maxHeight_pos = 0, maxHeight = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                maxHeight_pos = i;
            }
        }
        int maxLeft = heights[0]; 
        for (int i = 1; i < maxHeight_pos; ++i) {
            if (heights[i] > maxLeft) {
                maxLeft = heights[i];
            } else {
                res += maxLeft - heights[i];
            }
        }
        int maxRight = heights[n - 1];
        for (int i = n - 1; i > maxHeight_pos; --i) {
            if (heights[i] > maxRight) {
                maxRight = heights[i];
            } else {
                res += maxRight - heights[i];
            }
        } 

        return res;
    }
};