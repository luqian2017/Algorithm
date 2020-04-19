class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return {{}};
        vector<vector<int>> result;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        helper(nums, 0, result, sol);
        return result;
    }

private:
    void helper(vector<int> & nums, int pos, vector<vector<int>> &result, vector<int> & sol) {
        if (pos == nums.size()) {
            result.push_back(sol);
            return;
        }
        
        sol.push_back(nums[pos]);
        helper(nums, pos + 1, result, sol);
        sol.pop_back();
        helper(nums, pos + 1, result, sol);
        
        return;
    }
};