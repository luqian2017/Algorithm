class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        int n = nums.size();
        if (n < k) return "NO";
        unordered_map<int, int> um; //num, latest_location
        int minLen = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (um.find(nums[i]) == um.end()) {
                um[nums[i]] = i;
            } else {
                minLen = min(minLen, i - um[nums[i]]);
            }
        }

        if (minLen < k) return "YES";
        return "NO";
    }
};