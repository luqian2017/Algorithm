class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if (s.size() == 0 && dict.size() == 0) return true;
        unordered_map<string, bool> memo;
        return helper(s, dict, memo);
    }
    
private:
    bool helper(string &s, unordered_set<string> &dict, unordered_map<string, bool> & memo) {
        if (s.size() == 0) return false;
        if (memo.find(s) != memo.end()) return memo[s];
        
        int len = s.size();
        for (int i = 1; i <= len; ++i) {
            string subStr1 = s.substr(0, i);
            
            if (dict.find(subStr1) != dict.end()) {
                if (subStr1 == s) {
                    memo[s] = true;
                    return true;
                }
                string subStr2 = s.substr(i);
                bool result = helper(subStr2, dict, memo);
                if (result) {
                    memo[s] = true;    
                    return true;
                }
            }
        }
        memo[s] = false;
        return false;
    }
   
};