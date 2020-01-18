
bool compare(const vector<int> & a, const vector<int> & b)  {
    if (a[0] < b[0]) return true;
    if (a[0] == b[0]) return a[1] < b[1];
    return false;
}
    
class Solution {
public:
    /**
     * @param pairs: pairs of numbers
     * @return: the length longest chain which can be formed
     */
    int findLongestChain(vector<vector<int>> &pairs) {
        int m = pairs.size();
        if (m == 0) return 0;
        int n = pairs[0].size();
        if (n == 0) return 0;
        
        sort(pairs.begin(), pairs.end(), compare);
        vector<int> dp(m, 1); //note it is 1

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
        return dp[m - 1];        
    }
};