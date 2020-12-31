class Solution {
public:
    /**
     * @param steps: steps you can move
     * @param arrLen: the length of the array
     * @return: Number of Ways to Stay in the Same Place After Some Steps
     */
    int numWays(int steps, int arrLen) {
        return dfs(steps, arrLen, 0);
    }
private:
    int dfs(int steps, int arrLen, int pos) {
        if (steps == 0 && pos == 0) return 1;
        if (steps == 0 && pos != 0) return 0;

        if (pos < 0 || pos >= arrLen) return 0;
        
        return dfs(steps - 1, arrLen, pos - 1) + 
               dfs(steps - 1, arrLen, pos + 1) +
               dfs(steps - 1, arrLen, pos);
    }
    
};