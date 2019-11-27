
class Solution {
public:
    /**
     * @param S: a string
     * @return: return a string
     */
    string reorganizeString(string &S) {
        int n = S.size();
        string result;
        if (n == 0) return result;
        
        int thresh = (n & 0x1) ? n / 2 + 1 : n / 2;
        
        unordered_map<char, int> um;
        int maxFreq = 0, maxId = 0;
        for (int i = 0; i < n; ++i) {
            um[S[i]]++;
            if (maxFreq < um[S[i]]) {
                maxFreq = um[S[i]];
                if (maxFreq > thresh) return result;
                maxId = i;
            }
        }
      
        result.resize(n, S[maxId]);
        int p1 = 0, p2 = 1;
        while(p1 < n && p2 < n) {
            while (p1 < n && S[p1] == S[maxId]) p1++;
            if (p1 == n) break;
            result[p2] = S[p1++];
            p2 += 2;
        }
        
        return result;
    }
};