class Solution {
public:
    /**
     * @param strs: the given array of strings
     * @return: The anagrams which have been divided into groups
     */
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int n = strs.size();
        vector<vector<string>> result;
        if (n == 0) return {{}};
        

        map<vector<int>, vector<string>> mp;   
        //map<map<char, int>, vector<string>> mp;
        
        for (int i = 0; i < n; ++i) {
            vector<int> dict(26, 0);
          //  map<char, int> dict;
            int m = strs[i].size();
            for (int j = 0; j < m; ++j) {
                dict[strs[i][j] - 'a']++;
            }
            mp[dict].push_back(strs[i]);
        }
        
        for (auto m : mp) {
            result.push_back(m.second);
        }
        
        return result;
    }
};