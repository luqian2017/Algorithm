class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        int len = L.size();
        if (len == 0) return 0;
        //int minLen = INT_MAX, maxLen = 0;
        int maxLen = 0;
        for (int i = 0; i < len; ++i) {
//            minLen = min(minLen, L[i]);
            maxLen = max(maxLen, L[i]);
        }
        
        int start = 1, end = maxLen;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (qualify(L, k, mid)) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (qualify(L, k, end)) return end;
        if (qualify(L, k, start)) return start;
        return 0;
    }
    
private:
    bool qualify(vector<int> &L, int k, int l) {
        int len = L.size();
        int count = 0;
        for (int i = 0; i < len; ++i) {
            count += L[i] / l;
        }
        return count >= k;
    } 
};