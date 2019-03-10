class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        int m = word1.size();
        int n = word2.size();
        if (m == 0) return n;
        if (n == 0) return m;
        
        vector<int> prev(n + 1);
        vector<int> next(n + 1);
            
        for (int i = 0; i <= n; ++i) {
            prev[i] = i;
        }
        
        for (int i = 1; i <= m; ++i) {
            next[0] = i;
            for (int j = 1; j <= n; ++j) {
               if (word1[i - 1] == word2[j - 1]) {
                   next[j] = prev[j - 1];
               } else {
                   next[j] = min(min(prev[j], next[j - 1]), prev[j - 1]) + 1;
               }
            }
            prev = next;
        }
        
        return next[n];
    }
};