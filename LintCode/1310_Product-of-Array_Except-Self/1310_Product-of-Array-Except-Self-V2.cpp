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
        
        vector<int> result(len, 1);
        for (int i = 1; i < len; ++i) { 
             //note result[i] only records the forward product of i - 1
            result[i] = result[i - 1] * nums[i - 1];
        }

        int backwardProduct = 1;
        for (int i = len - 1; i >= 0; --i) {
            result[i] = result[i] * backwardProduct;
            backwardProduct *= nums[i];
        }
         
        return result;
    }
};