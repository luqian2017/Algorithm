class Solution {
public:
    /*
     * @param n: The number of queens
     * @return: All distinct solutions
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> sol;
        if (n == 0) {
            results.push_back(vector<string>());
            return results;
        }

        helper(n, 0, sol, results);
        return results;
    }

private:
    bool isValid(vector<int> &sol, int col) {
        int row = sol.size();
        for (int rowId = 0; rowId < sol.size(); ++rowId) {
            if (sol[rowId] == col) 
                return false;
            if (sol[rowId] + rowId == col + row)
                return false;
            if (sol[rowId] - rowId == col - row)
                return false;
        }
        return true;
    }

    void helper(int n, int index, vector<int>&sol, vector<vector<string>> &results) {
        if (index == n) {
            string dotStr(n, '.');
            vector<string> solString(n, dotStr);   //good string initialization code!
            for (auto i : sol) {
                solString[i][sol[i]] = 'Q';
            }
            results.push_back(solString);
            return;
        }

        for (int i = 0; i < n; ++i) {

            if (isValid(sol, i)) {
                sol.push_back(i);
                helper(n, index + 1, sol, results);
                sol.pop_back();
            }

        }
    }

};
