class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: the number of subarrays where the product of all the elements in the subarray is less than k
     */
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0|| k == 0) return 0;
        
        long long product = 1;
        int count = 0;
        int left = 0, right = 0;
        while (right < n) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
};