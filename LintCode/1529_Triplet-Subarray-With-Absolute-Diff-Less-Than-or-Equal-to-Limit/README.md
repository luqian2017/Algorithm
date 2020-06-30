class Solution {
public:
    /**
     * @param nums: the given array
     * @param limit: the limit on the absolute difference of the subarray
     * @return: Find the number of triplet subarray with the absolute difference less than or equal to limit
     */
    int tripletSubarray(vector<int> &nums, int limit) {
        int len = nums.size();
        long long count = 0;
        int p1 = 0, p2 = 0;
        
        for (int p2 = 2; p2 < len; ++p2) {
            while(nums[p2] - nums[p1] > limit) {
                p1++;
            }
            count += ((p2 - p1) * (p2 - p1 - 1) / 2) % 99997867;
        }
        return count;
    }
};