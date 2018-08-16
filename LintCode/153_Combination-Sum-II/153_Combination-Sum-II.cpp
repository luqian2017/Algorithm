class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<int> sol;
        vector<vector<int>> results;

        if (num.empty()) {
            if (target > 1)
                results.push_back(vector<int>());
            return results;
        }

        sort(num.begin(), num.end());
        helper(num, target, 0, sol, results);
        return results;
    }

private:
    void helper(vector<int> &num, int target, int index, vector<int> &sol, vector<vector<int>> &results) {
        int len = num.size();

        if (target == 0) {
            results.push_back(sol);
            return;
        }

        for (int i = index; i < len; ++i) {

            if (target < num[i]) return; //剪枝

            if (i != index && num[i] == num[i-1]) continue;  //去重！！！

            sol.push_back(num[i]);
            helper(num, target - num[i], i + 1, sol, results);
            sol.pop_back();
        }
    }
};