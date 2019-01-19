class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int maxLen = 0;
        int l = 0, r = 0;
        int len = s.size();
        if (len == 0 || k == 0) return 0;
        
        vector<int> dict(256, 0);
        int count = 0;
        
        for (int r = 0; r < len; ++r) {
            ++dict[s[r]];
            if (dict[s[r]] == 1) count++;
            
            while (count > k) {
                dict[s[l]]--;
                if (dict[s[l]] == 0) count--;
                ++l;
            }
            
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};