class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
    int numSquares(int n) {
        vector<int> DP(n + 1, 0);
        DP[1] = 1;
        DP[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            int minNum = INT_MAX;
            
            if (isSquareNum(i)) {
                DP[i] = 1; 
                continue;
            }
            
            for (int j = 1; j < i; ++j) {
                if ((DP[j] + DP[i - j]) < minNum) {
                    minNum = DP[j] + DP[i - j];
                }
            }
            DP[i] = minNum;
        }
        
        return DP[n];
    }
    
private:
    bool isSquareNum(int n) {
        int m = floor(sqrt(n) + 0.5);
        if(m * m == n)
            return true;
        return false;
    }

};