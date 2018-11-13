class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
        long long kDistinctCharacters(string &s, int k) {
        long long len=0;
        int sSize = s.size();
        if (sSize < k) return 0;
    
        map<char, int> m;

        int start = 0, end = 0;
    
        while(start < sSize - k + 1) {
            end = start;
            m.clear();
            while (end < sSize) {
                if (m.size() < k) {
                    if (m.find(s[end]) == m.end()) {
                        m[s[end]] = 1;
                        if (m.size() == k) {
                              len += sSize - end;
                              //since from [start..end] to [start..sSize] all contains at least k distinct characters, we do not need to extend end, but just restart by extending start;
                            break;
                        }
                    } else {
                        m[s[end]]++;
                       
                    }     
                    end++;
                }
            }
            start++;
        }
        return len;
    }

    
};