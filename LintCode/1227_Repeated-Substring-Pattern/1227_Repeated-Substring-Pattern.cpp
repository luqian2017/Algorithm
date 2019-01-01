class Solution {
public:
    /**
     * @param s: a string
     * @return: return a boolean
     */
    bool repeatedSubstringPattern(string &s) {
        int len = s.size();
        if (len & 0x1) return false;
        int halfLen = len >> 1;
        for (int i = 1; i <= halfLen; ++i) {
            string seg = s.substr(0, i);
            if (len % i != 0) continue;    //去掉不可能的情况
            int multi = len / i;
            bool isRepeated = true;
            for (int j = 0; j < multi; ++j) {
                if (s.substr(j * i, i) != seg) {
                    isRepeated = false;
                    break;
                }
            } 
            if (isRepeated) return true;
        }
        return false;
    } 
};