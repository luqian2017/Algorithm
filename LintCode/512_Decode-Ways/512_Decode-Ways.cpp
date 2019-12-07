class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        
        for (int i = 2; i <= n; ++i) {
            int curDigit = s[i - 1] - '0';
            if (curDigit >= 1 && curDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            
            //int cur2Digits = stoi(to_string(s[i - 2] + s[i - 1]));
            int cur2Digits = stoi(s.substr(i - 2, 2));
           
            if (cur2Digits >= 10 && cur2Digits <= 26) {
                dp[i] += dp[i - 2];
            }
        
            if (dp[i] == 0) return 0; // it shows its an invalid string
        }

        return dp[n];
    }
};
