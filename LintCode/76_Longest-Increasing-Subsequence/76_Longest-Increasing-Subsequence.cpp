class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> &nums) {
        int numSize = nums.size();
        if (numSize <= 1) return numSize;
        
        vector<int> DP(numSize, 0);
        int g_maxLen = 0;
        int g_maxId = 0;
    
        DP[0] = 1;
        for (int i = 1; i < numSize; ++i) {
            int maxLen = 0;
            int maxId = 0;
            
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (DP[j] > maxLen) {
                        maxLen = DP[j];
                        maxId = j;
                    }
                }
            }
            
            DP[i] = maxLen + 1;
        
            if (DP[i] > g_maxLen) {
                g_maxLen = DP[i];
                g_maxId = i;
            }
        }
        
        return g_maxLen;
    }
};