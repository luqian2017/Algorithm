class Solution {
public:
    /**
     * @param nums: a integer array
     * @param target: 
     * @return: return a integer
     */
    int KDifference(vector<int> &nums, int target) {
        int count = 0;
        int len = nums.size();
        int start = 0, end = 1;

        sort(nums.begin(), nums.end());

        while(end < len) {
            int diff = nums[end] - nums[start];
            if (diff == target) {
                count++;
                end++;
            } else if (diff < target) {
                end++;
            } else {
                start++;
            }
        }
        
        return count;
    }
};