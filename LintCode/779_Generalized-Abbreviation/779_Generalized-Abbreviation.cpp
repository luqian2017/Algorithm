class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result{word};
        helper(word, 0, result);
        return result;
    }

private:
    void helper(string word, int pos, vector<string> &res) {
        int n = word.size();
        for (int i = pos; i < n; ++i) {
            for (int j = 1; i + j <= n; ++j) {
                string tmpStr = word.substr(0, i); //beginning part
                tmpStr += to_string(j) + word.substr(i + j);
                res.push_back(tmpStr);
                helper(tmpStr, i + 1 + to_string(j).size(), res);
            }
        }
    }
};