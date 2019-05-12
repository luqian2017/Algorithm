class Solution {
public:
    /**
     * @param words: a list of string
     * @return: a boolean
     */
    bool validWordSquare(vector<string> &words) {
        int m = words.size();
        if (m == 0) return true;
        
        int n = 0;
        for (int i = 0; i < m; ++i) {
            n = max(n, (int)words[i].size());
        }
        
        int i = 0, j = 0;
        
        for (i = 0; i < n; ++i) {
            string columString;
            for (j = 0; j < m; ++j) {
                if (words[j].size() >= i) columString += words[j][i];
            }
            if (columString != words[i]) return false;  
        }
        
        return true;
    }
};