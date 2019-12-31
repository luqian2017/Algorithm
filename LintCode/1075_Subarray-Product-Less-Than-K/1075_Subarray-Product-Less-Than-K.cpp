class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the number of subarrays where the product of all the elements in the subarray is less than k
     */
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        
        long long product = 1;
        
        for (int i = 0; i < n; ++i) {
            helper(nums, i, k);
        }
        
        return count;
    }

private:
    int count = 0;
    void helper(vector<int> & nums, int index, int k) {
        long long product = 1;
        for (int i = index; i >= 0; i--) {
            if (nums[i] > k) break;
            product *= nums[i];
            if (product < k) {
                count++;
            } else {
                break;
            }
        }
    }
};