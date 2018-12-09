class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: all unique substring
     */
    vector<string> uniqueSubstring(string &s, int k) {
        int len = s.size();
        set<string> ss;
        int upperBound = len - k;
        for(int i = 0; i <= upperBound; ++i) {
            string substr = s.substr(i, k);
            ss.insert(substr);
        }
        
        vector<string> result(ss.begin(), ss.end());
        
        return result;
    }
};