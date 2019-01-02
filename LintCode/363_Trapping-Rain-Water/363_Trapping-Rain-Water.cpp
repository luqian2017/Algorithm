class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int len = heights.size();
        if (len == 0) return 0;
        
        int maxHeight = 0;
        int maxIndex = 0;
        
        for (int i = 0; i < len; ++i) {
            if (maxHeight < heights[i]) {
                maxHeight = heights[i];
                maxIndex = i;
            }
        }
        
        int sum = 0;
        maxHeight = 0;
        for (int i = 0; i < maxIndex; ++i) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            } else {
                maxHeight = heights[i];
            }
        }
        
        maxHeight = 0;
        for (int i = len - 1; i > maxIndex; --i) {
            if (maxHeight > heights[i]) {
                sum += maxHeight - heights[i];
            } else {
                maxHeight = heights[i];
            }
        }
        
        return sum;
    }
};