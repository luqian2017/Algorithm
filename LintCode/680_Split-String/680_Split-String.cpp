class Solution {
public:
    /*
     * @param : a string to be split
     * @return: all possible split string array
     */
    vector<vector<string>> splitString(string& s) {
        vector<vector<string> > results;
        if (s.empty()) {
            results.push_back(vector<string>());
            return results;
        }
        
        vector<string> sol;
        helper(s, 0, sol, results);
        return results;
    }

private:
    void helper(string&s, int index, vector<string> &sol, vector<vector<string>> &results) {
        if (index >= s.size()) {
            results.push_back(sol);
            return;
        }
        
        if (index < s.size()) {
            sol.push_back(s.substr(index, 1));
            helper(s, index + 1, sol, results);
            sol.pop_back();
        }
        
        if (index < s.size() - 1) {
            sol.push_back(s.substr(index, 2));
            helper(s, index + 2, sol, results);
            sol.pop_back();
        }
    }
};