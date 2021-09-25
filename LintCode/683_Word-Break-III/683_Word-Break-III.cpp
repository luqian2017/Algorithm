class Solution {
public:
    /**
     * @param s: A string
     * @param dict: A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string &s, unordered_set<string> &dict) {
        int n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        unordered_set<string> dict2;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            string str = *it;
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            dict2.insert(str);
        }
        vector<int> dp(n + 1, 0); //dp[i] is the # of sentences with s[0..i-1]
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (dict2.find(s.substr(i - 1, j - i + 1)) != dict2.end()) {
                    dp[j] += dp[i - 1];
                }
            }
        }
        return dp[n];
    }
};
