class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int len = s.size();
        if ((len == 0) || (len < k)) return 0;
        
        int l = 0, r = 0;
        int count = 0; //num of distinct characters
        int maxLen = 1;
        vector<int> dict(256, 0); //records the freqs of each ASCII character
        
        for (r = 0; r < len; ++r) {
            dict[s[r]]++;
            if (dict[s[r]] == 1) count++;
            
            while(count >= k && l < r) {
                maxLen = max(maxLen, r - l + 1);
                dict[s[l]]--;
                if (dict[s[l]] == 0) count--;
                ++l;
            }
        }
        
        return maxLen;
    }
};