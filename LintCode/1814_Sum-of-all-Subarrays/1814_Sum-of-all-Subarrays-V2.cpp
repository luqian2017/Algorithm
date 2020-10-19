class Solution {
public:
    /**
     * @param nums: a Integer list
     * @return: return the sum of subarrays
     */
    int SubArraySum(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += nums[i] * (i + 1) * (n - i);
        }
        return count;
    }
};