class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        catalanNums.resize(n + 1, vector<int>(n + 1, -1));
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n - i; ++j) {
                if (catalanNums[i][j] < 0) {
                    catalanNums[i][j] = catalan(i, j);
                }
            }
        }

        return catalan(n, 0);
    }
 
private:
   int catalan(int outside, int inside) {
       if (catalanNums[outside][inside] >= 0) return catalanNums[outside][inside];
       
       if (outside == 0) return 1; //stack full
       if (inside == 0) return catalan(outside - 1, 1);  //stack empty
        
       return catalan(outside - 1, inside + 1) + catalan(outside, inside - 1);
   }
   
   vector<vector<int>> catalanNums;
};