class Solution {
public:
    /**
     * @param nums: a binary array
     * @return: the maximum length of a contiguous subarray
     */
    int findMaxLength(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<int> presums(n, 0);
        int maxLen = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) nums[i] = -1;
        }
        presums[0] = nums[0]; 
        for (int i = 1; i < n; ++i) {
            presums[i] = presums[i - 1] + nums[i];
        }
        unordered_map<int, int> mp; //presum, latest_location
        for (int i = 0; i < n; ++i) {
            if (presums[i] == 0) maxLen = max(maxLen, i + 1);
            if (mp.find(presums[i]) != mp.end()) maxLen = max(maxLen, i - mp[presums[i]]);
            else mp[presums[i]] = i;
        }
   
        return maxLen;
    }
};