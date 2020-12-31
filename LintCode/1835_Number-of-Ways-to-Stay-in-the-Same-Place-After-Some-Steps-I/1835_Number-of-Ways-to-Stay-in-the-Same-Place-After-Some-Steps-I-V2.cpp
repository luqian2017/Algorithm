class Solution {
public:
    /**
     * @param steps: steps you can move
     * @param arrLen: the length of the array
     * @return: Number of Ways to Stay in the Same Place After Some Steps
     */
    int numWays(int steps, int arrLen) {
        mem.resize(steps + 1, vector<int>(arrLen, -1));
        return dfs(steps, arrLen, 0);
    }
private:
    vector<vector<int>> mem;
    int dfs(int steps, int arrLen, int pos) {
        if (pos < 0 || pos >= arrLen) return 0;
        if (mem[steps][pos] > 0) return mem[steps][pos];
        if (steps == 0 && pos == 0) {
            mem[0][0] = 1;
            return 1;
        }
        if (steps == 0 && pos != 0) {
            mem[0][pos] = 0;
            return 0;
        }
         
        mem[steps][pos] = dfs(steps - 1, arrLen, pos - 1) + 
               dfs(steps - 1, arrLen, pos + 1) +
               dfs(steps - 1, arrLen, pos);
        
        return mem[steps][pos];
    }
    
};