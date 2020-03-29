class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        int n = s.size();
        int m = dict.size();
        if (m == 0 && n == 0) return true;
        if (m == 0 || n == 0) return false;

        //memo[i] means if s[i..n] can be found in dict
        vector<int> memo(n, -1);  //-1 : init, 0 : false, 1 : true
        return helper(s, dict, 0, memo);
    }
    
private:
    bool helper(string &s, unordered_set<string> &dict, int index, vector<int> & memo) {
        if (index == s.size()) {
            return true;
        }
        
        if (memo[index] != -1) return memo[index];
        
        for (int i = index + 1; i <= s.size(); ++i) {
            string string1 = s.substr(index, i - index);
            if (dict.find(string1) != dict.end() && helper(s, dict, i, memo)) {
                memo[index] = 1;
                return true;
            } 
        }
        
        memo[index] = 0;
        return false;
    }
   
};