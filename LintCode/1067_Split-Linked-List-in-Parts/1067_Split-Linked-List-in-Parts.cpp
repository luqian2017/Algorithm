class Solution {
public:
    /**
     * @param root: the list
     * @param k: the split sum
     * @return: the answer
     */
    vector<vector<int>> splitLinkedListinParts(vector<int> &root, int k) {
        int len = root.size();
        if (len == 0 || k == 0) return {{}};
        vector<vector<int>> result(k, vector<int>());
        
        if (len <= k) {
            for (int i = 0; i < len; ++i) {
                result[i].push_back(root[i]);
            }
        } else {
            int avgLen = len / k;
            int remainder = len % k;
            for (int i = 0; i < remainder; ++i) {
                for (int j = 0; j < avgLen + 1; ++j) {
                    result[i].push_back(root[i * (avgLen + 1) + j]);
                }
            }
            int pos = remainder * (avgLen + 1);
            for (int i = remainder; i < k; ++i) {
                for (int j = 0; j < avgLen; ++j) {
                    result[i].push_back(root[pos + (i - remainder) * avgLen + j]);
                }
            }
        }
        
        return result;
    }
};