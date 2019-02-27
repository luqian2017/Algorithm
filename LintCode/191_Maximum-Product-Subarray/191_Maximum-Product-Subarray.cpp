class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        vector<int> dpMax(len, 0);
        vector<int> dpMin(len, 0);
        int result = nums[0];
        
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        
        for (int i = 1; i < len; ++i) {
            if (nums[i] > 0) {
                dpMax[i] = max(dpMax[i - 1] * nums[i], nums[i]);
                dpMin[i] = min(dpMin[i - 1] * nums[i], nums[i]);
            } else if (nums[i] < 0) {
                dpMax[i] = max(dpMin[i - 1] * nums[i], nums[i]);
                dpMin[i] = min(dpMax[i - 1] * nums[i], nums[i]);
            }
            result = max(result, dpMax[i]);
        }
        return result;
    }
};