class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return;
        int p1 = 0, p2 = 0, p3 = n - 1;
        while(p2 <= p3) {
            if (nums[p2] == 0) {
                swap(nums[p1], nums[p2]);
                p1++; p2++;
            } else if (nums[p2] == 1) {
                p2++;
            } else {
                swap(nums[p2], nums[p3]);
                p3--;
            }
        }
    }
};