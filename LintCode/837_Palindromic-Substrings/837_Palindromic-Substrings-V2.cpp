class Solution {
public:
    /**
     * @param str: s string
     * @return: return an integer, denote the number of the palindromic substrings
     */
    int countPalindromicSubstrings(string &str) {
        int n = str.size();
        if (n <= 1) return n;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            calPalindrom(str, i, i, count);         
            calPalindrom(str, i, i + 1, count);
        }
        return count;
    }

private:
    void calPalindrom(string & str, int start, int end, int & count) {
        int n = str.size();
        while(start >= 0 && end < n) {
            if (str[start] == str[end]) {
                count++;
                start--;
                end++;
            } else {
                break;
            }
        }
    } 
};