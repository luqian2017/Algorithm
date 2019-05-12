class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers
     */
    vector<int> nextPermutation(vector<int> &nums) {
        int n = nums.size();
        
        if (n <= 1) return nums;
        
        vector<int> result = nums;
        
        int index = 0;
        for (int i = n - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                index = i;
                break;
            }
        }
        
        if (index == 0) {
            reverse(result.begin(), result.end());
            return result;
        }
        
        for (int i = n - 1; i >= index; --i) {
            if (nums[i] > nums[index - 1]) {
                swap(result[i], result[index - 1]);
                reverse(result.begin() + index, result.end());
                return result;
            }
        }
    }
};