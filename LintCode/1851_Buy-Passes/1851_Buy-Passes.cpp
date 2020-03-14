class Solution {
public:
    /**
     * @param arr: the line 
     * @param k: Alex place
     * @return: the time when Alex requires to buy all passes
     */
    int buyPasses(vector<int> &arr, int k) {
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= arr[k]) {
                if (i > k) total += arr[k] - 1;
                else total += arr[k];
            }
            else total += arr[i];
        }
        return total;
    }
};