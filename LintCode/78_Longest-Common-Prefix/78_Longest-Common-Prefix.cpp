class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        int N = strs.size();
        if (N == 0) return "";
        
        unordered_map<string, vector<string>> hashmap;
        
        for (int i = 0; i < N; ++i) {
            int M = strs[i].size();
            
            for (int j = 0; j < M; ++j) {
                string pre = strs[i].substr(0, j + 1);
                hashmap[pre].push_back(strs[i]);
            }
        }
        
        string result;
        int maxLen = 0;
        
        for (auto h : hashmap) {
            if (h.second.size() == N) {
                if (h.first.size() > maxLen) {
                    maxLen = h.first.size();
                    result = h.first;
                }
            }
        }
        
        return result;
    }
};