class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int maxProduct(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return 0;
        
        int posMaxNew = 0, posMaxOld = 0, negMinNew = 0, negMinOld = 0;
        int result = nums[0];
        
        if (nums[0] > 0) {
            posMaxNew = nums[0];
        }

        if (nums[0] < 0) {
            negMinNew = nums[0];
        }
        
        for (int i = 1; i < len; ++i) {
            if (nums[i] > 0) {
                int posMax = posMaxNew > 0 ? posMaxNew * nums[i] : nums[i];
                int negMin = negMinNew < 0 ? negMinNew * nums[i] : 0;
                posMaxOld = posMaxNew;
                posMaxNew = posMax;
                negMinOld = negMinNew;
                negMinNew = negMin;
            } else if (nums[i] < 0) {
                int posMax = negMinNew < 0 ? negMinNew * nums[i] : 0;
                int negMin = posMaxNew > 0 ? posMaxNew * nums[i] : nums[i];
                posMaxOld = posMaxNew;
                posMaxNew = posMax;
                negMinOld = negMinNew;
                negMinNew = negMin;
            } else {
                posMaxNew = 0;
                negMinNew = 0;
            }
            result = max(result, posMaxNew);
        }
        return result;
    }
};