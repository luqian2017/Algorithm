class Solution {
public:
    /**
     * @param nums:  a sorted integer array without duplicates
     * @return: the summary of its ranges
     */
    vector<string> summaryRanges(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return {};
        vector<string> result;
        int pos = 0;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && nums[i + 1] > nums[i] + 1) {
                if (i == pos) 
                    result.push_back(to_string(nums[i]));
                else
                    result.push_back(to_string(nums[pos]) + "->" + to_string(nums[i]));
                pos = i + 1;    
            }
        }
        if (pos == n - 1)
            result.push_back(to_string(nums[pos]));
        else
            result.push_back(to_string(nums[pos]) + "->" + to_string(nums[n - 1]));
        
        return result;
    }
};