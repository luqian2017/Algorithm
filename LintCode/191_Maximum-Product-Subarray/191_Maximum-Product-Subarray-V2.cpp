class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        vector<int> dpPosMax(len, 0);
        vector<int> dpNegMin(len, 0);
        int result = nums[0];
        
        if (nums[0] > 0) {
            dpPosMax[0] = nums[0];
            dpNegMin[0] = 0;
        }

        if (nums[0] < 0) {
            dpNegMin[0] = nums[0];
            dpPosMax[0] = 0;
        }
        
        for (int i = 1; i < len; ++i) {
            if (nums[i] > 0) {
                dpPosMax[i] = dpPosMax[i - 1] > 0 ? dpPosMax[i - 1] * nums[i] : nums[i];
                dpNegMin[i] = dpNegMin[i -1] < 0 ? dpNegMin[i - 1] * nums[i] : 0;
            } else if (nums[i] < 0) {
                dpPosMax[i] = dpNegMin[i - 1] < 0 ? dpNegMin[i - 1] * nums[i] : 0;
                dpNegMin[i] = dpPosMax[i - 1] > 0 ? dpPosMax[i - 1] * nums[i] : nums[i];
            }
            result = max(result, dpPosMax[i]);
        }
        return result;
    }
};