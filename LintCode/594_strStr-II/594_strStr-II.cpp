class Solution {
public:
    /*
     * @param source: A source string
     * @param target: A target string
     * @return: An integer as index
     */
    int strStr2(const char* source, const char* target) {
        if (!source || !target) return -1;
        if (strlen(source) == 0 && strlen(target) == 0) return 0;
        if (strlen(source) && !strlen(target)) return 0;
        
        int lenS = strlen(source);
        int lenT = strlen(target);
        int BASE = 1e+6;
        
        if (lenS < lenT) return -1;
        
        int power31_lenT= 1;   // 31^lenT
        for (int i = 0; i < lenT; ++i) {
            power31_lenT = (power31_lenT * 31) % BASE;
        }
        
        int hashTgt = 0;
        for (int i = 0; i < lenT; ++i) {
            hashTgt = (hashTgt * 31 + target[i]) % BASE;
        }
        
        int hashSrc = 0;
        for (int i = 0; i < lenS; ++i) {
            
            hashSrc = (hashSrc * 31 + source[i]) % BASE;
            if (i < lenT) continue;
            
            // abcd - a
            hashSrc -= (source[i - lenT] * power31_lenT) % BASE;
            if (hashSrc < 0) 
                hashSrc += BASE;
            
            if (hashSrc == hashTgt) {
                for (int j = 0; j < lenT; ++j) {
                    if (source[i - lenT  + 1 + j] != target[j]) return -1;
                }
                return i - lenT + 1;
            }
        }
        
        return -1;
    }
};