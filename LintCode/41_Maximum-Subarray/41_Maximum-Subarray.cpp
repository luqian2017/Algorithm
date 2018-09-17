class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> &nums) {
        int result = INT_MIN;
        int sum = 0;
        if (nums.size() == 0) return 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        
        return result;
    }
};