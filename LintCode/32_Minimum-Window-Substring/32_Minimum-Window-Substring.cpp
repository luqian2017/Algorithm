class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        int ns = source.size();
        int nt = target.size();
        
        map<char, int> mp;
        for (int i = 0; i < nt; ++i) {
            mp[target[i]]++;
        }
        int count = mp.size();
        
        int p1 = 0, p2 = 0;
        int minLen = INT_MAX;
        string minResult;
        
        while(p1 < ns) {
            while(p2 < ns && count > 0) {
                mp[source[p2]]--;
                if (mp[source[p2]] == 0) count--;
                p2++;
                if (count == 0) break;
            }
            
            if (count == 0) {
                int curWinSize = p2 - p1;// + 1;
                if (curWinSize < minLen) {
                    minLen = curWinSize;
                    minResult = source.substr(p1, curWinSize);
                }
            }
    
            if (mp[source[p1]] == 0) count++;
            mp[source[p1]]++;
            p1++;
        }
        
        return minResult;
    }
};