class Solution {
public:
    /**
     * @param s: the string s
     * @return: the number of operations at least
     */
    int numberOfOperations(string &s) {
        int n = s.size();
        if (n <= 1) return 0;
        
        int count = 0;
        int i = 0, j = n - 1;
        while(i < j) {
            if (s[i] != s[j]) count += abs(s[j] - s[i]);
            i++;
            j--;
        }
        
        return count;
    }
};