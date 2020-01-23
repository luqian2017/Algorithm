class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        int n = s.size();
        vector<int> count(256, 0);
        int p1 = 0, p2 = 0;
        
        int maxLen = 0;
        while(p2 < n) {
            count[s[p2]]++;
            if (count[s[p2]] > 1) {
                while(p1 < p2) {
                    count[s[p1]]--;
                    p1++;
                    if (s[p1-1] == s[p2]) break;   
                }
            }
            maxLen = max(maxLen, p2 - p1 + 1);
            p2++;
        }
        
        return maxLen;
    }
}; 