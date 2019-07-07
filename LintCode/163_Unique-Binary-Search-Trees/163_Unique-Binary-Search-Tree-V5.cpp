class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    int numTrees(int n) {
        dp.resize(n + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= n; ++i) 
            for (int j = 0; j <=n; ++j) {
                if (i >= j) dp[i][j] = 1;   
            }
        return helper(1, n);
    }

private:
    int helper(int begin, int end) {
        if (begin >= end) return 1; //NULL is one solution
        int count = 0, leftCount = 0, rightCount = 0;
        for (int i = begin; i <= end; ++i) {
            leftCount = dp[begin][i - 1] < 0 ? helper(begin, i - 1) : dp[begin][i - 1]; //leftTree
            if (i < end) {
                rightCount = dp[i + 1][end] < 0 ? helper(i + 1, end) : dp[i + 1][end]; //rightTree
            } else {
                rightCount = 1;
            }
            count += leftCount * rightCount;
        }
        dp[begin][end] = count;
        return count;
    }
    
    vector<vector<int>> dp;
};
