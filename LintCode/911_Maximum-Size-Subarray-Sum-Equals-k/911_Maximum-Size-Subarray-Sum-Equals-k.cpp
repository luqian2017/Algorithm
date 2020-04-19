class Solution {
public:
    /**
     * @param nums: an array
     * @param k: a target value
     * @return: the maximum length of a subarray that sums to k
     */
    int maxSubArrayLen(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> presums(n);
        int maxLen = 0;
        
        presums[0] = nums[0];
        if (nums[0] == k) maxLen = 1;
        for (int i = 1; i < n; ++i) {
            presums[i] = presums[i - 1] + nums[i];
            if (nums[i] == k) maxLen = max(maxLen, 1);
            if (presums[i] == k) maxLen = max(maxLen, i + 1);
        }
        unordered_map<int, int> hashMap; //value, index
        for (int i = 0; i < n; ++i) {
            int temp = presums[i] - k;
            if (hashMap.find(temp) != hashMap.end()) {
                maxLen = max(maxLen, i - hashMap[temp]);
            }
            if (hashMap.find(presums[i]) == hashMap.end()) hashMap[presums[i]] = i;
        }

        return maxLen;
    }
};