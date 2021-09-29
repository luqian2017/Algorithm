class Solution {
public:
    /**
     * @param nums: a integer array
     * @return: return an integer denoting the number of non-unique(duplicate) values
     */
    vector<int> countduplicates(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = 1;
            } else {
                if (um[nums[i]] == 1) res.push_back(nums[i]);
                um[nums[i]]++;
            }
        }
        return res;
    }
};