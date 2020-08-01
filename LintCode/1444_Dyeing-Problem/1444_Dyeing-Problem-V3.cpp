class Solution {
public:
    /**
     * @param n: the number of sectors
     * @param m: the number of colors
     * @return: The total number of plans.
     */
    int getCount(int n, int m) {
        int third = m;
        int first = (long) third * (m - 1) % 1000000007;
        int second = (long) first * (m - 2) % 1000000007;
        
      //  if (n == 1) return third;
        if (n == 2) return first;
        if (n == 3) return second;

        for (int i = 4; i <= n; ++i) {
            //if the first sector and the last sector are same color
            third = (long) first * (m - 1) % 1000000007;

            //if the first sector and the last sector are not same color
            third += (long) second * (m - 2) % 1000000007;
            third %= 1000000007;
            first = second;
            second = third;
        }
        
        return third;
    }
};