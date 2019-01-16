class Solution {
public:
    /**
     * @param nums: an array of integers
     * @param s: An integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int len = nums.size();
        if (len == 0) return -1;
        
        int left = 0;
        int minLen = INT_MAX;
        int sum = 0;
        
        for (int right = 0; right < len; ++right) {
            sum += nums[right];
            while (sum >= s) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
    
        return (minLen == INT_MAX) ? -1 : minLen;
    }
};