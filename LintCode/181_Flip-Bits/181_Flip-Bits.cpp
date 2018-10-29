class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: An integer
     */
    int bitSwapRequired(int a, int b) {
        int c = a ^ b;
        int count = 0;
        while (c) {
            count++;
            c &= c - 1;
        }
        
        return count;
    }
};