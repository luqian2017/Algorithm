class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        int len = heights.size();
        if (len == 0) return 0;
        
        int lMax = 0, rMax = 0;
        int p1 = 0, p2 = len - 1;
        int sum = 0;
        
        while(p1 < p2) {
            if (lMax < heights[p1]) {
                lMax = heights[p1];
            }
            if (rMax < heights[p2]) {
                rMax = heights[p2];
            }
            
            if (lMax  < rMax) {
                sum += lMax - heights[p1];
                p1++;
            } else {
                sum += rMax - heights[p2];
                p2--;
            }
        }
        return sum;
        
    }
};

