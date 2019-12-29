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
            for (int j = i; j < n; ++j) {
                string substring = str.substr(i, j - i + 1);
                if (isPalindrome(substring)) count++;
            }
        } 
        return count;
    }
private:
    bool isPalindrome(string & str) {
        int n = str.size();
        if (n <= 1) return true;
        int i = 0, j = n - 1;
        while(i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};