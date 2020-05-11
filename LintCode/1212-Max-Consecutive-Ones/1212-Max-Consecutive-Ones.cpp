class Solution {
public:
    /**
     * @param nums: a binary array
     * @return:  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int len = 0, max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                len++;
                max_len = max(max_len, len);
            } else {
                len = 0;
            }
        }
        
        return max_len;
    }
};