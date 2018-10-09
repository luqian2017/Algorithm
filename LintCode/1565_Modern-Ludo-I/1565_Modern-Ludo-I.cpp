class Solution {
public:
    /**
     * @param length: the length of board
     * @param connections: the connections of the positions
     * @return: the minimum steps to reach the end
     */
    int modernLudo(int length, vector<vector<int>> &connections) {
        
        int shortCutCount = connections.size();
        map<int, int> shortCutMap;
        vector<int> dp(length + 1, INT_MAX);
        
        for (auto con : connections) {
            shortCutMap[con[0]] = con[1];
        }
        
        dp[1] = 0; //starting point is from 1
        
        for (int i = 2; i <= 7; ++i) dp[i] = 1;
        
        
        for (int i = 2; i <= length; ++i) {    
        
            if (i > 7) {
                for (int j = 1; j <= 6; ++j) {
                    dp[i] = min(dp[i], dp[i - j] + 1);
                }
            }
        
            if (shortCutMap.find(i) != shortCutMap.end()) {
                dp[shortCutMap[i]] = min(dp[i], dp[shortCutMap[i]]);
            }
        }
        
        return dp[length];
    }
};