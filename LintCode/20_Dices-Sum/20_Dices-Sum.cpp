class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        vector<pair<int, double>> results;
        //dp[i][j]: the prob of the ith throw, and get the sum j.
        vector<vector<double>> dp(n + 1, vector<double>(6 * n + 1));
        
        for (int i = 1; i <= 6; ++i) dp[1][i] = 1.0 / 6;
        for (int i = 2; i <= n; ++i) {
            
            //throw i times, the sum range is [i .. 6 * i]
            for (int j = i; j <= 6 * i; ++j) {
                for (int k = 1; k <= 6; ++k) {
                    if (j >= k) dp[i][j] += dp[i - 1][j - k];
                }
                dp[i][j] /= 6.0;
            }
        }
      
      //  for (int j = n; j <= 6 * n; ++j) { 
      //        double sum = 0.0;
      //        for (int i = 1; i <= n; ++i) {
//                sum += dp[i][j];
  //          }
    //        results.push_back({j, sum});
        for (int i = n; i <= 6 * n; ++i) {
            results.push_back({i, dp[n][i]});
        }
          
        return results;
    }
};