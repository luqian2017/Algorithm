class Solution {
public:
    /**
     * @param S: a string
     * @param K: a integer
     * @return: return a string
     */
    string licenseKeyFormatting(string &S, int K) {
        int n = S.size();
        if (n < K) return S;
        
        string newS;
        int pos = n - 1;
        int count = 0;
        while (pos >= 0) {
            if (S[pos] != '-') {
                newS = S[pos] + newS; 
                count++;
                if (count == K)  { 
                    newS = '-' + newS;
                    count = 0;
                }
            }
            pos--;            
        }
        
        pos = 0;
        while (newS[pos] == '-') pos++;
        newS = newS.substr(pos);
        for (auto &c : newS) c = toupper(c);
        
        return newS;
    }
};