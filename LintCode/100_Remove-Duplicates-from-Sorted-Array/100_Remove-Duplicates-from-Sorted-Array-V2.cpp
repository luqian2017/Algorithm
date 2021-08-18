class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int start = 0, end = 1;
        while (end < n) {
            while (end < n && nums[end] == nums[start]) end++;
            if (end < n) {
                start++;
                nums[start] = nums[end];
                end++;
            }
        }
        return start + 1;
    }
};