class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> results;
        vector<int> sol;

        if (candidates.empty()) {
            results.push_back(vector<int>());
            return results;
        }

        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, sol, results);
        return results;
    }

    void helper(vector<int> &candidates, int target, int index, vector<int> &sol, vector<vector<int>> &results) {
        if (target == 0) {
            results.push_back(sol);
            return;
        }

        if (index == candidates.size()) return;
        if (target < candidates[index]) return; //剪枝

        for (int i = index; i < candidates.size(); ++i) {
            sol.push_back(candidates[i]);
            if (target >= candidates[i]) {
                helper(candidates, target - candidates[i], i, sol, results);
            } else {
                helper(candidates, target - candidates[i], i + 1, sol, results);
            }
            sol.pop_back();
        }
    }    

};