class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumber(vector<int> &A) {
        int result = 0;
        for (auto i : A) {
            result ^= i;
        }
        return result;
    }
};