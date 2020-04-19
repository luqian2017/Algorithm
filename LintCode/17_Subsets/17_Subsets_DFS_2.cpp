class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int> > results;
        vector<int> sol;
        
        if (nums.empty()) {
          results.push_back(vector<int>());
          return results;
        }
        
        sort(nums.begin(), nums.end());

        helper(nums, 0, sol, results);
        return results;
    }
    
    void helper(vector<int> &nums, int index, vector<int>&sol, vector<vector<int>> &results) {
        
        results.push_back(sol);
        for (int i=index; i<nums.size(); ++i) {
            sol.push_back(nums[i]);
            helper(nums, i+1, sol, results);
            sol.pop_back();
        }
    }

};