class Solution {
public:
    /**
     * @param s: a string
     * @param p: a string
     * @return: a list of index
     */
    vector<int> findAnagrams(string &s, string &p) {
        int lenS = s.size();
        int lenP = p.size();
        
        vector<int> result;
        
        if ((lenS == 0) || (lenP == 0) || (lenS < lenP)) return result;
        
        vector<int> table(26, 0);
        
        for (int i = 0; i < lenP; ++i) {
            table[p[i] - 'a'] += 1;
        }
        
        int start = 0, end = 0, count = 0;
        
        while(end < lenS) {
            int index = s[end] - 'a';
            if (table[index] > 0) {
                count++;
            }
            table[index]--;
            
            if (end - start + 1 == lenP) {
                if (count == lenP) {
                    result.push_back(start);
                }
                int origIndex = s[start] - 'a';
                if (table[origIndex] >= 0) {
                    count--;
                }
                table[origIndex]++;
                start++; end++;
            } else {
                end++;
            }
        }
        
        return result;
    }
};