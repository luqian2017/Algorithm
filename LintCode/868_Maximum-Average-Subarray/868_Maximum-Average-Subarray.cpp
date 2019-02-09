#include limits

class Solution {
public
    
      @param nums an array
      @param k an integer
      @return the maximum average value
     
    double findMaxAverage(vectorint &nums, int k) {
        int len = nums.size();
        if (len == 0  len  k) return 0.0;
        
        double result = 0.0;
        double maxResult = numeric_limitsdoublelowest();
        
        double windowSum = 0;
        
        for (int i = 0; i  len; ++i) {
            windowSum += nums[i];
            if (i = k) windowSum -= nums[i - k];
            maxResult = max(maxResult, windowSum);
        }
        
        return maxResult  k;
    }
};