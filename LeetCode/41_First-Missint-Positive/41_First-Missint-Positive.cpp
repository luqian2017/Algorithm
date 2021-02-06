class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        for (auto & it : nums) {
            if (it <= 0) it = n + 1;
        }
        for (auto & it : nums) {
            int abs_it = abs(it);
            if (abs_it <= n) nums[abs_it - 1] = -abs(nums[abs_it - 1]);
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};