class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        map<int, string> hashmap = {{1,""}, {2,"abc"}, {3, "def"},
                                    {4, "ghi"}, {5, "jkl"}, {6, "mno"},
                                    {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string> results;
        if (digits.empty()) return results;

        string sol;

        helper(digits, hashmap, 0, sol, results);
        return results;
    }

    void helper(string &digits, map<int, string> &hashmap, int index, string &sol, vector<string> &results) {
        if (index == digits.size()) {
            results.push_back(sol);
            return;
        }

        int digit = digits[index] - '0';

        for (int i = 0; i < hashmap[digit].size(); ++i) {
            sol.push_back(hashmap[digit][i]);
            helper(digits, hashmap, index + 1, sol, results);
            sol.pop_back();
        }
    }
};
