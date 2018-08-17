class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string &s) {
        vector<vector<string> > results;
        if (s.empty()) {
            results.push_back(vector<string>());
            return results;
        }
        vector<string> sol;
        helper(s, 0, sol, results);
        return results;
    }

    bool isPalidrome(string &s) {
        int len = s.size();

        if (len < 2) return true;

        int i = 0, j = len - 1;

        while (i < j) {
            if (s[i] != s[j]) 
                return false;
            i++; j--;
        }

        return true;
    }

    void helper(string &s, int index, vector<string> &sol, vector<vector<string>> & results) {
        int len = s.size();
        if (index >= len) {
            results.push_back(sol);
            return;
        }

        for (int i = index; i < len; ++i) {
            string str = s.substr(index, i - index + 1);
            if (isPalidrome(str)) {
                sol.push_back(str);
                helper(s, i + 1, sol, results);
                sol.pop_back();
            }
        }
    }
};