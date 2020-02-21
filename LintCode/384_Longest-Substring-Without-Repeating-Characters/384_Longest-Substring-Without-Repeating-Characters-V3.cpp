class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string &s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<int> positions(256, -1);
        
        int p1 = 0, p2 = 0;
        int maxLen = 0;
        while(p2 < n) {
            while (p2 < n && positions[s[p2]] < 0) {
                positions[s[p2]] = p2;
                p2++;
            }
            
            if (p2 < n && positions[s[p2]] >= 0) {
               // maxLen = max(maxLen, p2 - positions[s[p2]]);
                maxLen = max(maxLen, p2 - p1);
                p1 = max(p1, positions[s[p2]] + 1);
                
                positions[s[p2]] = p2;
                p2++;
            }
        }
        maxLen = max(maxLen, p2 - p1);
        return maxLen;
    }
};