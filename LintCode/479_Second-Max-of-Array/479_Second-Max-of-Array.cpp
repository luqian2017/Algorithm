class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The second max number in the array.
     */
    int secondMax(vector<int> &nums) {
        int max = INT_MIN;
        int secMax = INT_MIN;
        
        int len = nums.size();
        
        for (int i = 0; i < len; ++i) {
            if (max <= nums[i]) {
                secMax = max;
                max = nums[i];
            } else if (secMax <= nums[i]) {
                secMax = nums[i];
            }
        }
        
        return secMax;
    }
};