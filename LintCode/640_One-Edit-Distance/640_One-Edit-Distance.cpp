class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        string shortStr, longStr;
        if (s.size() <= t.size()) {
            shortStr = s;
            longStr = t;
        } else {
            shortStr = t;
            longStr = s;
        } 
        
        int m = shortStr.size();
        int n = longStr.size();
        
        if (shortStr == longStr) return false;

        if (m < n - 1) return false;

        if (m == n) {
            int numOfDiff = 0;
            for (int i = 0; i < m; ++i) {
                if (shortStr[i] != longStr[i]) {
                    numOfDiff++;
                    if (numOfDiff > 1) return false;
                }
            }
            return numOfDiff == 1;
        }

        if (m == n - 1) {
            for (int i = 0; i < m; ++i) {  //up to shortStr.size()
                if (shortStr[i] != longStr[i]) return longStr.substr(i + 1) == shortStr.substr(i);
            }
            return true;
        }
    }
};