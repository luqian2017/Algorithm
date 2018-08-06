class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> results;
        vector<int> sol;
        vector<bool> visited(nums.size(), false);
        if (nums.empty()) {
            results.push_back(vector<int>());
            return results;
        }
        sort(nums.begin(), nums.end());
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

            if (i > 0 && (nums[i] == nums[i-1]) && !visited[i - 1]) continue;

            visited[i] = true;
            sol.push_back(nums[i]);
            helper(nums, visited, sol, results);
            visited[i] = false;
            sol.pop_back();
        }
    }
};