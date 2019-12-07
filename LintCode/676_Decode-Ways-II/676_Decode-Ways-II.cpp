class Solution {
public:
    /**
     * @param s: a message being encoded
     * @return: an integer
     */
    int numDecodings(string &s) {
        int n = s.size();
        if (n == 0) return 0;
        const long long mod = 1000000007;
        
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; //used to handle cases like s = "12" 
        
        if (s[0] == '0') dp[1] = 0;
        else if (s[0] == '*') dp[1] = 9;
        else dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            char curChar = s[i - 1];
            char prevChar = s[i - 2];
            
            if (curChar >= '1' && curChar <= '9') dp[i] = dp[i - 1];
            if (curChar == '*') dp[i] = dp[i - 1] * 9;
            
            if (prevChar != '*' && curChar != '*') {
                   int twoDigitNum = stoi(s.substr(i - 2, 2));
                if (twoDigitNum >= 10 && twoDigitNum <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
            else if (prevChar == '*' && curChar != '*') {
                if (curChar >= '0' && curChar <= '6') {
                    dp[i] += dp[i - 2] * 2;
                } else {//if (curChar >= '7' && curChar <= '9') {
                    dp[i] += dp[i - 2];
                }     
            }
            else if (prevChar != '*' && curChar == '*') {
                //cout<<"111 "<<dp[i - 2]<<" "<<dp[i - 1]<<endl;
                if (prevChar == '1') {
                    dp[i] += dp[i - 2] * 9; //it 
                } else if (prevChar == '2') {
                    dp[i] += dp[i - 2] * 6;
                }
            }
            else { //prevChar == '*' && curChar == '*'
                dp[i] += dp[i - 2] * 15; //26 - 11 = 15   
            }
        
            dp[i] %= mod;            
        }

        return dp[n];
    }
};