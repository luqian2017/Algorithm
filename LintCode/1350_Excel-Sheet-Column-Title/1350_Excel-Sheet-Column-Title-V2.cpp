class Solution {
public:
    /**
     * @param n: a integer
     * @return: return a string
     */
    string convertToTitle(int n) {
        string res = "";
        n--;
        while (n >= 0) {
            res = (char)('A' + (n % 26)) + res;
            n /= 26;
            n--;
        }
        return res;
    }
};