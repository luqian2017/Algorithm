class Solution {
public:
    /**
     * @param sales: a integer array
     * @return: return a Integer
     */
    int BalancedSalesArray(vector<int> &sales) {
        int len = sales.size();
        vector<int> presums(len, 0);
        presums[0] = sales[0];
        for (int i = 1; i < len; ++i) {
            presums[i] = presums[i - 1] + sales[i];
        }
        
        for (int i = 1; i < len; ++i) {
            if (presums[i - 1] == presums[len - 1] - presums[i]) return i;
        }
        return -1;
    }
};