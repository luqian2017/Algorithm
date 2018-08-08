class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    vector<string> stringPermutation2(string &str) {
        vector<string> results;
        string sol;

        if (str.empty()) {
            results.push_back("");
            return results;
        }
        int strSize = str.size();

        vector<char> inputStr(strSize);
        for (int i = 0; i < strSize; ++i) {
            inputStr[i] = str[i];
        }
        sort(inputStr.begin(), inputStr.end());

        vector<bool> visited(strSize, false);        
        helper(inputStr, 0, visited, sol, results);
        return results;
    }

    void helper(vector<char> &str, int index, vector<bool> &visited, string &sol, vector<string> &results) {
        int strSize = str.size();
        if (sol.size() == strSize) {
            results.push_back(sol);
            return;
        }

        for (int i = 0; i < strSize; ++i) {
            if (visited[i]) continue;
            if ((i > 0) && (str[i] == str[i - 1]) && !visited[i-1]) continue;

            sol.push_back(str[i]);
            visited[i] = true;
            helper(str, index + 1, visited, sol, results);
            visited[i] = false;
            sol.pop_back();
        }
    }    
};