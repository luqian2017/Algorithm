class Solution {
public:
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if (n == 0 || k == 0) return 0;
        int same = 0, diff = k;
        for (int i = 2; i <= n; ++i) {
            int temp = diff;
            diff = (same + diff) * (k - 1);
            same = temp;
        }
 
        return same + diff;
    }
};