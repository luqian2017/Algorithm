class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> results;
        vector<int> sol;
        vector<bool> visited(nums.size(), false);
        if (nums.empty()) {
            results.push_back(vector<int>());
            return results;
        }

        helper(nums, visited, sol, results);
        return results;
    }

    void helper(vector<int> &nums, vector<bool> &visited, vector<int> &sol, vector<vector<int>> &results) {
        if (sol.size() == nums.size()) {
            results.push_back(sol);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visited[i]) continue;

            visited[i] = true;
            sol.push_back(nums[i]);
            helper(nums, visited, sol, results);
            visited[i] = false;
            sol.pop_back();
        }
    }
};