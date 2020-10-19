class Solution {
public:
    /**
     * @param nums: a Integer list
     * @return: return the sum of subarrays
     */
    int SubArraySum(vector<int> &nums) {
        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            int left_count = i;
            int right_count = max(0, len - i - 1);
            #define array_sum(x) ((x * (x + 1)) >> 1)
            int array_sum = array_sum(len) - array_sum(left_count) - array_sum(right_count);
            sum += array_sum * nums[i];
        }
        
        return sum;
    }
};