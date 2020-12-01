class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set us(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (us.find(nums[i] - 1) == us.end()) {
                int count = 0;
                int candidate = nums[i];
                while(us.find(candidate) != us.end()) {
                    count++;
                    candidate++;
                }
                res = max(res, count);
            }
        }

        return res;
    }
};