class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        int n = strs.size();
        if (n == 0) return {};
        map<vector<int>, vector<string>> mp;
        vector<string> res;
        int empty_str_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (strs[i] == "") {
                empty_str_cnt++;
                continue;
            }
            vector<int> freqs(26, 0);
            for (int j = 0; j < strs[i].size(); ++j) {
                freqs[strs[i][j] - 'a']++;
            }
            mp[freqs].push_back(strs[i]);
        }
        
        for (int i = 0; i < empty_str_cnt; i++) {
            res.push_back(""); 
        }
        
        for (auto m : mp) {
            if (m.second.size() > 1) {
                for (auto s : m.second) {
                    res.push_back(s);
                }
            }
        }

        return res;
    }
};