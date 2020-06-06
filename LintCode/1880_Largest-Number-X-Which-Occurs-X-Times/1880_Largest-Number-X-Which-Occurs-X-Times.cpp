class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: return the biggest value X, which occurs in A exactly X times.
     */
    int findX(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        unordered_map<int, int> um;
        
        for (int i = 0; i < n; ++i) {
            if (um.find(arr[i]) == um.end()) {
                um[arr[i]] = 1;
            } else {
                um[arr[i]]++;
            }
        }
        
        int result = 0;
        for (auto it : um) {
            if (it.first == it.second) {
                result = max(result, it.first);
            }
        }
        
        return result;
    }
};