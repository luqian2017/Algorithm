class Solution {
public:
    /**
     * @param nums: the array of integers
     * @param target: 
     * @return: the starting and ending position
     */
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        if (n == 0) return {-1, -1};
        
        int start = 0, end = n - 1;
        int firstPos = 0, endPos = 0;
        //find first position of target
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid;
            } else { // if (nums[mid] < target) {
                start = mid;
            } 
        }
        
        if (nums[start] == target) firstPos = start;
        else if (nums[end] == target) firstPos = end;
        else return {-1, -1};
        
        start = 0, end = n - 1;
        //find last position of target
        while(start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            } else {
                end = mid;
            } 
        }

        if (nums[end] == target) endPos = end;
        else if (nums[start] == target) endPos = start;
        else return {-1, -1};
        
        return {firstPos, endPos};
    }
};