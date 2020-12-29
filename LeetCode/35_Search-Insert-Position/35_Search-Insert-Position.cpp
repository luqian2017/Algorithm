class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return 0;
        int res;
        int start = 0, end = len - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                return mid;
            }
        }
        if (nums[end] == target) return end;
        if (nums[end] < target) return end + 1;
        if (nums[start] < target) return start + 1;
        if (nums[start] == target) return start;
        return (start == 0) ? 0 : start - 1;
    }
};