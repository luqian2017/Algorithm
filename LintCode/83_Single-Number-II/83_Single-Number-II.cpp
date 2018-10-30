class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        
        int ONES = 0, TWOS = 0;
        
        for (auto i : A) {
            ONES = (ONES ^ i) & (~TWOS);
            TWOS = (TWOS ^ i) & (~ONES);
        }
        
        return ONES;
    }
};