class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        
        int index = 0, pos = 0;
        int sum = 0;
        while(index < n) {
            sum += nums[index];
            if (sum > maxSum) {
                maxSum = sum;
            }
            if (sum <= 0) {
                sum = 0;
                pos = index;
            } 
            index++;
        }
        return maxSum;
    }
};