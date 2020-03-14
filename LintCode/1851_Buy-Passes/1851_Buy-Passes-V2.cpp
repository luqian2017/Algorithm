class Solution {
public:
    /**
     * @param arr: the line 
     * @param k: Alex place
     * @return: the time when Alex requires to buy all passes
     */
    int buyPasses(vector<int> &arr, int k) {
        if (arr[k] == 1) return k + 1;
        int n = arr.size();
        int origK = k;
        
        int numPasses = arr[k];
        int totalWaitTime = 0;
        for (int i = 0; i < numPasses - 1; ++i) {
            totalWaitTime += n;
            for (int j = 0; j < arr.size(); ++j) {
                arr[j]--;    
                if (arr[j] == 0) {
                    n--;
                    if (j < origK) k--;
                }
            }
        }
        return totalWaitTime + k + 1;
    }
};