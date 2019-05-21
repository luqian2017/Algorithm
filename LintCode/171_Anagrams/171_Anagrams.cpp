class Solution {
public
    
      @param strs A list of strings
      @return A list of strings
     
    vectorstring anagrams(vectorstring &strs) {
        int N = strs.size();
        if (N == 0) return vectorstring();
        
        mapvectorint, vectorstring mp;
        vectorstring result;
        
        for (int i = 0; i  N; ++i) {
            vectorint charMap(26, 0);
            int len = strs[i].size();
            for (int j = 0; j  len; ++j) {
                charMap[strs[i][j] - 'a']++;
            }
            mp[charMap].push_back(strs[i]);
        }
        
        for (auto m  mp) {
            if (m.second.size()  1) {
                for (auto s  m.second) result.push_back(s);
            }
        }
        
        return result;
    }

};