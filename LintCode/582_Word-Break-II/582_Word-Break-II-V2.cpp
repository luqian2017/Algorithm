class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) {
        map<string, vector<string>> memo;
        return helper(s, wordDict, memo);
    }

private:
    vector<string> helper(string &s, unordered_set<string> &wordDict, map<string, vector<string>> &memo) {
        int len = s.size();
        if (len == 0) return {};
        if (memo.find(s) != memo.end()) return memo[s];
        
        vector<string> result;
        for (int i = 1; i <= len; ++i) {
            string subStr1 = s.substr(0, i);
            if (wordDict.find(subStr1) != wordDict.end()) {
                if (subStr1.size() == len) {
                    result.push_back(subStr1);   
                } else {
                    string subStr2 = s.substr(i);
                    vector<string> tmpRes;
                    tmpRes = helper(subStr2, wordDict, memo);
                    //tmpRes = helper(subStr2, wordDict);
                    for (auto t : tmpRes) {
                        result.push_back(subStr1 + " " + t);
                    }
                }
            }
        }
        
        memo[s] = result;
        return result;
    }
};