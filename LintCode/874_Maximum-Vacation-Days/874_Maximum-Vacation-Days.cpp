class Solution {
public:
    /**
     * @param flights: the airline status from the city i to the city j
     * @param days: days[i][j] represents the maximum days you could take vacation in the city i in the week j
     * @return: the maximum vacation days you could take during K weeks
     */
    int maxVacationDays(vector<vector<int>> &flights, vector<vector<int>> &days) {
        int N = flights.size();  //# of city
        int K = days[0].size();  //# of week
        
        vector<vector<int>> dp(N + 1, vector<int>(K + 1, INT_MIN)); //dp[i][j] - the max vacation days of the ith city in the jth week
        dp[1][0] = 0;
        for (int i = 1; i <= K; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (int p = 1; p <= N; ++p) {
                    if (p == j || flights[p - 1][j - 1]) {
                        dp[j][i] = max(dp[j][i], dp[p][i - 1] + days[j - 1][i - 1]);
                    }
                }
            }
        }
        
        int result = 0;
        for (int i = 1; i <= N; ++i) {
            result = max(result, dp[i][K]);
        }
        
        return result;
    }
};