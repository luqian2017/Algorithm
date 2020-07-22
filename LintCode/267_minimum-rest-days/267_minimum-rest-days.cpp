class Solution {
public:
    /**
     * @param company: Company business
     * @param gym: Gym business
     * @return: Find the shortest rest day
     */
    int minimumRestDays(vector<int> &company, vector<int> &gym) {
        int n = company.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        //dp[i][j] is the minimum reset days up to the ith day when the activity is j. j = 0 - work, 1 - gym, 2 - rest
        
        dp[0][2] = 1;
        if (company[0] == 1) dp[0][0] = 0;
        if (gym[0] == 1) dp[0][1] = 0;
        
        for (int i = 1; i < n; ++i) {
            if (company[i] == 1) {
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]);
            }
            if (gym[i] == 1) {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
            }
            dp[i][2] = min(dp[i - 1][2], min(dp[i - 1][0], dp[i - 1][1])) + 1;
        }
        
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};