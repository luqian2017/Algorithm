class Solution {
public:
    /**
     * @param n: The folding times
     * @return: the 01 string
     */
    string getString(int n) {
        
        string s = "0";
        for (int i = 2; i <= n; ++i) {
            string reverseS;
            int len = s.size();
            s.push_back('0');
            for (int j = 0; j < len; ++j) {
                s.push_back(1 ^ (s[len - 1 - j] - '0') + '0');
            }
        }
        
        return s;
        
    }
};