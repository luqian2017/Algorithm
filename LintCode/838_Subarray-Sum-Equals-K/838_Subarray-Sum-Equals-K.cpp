class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> hashmap;  //preSum, freq
        hashmap[0] = 1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i]; 
            count += hashmap[sum - k];   
            hashmap[sum]++;
        }
        return count;
    }
};