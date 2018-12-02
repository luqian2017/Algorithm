class Solution {
public:
    /**
     * @param s: the string s
     * @param k: the maximum length of substring
     * @return: return the least number of substring
     */
    int getAns(string &s, int k) {
        int len = s.size();
        if (len == 0 || k < 0) return 0;
        
        int count = 1;
        int totalNum = 1;
        
        for (int i = 1; i < len; ++i) {
            if ((s[i] != s[i - 1])) {
                totalNum++;
                count = 1;
            } else {
                if (count < k) {
                    count++;
                } else if (count == k) {
                    count = 1;
                    totalNum++;
                }
            }
        }
        
        return totalNum;
    }
};