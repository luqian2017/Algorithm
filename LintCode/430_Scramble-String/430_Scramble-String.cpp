class Solution {
public:
    /**
     * @param s1: A string
     * @param s2: Another string
     * @return: whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        if (s1 == s2) return true;
        
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 != len2) return false;
        
        int hash1 = 0, hash2 = 0;
        for (int i = 0; i < len1; ++i) {
            hash1 += s1[i] - 'a';
            hash2 += s2[i] - 'a';
        }
        if (hash1 != hash2) return false;
        
        for (int i = 1; i < len1; ++i) {
            string s11 = s1.substr(0, i);
            string s21 = s2.substr(0, i);
            string s12 = s1.substr(i);
            string s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) 
                return true;
            
            s11 = s1.substr(len1 - i);
            s21 = s2.substr(0, i);
            s12 = s1.substr(0, len1 - i);
            s22 = s2.substr(i);
            if (isScramble(s11, s21) && isScramble(s12, s22)) 
                return true;
        }
        return false;
    }
    
};