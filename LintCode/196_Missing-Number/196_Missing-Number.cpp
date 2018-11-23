class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An integer
     */
    int findMissing(vector<int> &nums) {
        int result = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; ++i) {
            result ^= i;
            result ^= nums[i];
        }
        
        result ^= len;
        
        return result;
        
    }
};