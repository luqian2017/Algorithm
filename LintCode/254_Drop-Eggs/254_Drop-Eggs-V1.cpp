class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        if (n <= 2) return n;
        return ceil((-1 + sqrt((long long)n * 8 + 1)) / 2);
    }
};
