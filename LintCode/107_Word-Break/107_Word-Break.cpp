class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        int lenS = s.size();
        int lenD = dict.size();
        maxWordLen = 0;
        minWordLen = lenS;
        
        for (auto w : dict) {
            maxWordLen = max(maxWordLen, (int)w.size());
            minWordLen = min(minWordLen, (int)w.size());
        }
        
        vector<string> sol;
        vector<vector<string>> result;
        
        helper(s, 0, dict, sol, result);
        if (result.size() > 0) return true;
        return false;
    }
    
private:

    void helper(string &s, int index, unordered_set<string> &dict, vector<string> &sol, vector<vector<string>> &result) {
        
        int len = s.size();
        if (index == len) {
            result.push_back(sol);
            return;
        }
        
        if (index + minWordLen > len) 
            return;
        
        for (int i = minWordLen; i <= maxWordLen; ++i) {
            string w = s.substr(index, i);
            if (dict.find(w) == dict.end()) continue;
            sol.push_back(w);
            helper(s, index + i, dict, sol, result);
            sol.pop_back();
        }
    }
    
    int minWordLen;
    int maxWordLen;
};