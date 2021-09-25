class Solution {
public:
    /**
     * @param nums: a binary array
     * @return: the maximum length of a contiguous subarray
     */
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<int> presums(n, 0);
        int maxLen = 0;
        presums[0] = nums[0]; 
        for (int i = 1; i < n; ++i) {
            presums[i] = presums[i - 1] + nums[i];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                //if (presums[j] * 2 == j + 1) {
                //    maxLen = max(maxLen, j + 1);
                //} else 
                if ((presums[j] - presums[i] + nums[i]) * 2 == (j - i + 1)) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};