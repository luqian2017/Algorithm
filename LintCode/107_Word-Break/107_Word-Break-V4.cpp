class Solution {
public:
    /**
     * @param s: A string
     * @param wordSet: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &wordSet) {
        vector<int> used(s.size(), -1); //-1: initialized, 0: not OK, 1: OK
        return helper(s, 0, wordSet, used);
    }
private:
    bool helper(string s, int start, unordered_set<string> &wordSet, vector<int> &used) {
        if (start == s.size()) return true;
        if (used[start] == 1) return true;
        if (used[start] == 0) return false;
        for (int i = start; i < s.size(); ++i) {
            string seg = s.substr(start, i - start + 1);
            if (wordSet.find(seg) != wordSet.end()) {
                if (helper(s, i + 1, wordSet, used)) {
                    used[start] = 1;
                    return true;
                }
            }
        }
        used[start] = 0;
        return false;
    }
};