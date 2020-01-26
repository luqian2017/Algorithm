class Solution {
public:
    /*
     * @param nums: a list of integers
     * @return: A integer indicate the sum of minimum subarray
     */
    int minSubArray(vector<int> &nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int sum = 0, minSum = INT_MAX;
        while (end < n && start <= end) {
            sum += nums[end];
            minSum = min(minSum, sum);
            if (sum > 0) {
                start = nums[end] > 0 ? end + 1 : end;
                end = start;
                sum = 0; // nums[start];
            }
            else {
                end++;
            }
        }
        
        return min(minSum, nums[n - 1]);
    }
};