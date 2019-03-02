class Solution {
public:
    /**
     * @param nums: A list of integer
     * @return: An integer, maximum coins
     */
    int maxCoins(vector<int> &nums) {
        int N = nums.size();
        if (N == 0) return 0;
        
        vector<int> nums2;
        nums2.push_back(1);
        nums2.insert(nums2.end(), nums.begin(), nums.end());
        nums2.push_back(1);

        vector<vector<int>> dp(N + 2, vector<int>(N + 2, 0));
        
        for (int i = 0; i <= N; ++i) {
            dp[i][i + 1] = 0;
        }

        for (int i = 2; i <= N + 1; ++i) {
            for (int j = 0; i + j <= N + 1; ++j) {
                int maxV = 0;
                for (int k = j + 1; k < i + j; ++k) {
                    maxV = max(maxV, dp[j][k] + dp[k][i + j] + nums2[j] * nums2[i + j] * nums2[k]);
                }
                dp[j][i + j] = maxV;
            }
        }
        return dp[0][N + 1];
    }
};