class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        int len = s.size();
        if (len == 0) return 0;
        
        vector<int> table(255, -1);
        int pos = 0;
        int maxSegLen = 0;
        
        for (int i = 0; i < len; ++i) {
            if (table[s[i]] >= pos) { //it shows a repetitive char appears and it should be after pos! 
                pos = table[s[i]] + 1;    
            }
            table[s[i]] = i;
            maxSegLen = max(maxSegLen, i - pos + 1); //for both cases: repetitive and non-repetitive
        }
        
        return maxSegLen;
    }
};