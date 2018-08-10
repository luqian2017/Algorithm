class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> sol;
        
        if ((n < k) || (k == 0)) {
            results.push_back(vector<int>());
            return results;
        }
        
        helper(n, k, 1, sol, results);
        return results;
    }

    void helper(int n, int k, int index, vector<int> &sol, vector<vector<int>> &results) {
        if (sol.size() == k) {
            results.push_back(sol);
            return;
        }

        if (index == n + 1) return;
        
        for (int i = index; i <= n; ++i) {
            sol.push_back(i);
            helper(n, k, i + 1, sol, results);
            sol.pop_back();
        }
    }    
};