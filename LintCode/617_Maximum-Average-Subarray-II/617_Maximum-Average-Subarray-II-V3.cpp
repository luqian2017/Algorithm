class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        int len = nums.size();
        if (len == 0 || len < k) return 0;
       
        double maxAve = nums[0], minAve = nums[0], midAve = nums[0];
        
        for (int i = 1; i < len; ++i) {
            maxAve = max(maxAve, (double)nums[i]);
            minAve = min(minAve, (double)nums[i]);
        }

        while(maxAve - minAve > 1e-5) {
            midAve = minAve + (maxAve - minAve) / 2;
            if (canFind(nums, k, midAve)) {
                //the midAve is too small
                minAve = midAve;
            } else {
                //the midAve is too large
                maxAve = midAve;
            }
        }
        
        return minAve;
    }
    
private: 
    bool canFind(vector<int> &nums, int k, double mid) {
        double rightSum = 0, leftSum = 0;
        double minLeftSum = 0; //numeric_limits<double>::max();
        int len = nums.size();
        
        for (int i = 0; i < k; ++i) {
            rightSum += nums[i] - mid;
        }
        
        for (int i = k; i < len; ++i) {
            if (rightSum - minLeftSum >= 0) return true;

            rightSum += nums[i] - mid;
            leftSum += nums[i - k] - mid;
            minLeftSum = min(minLeftSum, leftSum);
        }
        
        //need to consider the case of i == len - 1
        if (rightSum - minLeftSum >= 0) return true;

        return false;
    }
};