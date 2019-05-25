class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        
        int start = 0, end = n - 1;
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            } else if (nums[mid] >= target) {
                end = mid;
            }
        }
        
        if (nums[start] == target) return start;
        if (nums[end] == target) return end;
        return -1;
    }
};