class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        string sol = "";
        vector<string> sols;
        dfs(n, 0, 0, sols, sol);
        return sols;
    }
    
private:
    void dfs(int n, int left, int right, vector<string> & sols, string sol) {
        if (left == n && right == n) {
            sols.push_back(sol);
            return;
        }

        if (left == n) {
            sol += string(n - right, ')');
            sols.push_back(sol);
            return;
        } else if (left > right) {
            dfs(n, left + 1, right, sols, sol + '(');
            dfs(n, left, right + 1, sols, sol + ')');
        } else if (left == right) {
            dfs(n, left + 1, right, sols, sol + '(');     
        }
    } 
};