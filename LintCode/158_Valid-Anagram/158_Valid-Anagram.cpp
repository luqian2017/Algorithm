class Solution {
public:
    /**
     * @param s: The first string
     * @param t: The second string
     * @return: true or false
     */
    bool anagram(string &s, string &t) {
        vector<int> counterS(128, 0);
        vector<int> counterT(128, 0);
        
        int lenS = s.size();
        int lenT = t.size();
        
        for (int i = 0; i < lenS; ++i) {
            counterS[s[i]]++;
        }
        
        for (int i = 0; i < lenT; ++i) {
            counterT[t[i]]++;
        }
        
        for (int i = 0; i < 128; ++i) {
            if ((counterS[i] != counterT[i])) return false;
        }
        
        return true;
    }
};