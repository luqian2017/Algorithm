class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0];
        
        int start = 0, end = n - 1;
        if (nums[end] > nums[start]) return nums[start];  //no wrapping
        
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) return nums[mid];
            if (nums[start] < nums[mid]) start = mid;
            if (nums[start] > nums[mid]) end = mid;
        }
        
        if (nums[start] < nums[end]) return nums[start];
        return nums[end];
    }
};