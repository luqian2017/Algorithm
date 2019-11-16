class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        if (n == 0) {
            if (lower == upper) return vector<string>{to_string(lower)};
            return vector<string>{to_string(lower) + "->" + to_string(upper)};
        }
        
        int p = lower;
        vector<string> result;
        string gap;
        long long num = lower;
        if (num < nums[0]) {
            if (num == (long long)(nums[0]) - 1) {
                result.push_back(to_string(num));
            } else {
                result.push_back(to_string(num) + "->" + to_string((long long)(nums[0]) - 1));
            }
            if (n == 1) return result;
        }
        num = nums[0];
        for (int i = 1; i < n; ++i) {
            if (num < (long long)(nums[i]) - 1) {
                if (nums[i] - num == 2) {
                    result.push_back(to_string(num + 1));
                } else {
                    result.push_back(to_string(num + 1) + "->" + to_string((long long)(nums[i]) - 1));  
                }
            }
            num = nums[i];
        }
        
        if (upper > nums[n - 1]) {
            if (upper - nums[n - 1] == 1) {
                result.push_back(to_string(upper));
            } else {
                result.push_back(to_string((long long)(nums[n - 1]) + 1) + "->" + to_string(upper));
            }
        }
        
        return result;
    }
};