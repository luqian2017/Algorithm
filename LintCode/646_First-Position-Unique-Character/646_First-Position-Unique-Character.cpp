class Solution {
public:
    /**
     * @param s: a string
     * @return: it's index
     */
    int firstUniqChar(string &s) {
        int len = s.size();
        if (len == 0) return -1;
        
        vector<int> charTable(255, 0);

        for (int i = 0; i < len; ++i) {
            charTable[s[i]]++;
        }
        
        for (int i = 0; i < len; ++i) {
            if (charTable[s[i]] == 1) return i;    
        }
        
        return -1;
    }
};