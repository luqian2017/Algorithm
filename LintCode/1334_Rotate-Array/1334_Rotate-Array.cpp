class Solution {
public:
    /**
     * @param nums: an array
     * @param k: an integer
     * @return: rotate the array to the right by k steps
     */
    vector<int> rotate(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> result;
        if (len <= 0) return result;
        if (k > len) k = k % len;
        reverse(nums.begin(), nums.begin() + len - k);
        reverse(nums.begin() + len - k, nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }
};