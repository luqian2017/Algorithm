class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the product of all the elements of nums except nums[i].
     */
    vector<int> productExceptSelf(vector<int> &nums) {
        
        int len = nums.size();
        
        if (len == 0) return vector<int>();
        if (len == 1) return nums;
        
        vector<int> result(len, 0);
        vector<int> forward(len, 0);
        vector<int> backward(len, 0);
        
        forward[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            forward[i] = forward[i - 1] * nums[i];
        }

        backward[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; --i) {
            backward[i] = backward[i + 1] * nums[i];
        }
        
        for (int i = 1; i < len - 1; ++i) {
            result[i] = forward[i - 1] * backward[i + 1];
        }
        result[0] = backward[1];
        result[len - 1] = forward[len - 2];
        
        return result;
    }
};