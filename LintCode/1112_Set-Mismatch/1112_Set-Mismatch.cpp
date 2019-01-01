class Solution {
public:
    /**
     * @param nums: an array
     * @return: the number occurs twice and the number that is missing
     */
    vector<int> findErrorNums(vector<int> &nums) {
        int len = nums.size();
        if (len == 0) return vector<int>(2, 0);
        
        sort(nums.begin(), nums.end());
        int candidate_orig = 0, candidate_err = 0;
        for (int i = 1; i <= len; ++i) {
            if (nums[i - 1] == nums[i]) {
                candidate_err = nums[i];
                break;
            }
        }
        int xor_result = 0;
        for (int i = 1; i <= len; ++i) {
            xor_result ^= i;
            xor_result ^= nums[i - 1];
        }
        xor_result ^= candidate_err;
        
        candidate_orig = xor_result;
        
        return vector<int>{candidate_err, candidate_orig};
    }
};