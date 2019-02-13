class Solution {
public:
    /**
     * @param nums: an array containing n + 1 integers which is between 1 and n
     * @return: the duplicate one
     */
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int start = 1, mid = 0, end = len - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (calCount(nums, mid) > mid) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (calCount(nums, start) > start) return start;
        return end;      
    }

private:
    int calCount(vector<int> &nums, int n) {
        int count = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (nums[i] <= n) count++;   //it should be <= here! not <
        }
        return count;
    }
};